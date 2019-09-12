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


#include "base/fscapi.h"
#include <Foundation/Foundation.h>
#include <CoreFoundation/CoreFoundation.h>

#include "http/CustomTransportAgent.h"
#include "http/HttpConnectionHandler.h"
#include "http/constants.h"
#include "http/AbstractHttpConnection.h"
#include "base/util/utils.h"
#include "base/util/KeyValuePair.h"
#include "base/util/StringBuffer.h"
#include "event/FireEvent.h"
#include <pthread.h>
#include <zlib.h>

BEGIN_FUNAMBOL_NAMESPACE

CustomTransportAgent::CustomTransportAgent() : TransportAgent() {
    auth = NULL;
}

CustomTransportAgent::~CustomTransportAgent() {}

/*
 * Constructor.
 * In this implementation newProxy is ignored, since proxy configuration
 * is taken from the WinInet subsystem.
 *
 * @param url the url where messages will be sent with sendMessage()
 * @param proxy proxy information or NULL if no proxy should be used
 */
CustomTransportAgent::CustomTransportAgent(const URL& newURL, Proxy& newProxy, unsigned int maxResponseTimeout)
: TransportAgent(newURL, newProxy, maxResponseTimeout)
{
    auth = NULL;
}


// TODO
// consider moving both sendMessage and sendBuffer to basic class
char* CustomTransportAgent::sendMessage(const char* msg) {
	return sendMessage(msg, (unsigned int)strlen(msg));
}

/*
 * msg is not expected to be a zero terminated string !!!
 */
char* CustomTransportAgent::sendMessage(const char* msg, const unsigned int length) {
    if (this->sendPtr) {
        return this->sendPtr(msg, length, this->auth, this, this->context);
    }
	return NULL;
}

void CustomTransportAgent::setSendPtr(TransportSendBufferPtr ptr) {
    this->sendPtr = ptr;
}

void CustomTransportAgent::setContext(void *ctx) {
    this->context = ctx;
}

StringMap CustomTransportAgent::getRequestProperties() {
    return requestProperties;
}

StringMap CustomTransportAgent::getResponseProperties() {
    return responseProperties;
}
END_FUNAMBOL_NAMESPACE

