/*
 * Funambol is a mobile platform developed by Funambol, Inc. 
 * Copyright (C) 2003 - 2007 Funambol, Inc.
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

#ifndef INCL_CUSTOM_TRANSPORT_AGENT
#define INCL_CUSTOM_TRANSPORT_AGENT
/** @cond DEV */

#include <Funambol/base/fscapi.h>

#if defined(FUN_IPHONE)
#include <SystemConfiguration/SystemConfiguration.h>
#include <SystemConfiguration/SCNetworkReachability.h>
#include <CFNetwork/CFNetwork.h>
#else
#include <CoreServices/CoreServices.h>
#endif

#include <Funambol/http/URL.h>
#include <Funambol/http/Proxy.h>
#include <Funambol/http/TransportAgent.h>
#include <Funambol/base/Log.h>
#include <Funambol/http/HttpAuthentication.h>

#define ERR_HTTP_TIME_OUT               ERR_TRANSPORT_BASE+ 7
#define ERR_HTTP_NOT_FOUND              ERR_TRANSPORT_BASE+60
#define ERR_HTTP_REQUEST_TIMEOUT        ERR_TRANSPORT_BASE+61
#define ERR_HTTP_INFLATE                ERR_TRANSPORT_BASE+70
#define ERR_HTTP_DEFLATE                ERR_TRANSPORT_BASE+71



/** Max number of attempts sending http requests. */
#define MAX_RETRIES                     3                       // Max number of attempts sending http requests.


BEGIN_FUNAMBOL_NAMESPACE

typedef char* (*TransportSendBufferPtr)(const void * data, const unsigned int size, HttpAuthentication *auth, TransportAgent *agent, void * context);

class CustomTransportAgent : public TransportAgent {
    private:
        HttpAuthentication *auth;
        TransportSendBufferPtr sendPtr;
        void * context;
    
    public:
        CustomTransportAgent();
        CustomTransportAgent(const URL& url, Proxy& proxy, unsigned int responseTimeout = DEFAULT_MAX_TIMEOUT);
        ~CustomTransportAgent();
        void setSendPtr(TransportSendBufferPtr ptr);
        void setContext(void *context);
        StringMap getRequestProperties();
        StringMap getResponseProperties();
    
        char* sendMessage(const char* msg);
        char* sendMessage(const char* msg, const unsigned int length);
};

END_FUNAMBOL_NAMESPACE

/** @endcond */
#endif

