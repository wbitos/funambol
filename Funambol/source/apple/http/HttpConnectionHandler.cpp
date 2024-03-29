/*
 * Funambol is a mobile platform developed by Funambol, Inc. 
 * Copyright (C) 2010 Funambol, Inc.
 * 
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License version 3 as published by
 * the Free Software Foundation with the addition of the following permission 
 * added to Section 15 as permitted in Section 7(a): FOR ANY PART OF THE COVERED
 * WORK IN WHICH THE COPYRIGHT IS OWNED BY FUNAMBOL, FUNAMBOL DISCLAIMS THE 
 * WARRANTY OF NON INFRINGEMENT  OF THIRD PARTY RIGHTS.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Affero General Public License 
 * along with this program; if not, see http://www.gnu.org/licenses or write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA.
 * 
 * You can contact Funambol, Inc. headquarters at 643 Bair Island Road, Suite 
 * 305, Redwood City, CA 94063, USA, or at email address info@funambol.com.
 * 
 * The interactive user interfaces in modified source and object code versions
 * of this program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU Affero General Public License version 3.
 * 
 * In accordance with Section 7(b) of the GNU Affero General Public License
 * version 3, these Appropriate Legal Notices must retain the display of the
 * "Powered by Funambol" logo. If the display of the logo is not reasonably 
 * feasible for technical reasons, the Appropriate Legal Notices must display
 * the words "Powered by Funambol".
 */


#include <Funambol/base/fscapi.h>

#if FUN_TRANSPORT_AGENT == FUN_MAC_TRANSPORT_AGENT

#include <Foundation/Foundation.h>
#include <CoreFoundation/CoreFoundation.h>
#include <Funambol/http/HttpConnectionHandler.h>
#include <Funambol/http/constants.h>
#include <Funambol/base/util/utils.h>
#include <Funambol/base/util/KeyValuePair.h>
#include <Funambol/base/util/StringBuffer.h>
#include <Funambol/event/FireEvent.h>
#include <pthread.h>
#include <inttypes.h>

BEGIN_FUNAMBOL_NAMESPACE

// thread cleanup handler
static void stopReaderThread(void *arg);

// reader thread fuctions
static void* readerThread(void *arg);
static void* readerStreamThread(void *arg);

HttpConnectionHandler::HttpConnectionHandler() : readerThreadRunning(false), handle(NULL) {}

HttpConnectionHandler::~HttpConnectionHandler() 
{
    if (handle) {
        if (readerThreadRunning) {
            stopReaderThread((void *)handle);
        }
        delete handle;
    }
}

int HttpConnectionHandler::startConnectionHandler(CFReadStreamRef stream, int requestSize)
{
    int status = 0;
    int ret = E_SUCCESS; 
    void* thread_ret_val = 0;

    if (readerThreadRunning) {
        LOG.error("%s: reader thread already running", __FUNCTION__);
        
        return E_ALREADY_RUNNING;
    }

    readerThreadRunning = true;

    // set PTHREAD_CANCEL_DEFERRED to enable cleanup handlers
    // over pthread_cancel() calls
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    if (handle) {
        delete handle;
    }

    handle = new StreamDataHandle();

    handle->responseStream = stream;
    handle->stopStreamReading = false;
    handle->requestSize = requestSize;
            
    // set stopReaderThread as cleanup handler for pthread_cancel
    pthread_cleanup_push(stopReaderThread, (void *) handle);
            
    // create reader thread (this will open connection sending HTTP request
    // and will read the response).
    if ((status = pthread_create(&(handle->threadId), NULL, readerThread, (void *)handle)) != 0) {
        LOG.error("%s: error creating reader thread: %s", __FUNCTION__,
                            strerror(status));
        readerThreadRunning = false;
        delete handle;
        handle = NULL;
        
        ret = E_THREAD_CREATE;
        
        return ret;
    }

    // wait for completion of readerThread
    if ((status = pthread_join(handle->threadId, &thread_ret_val)) != 0) {
        readerThreadRunning = false;
        delete handle;
        handle = NULL;
        
        LOG.error("%s: error creating reader thread: %s", __FUNCTION__, strerror(status));
        
        ret = E_THREAD_JOIN;
        
        return ret;
    } 
      
    readerThreadRunning = false;

    ret = (int)(intptr_t)thread_ret_val;

    // remove thread cleanup handler
    pthread_cleanup_pop(0);

    return ret;    
}

