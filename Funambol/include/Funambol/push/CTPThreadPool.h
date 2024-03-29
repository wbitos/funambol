/*
 * Funambol is a mobile platform developed by Funambol, Inc. 
 * Copyright (C) 2008 Funambol, Inc.
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
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
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

#ifndef INCL_CTP_THREAD_POOL
#define INCL_CTP_THREAD_POOL

#include <Funambol/base/globalsdef.h>
#include <Funambol/base/fscapi.h>
#include <Funambol/base/util/ArrayList.h>

BEGIN_NAMESPACE

// Forward declarations
class CmdTimeoutThread;
class HeartbeatThread;
class ReceiverThread;

/**
 * This class implements a pool of thread to be used by the CTP. The purpose is
 * not reusing existing threads, but rather to ensure that thread objects are
 * properly release when no longer running.
 * This class is a very simple form of garbage collection for CTP threads. The
 * cleanup is not performed automatically but must be explicitelly invoked.
 * Since CTP has periodic activity this is not a problem in this context.
 */

class CTPThreadPool {

public:

    /** Constructor */
    CTPThreadPool() {}

    /** Creates a new timeout thread */
    CmdTimeoutThread* createCmdTimeoutThread();

    /** Creates a new heartbeat thread */
    HeartbeatThread*  createHeartbeatThread();

    /** Creates a new receiver thread */
    ReceiverThread*   createReceiverThread();

    /** Cleanup any thread object that has terminated its execution */
    void cleanup();

private:
    ArrayList threadList;
};

END_NAMESPACE

#endif