int HttpConnectionHandler::startConnectionHandler(CFReadStreamRef stream, OutputStream& os, int chunkSize)
{
    int status = 0;
    int ret = E_SUCCESS; 
    void* thread_ret_val = 0;

    if (readerThreadRunning) {
        LOG.error("%s: reader thread already running", __FUNCTION__);
        
        return E_ALREADY_RUNNING;
    }

    readerThreadRunning = true;

    // set PTHREAD_CANCEL_DEFERRED to enable cleanup handlers
    // over pthread_cancel() calls
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    if (handle) {
        delete handle;
    }

    handle = new StreamDataHandle();

    handle->responseStream = stream;
    handle->stopStreamReading = false;
    handle->requestSize = chunkSize;
    handle->os = &os;
    handle->chunkSize = chunkSize;
            
    // set stopReaderThread as cleanup handler for pthread_cancel
    pthread_cleanup_push(stopReaderThread, (void *) handle);
            
    // create reader thread (this will open connection sending HTTP request
    // and will read the response).
    if ((status = pthread_create(&(handle->threadId), NULL, readerStreamThread, (void *)handle)) != 0) {
        LOG.error("%s: error creating reader thread: %s", __FUNCTION__,
                            strerror(status));
        readerThreadRunning = false;
        delete handle;
        handle = NULL;
        
        ret = E_THREAD_CREATE;
        
        return ret;
    }

    // wait for completion of readerThread
    if ((status = pthread_join(handle->threadId, &thread_ret_val)) != 0) {
        readerThreadRunning = false;
        delete handle;
        handle = NULL;
        
        LOG.error("%s: error creating reader thread: %s", __FUNCTION__, strerror(status));
        
        ret = E_THREAD_JOIN;
        
        return ret;
    } 
      
    readerThreadRunning = false;

    ret = (int)(intptr_t)thread_ret_val;

    // remove thread cleanup handler
    pthread_cleanup_pop(0);

    return ret;    
}


const char* HttpConnectionHandler::getRequestReponse() const
{
    const char* response = NULL;

    if (handle) {
        //response = handle->responseBuffer.c_str();
        response = handle->responseBuffer;
    }

    return response;
}

static void* watchThread(void *arg) {
    //printf("Thread start!");
    StreamDataHandle* streamHandle = (StreamDataHandle*)arg;
    int  a = streamHandle->readCount;
    int  oa = a;
    int count = 0;
    while (!streamHandle->needStop) {
        //LOG.debug("count :%d",count);
        //printf("count :%d\n",count);
        if (count > 1000) {
            //
            printf("reading response over time.\n");
            LOG.debug("reading response over time.");
            //stopReaderThread(streamHandle);
            fireSyncEvent("reading response over time.",SYNC_ERROR);
            break;
        }
        usleep(50000);
        if (oa == a) {
            count ++;
        }
        else {
            count = 0;
        }
        if (streamHandle) {
            a = streamHandle->readCount;
        }
    }
    //printf("Thread end!");
    return NULL;
}
/**
 * HTTP connection handler within a thread: open a connection 
 * sending HTTP request and read server response
 */ 
static void* readerThread(void *arg)
{
    StreamDataHandle* streamHandle = (StreamDataHandle *)arg;
    int read_size = 1024;
    int ret = E_SUCCESS; 
    UInt8   buffer[read_size];
    CFIndex bytesRead = 0;
    streamHandle->streamConnected = false;
    // open connection and send request
    if (!CFReadStreamOpen(streamHandle->responseStream)) {
        LOG.error("failed to send HTTP request...");
        ret = ERR_CONNECT;
        return (void *)(long)ret;
    }
   
    streamHandle->streamConnected = true;
    LOG.debug("HTTP request sent");
    
    // send notifications
    fireTransportEvent(streamHandle->requestSize, SEND_DATA_END);
    fireTransportEvent(0, RECEIVE_DATA_BEGIN);

    streamHandle->stopStreamReading = false;
    memset(buffer, 0, read_size);
    
    LOG.debug("reading data from server...");
    
    streamHandle->readCount = 0;
    streamHandle->needStop = false;
    streamHandle->responseBufferLen = 0;
    streamHandle->responseBufferSize = 0;
    streamHandle->responseBuffer = 0;
    
    //int status = pthread_create(&(streamHandle->watchThreadId), NULL, watchThread, streamHandle);
    //usleep(50000);
    // sleep(1); // need sleep? 
    // server reponse read loop
    while ((bytesRead = CFReadStreamRead(streamHandle->responseStream, buffer, read_size -1)) > 0) {
        pthread_testcancel();
        
        LOG.debug("readCount:%d buffersize:%d reading %d bytes.",streamHandle->readCount,read_size,bytesRead);
        streamHandle->readCount ++;
        if (streamHandle->stopStreamReading) {
            break;
        }
        //   Convert what was read to a C-string
        buffer[bytesRead] = 0;
        //   Append it to the reply string
        //streamHandle->responseBuffer.append((const char*)buffer,bytesRead);
        
        if (streamHandle->responseBufferLen + bytesRead > streamHandle->responseBufferSize) {
            streamHandle->responseBufferSize = (int)(streamHandle->responseBufferLen + bytesRead + 1);
            streamHandle->responseBuffer = (char*)realloc(streamHandle->responseBuffer,streamHandle->responseBufferSize);
        }
        memcpy(streamHandle->responseBuffer + streamHandle->responseBufferLen, buffer, bytesRead);
        streamHandle->responseBufferLen = (int)(streamHandle->responseBufferLen + bytesRead);
        
        memset(buffer, 0, read_size);
    }
    streamHandle->needStop = true;
    //usleep(150000);
    //status = pthread_kill(streamHandle->watchThreadId, SIGUSR1);
    //if (status != 0) {
    //    printf("...err killed   status = %d\n",status);
    //}
    
    LOG.debug("data read from server completed");
 
    return (void *)(long)ret;
}



static void* readerStreamThread(void *arg)
{
    StreamDataHandle* streamHandle = (StreamDataHandle *)arg;
    long ret = E_SUCCESS;
    int read_size = streamHandle->chunkSize; 
    UInt8   buffer[read_size];
    CFIndex bytesRead = 0;
  
    streamHandle->streamConnected = false;
    
    // open connection and send request
    if (!CFReadStreamOpen(streamHandle->responseStream)) {
        LOG.error("failed to send HTTP request...");
        ret = ERR_CONNECT;
        
        return (void *)(long)ret;
    }
   
    streamHandle->streamConnected = true;
    LOG.debug("HTTP request sent");
    
    // send notiifications
    fireTransportEvent(streamHandle->requestSize, SEND_DATA_END);
    fireTransportEvent(0, RECEIVE_DATA_BEGIN);

    streamHandle->stopStreamReading = false;
    memset(buffer, 0, read_size);
    
    LOG.debug("reading data from server...");
    
    streamHandle->readCount = 0;
    streamHandle->needStop = false;
    
    int status = pthread_create(&(streamHandle->watchThreadId), NULL, watchThread, streamHandle);
    if (status != 0) {
        printf("...");
    }
    // server reponse read loop
    while ((bytesRead = CFReadStreamRead(streamHandle->responseStream, buffer, read_size - 1)) > 0) {
        pthread_testcancel();
        
        LOG.debug("buffersize:%d reading %d bytes.",read_size,bytesRead);
        streamHandle->readCount ++;
        if (streamHandle->stopStreamReading) {
            break;
        }
        //   Convert what was read to a C-string
        buffer[bytesRead] = 0;
        streamHandle->os->write((const void*)buffer, (int)bytesRead);
        memset(buffer, 0, read_size);
    }
    streamHandle->needStop = true;
    
    status = pthread_kill(streamHandle->watchThreadId, SIGUSR1);
    if (status != 0) {
        printf("...err killed\n");
    }
    
    LOG.debug("Data read");
    return (void *)(long)ret;
}


/**
 * thread cleanup handler (called on cancellation request 
 * sent to main thread): tries to stop the reader loop
 * and finally sends to thread SIGUSR1 signal (this is 
 * needed to avoid to be blocked on CFReadStreamOpen)
 */ 
void stopReaderThread(void *arg)
{
    StreamDataHandle* streamHandle = (StreamDataHandle *)arg;
    
    if (streamHandle->streamConnected) {
        streamHandle->stopStreamReading = true;
    }
    
    CFReadStreamClose(streamHandle->responseStream); 
    CFRelease(streamHandle->responseStream); 
    
    LOG.debug("%s: killing reader thread", __FUNCTION__);
    pthread_kill(streamHandle->threadId, SIGUSR1);
}

END_FUNAMBOL_NAMESPACE

#endif