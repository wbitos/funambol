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

#ifndef INCL_OUTPUT_STREAM
#define INCL_OUTPUT_STREAM
/** @cond DEV */

#include <Funambol/base/fscapi.h>
#include <Funambol/base/constants.h>
#include <Funambol/base/globalsdef.h>
#include <Funambol/base/util/ArrayElement.h>


BEGIN_FUNAMBOL_NAMESPACE


/**
 * Abstract class that represents a generic Output Stream.
 * The method write() is inteded to write data to a generic stream.
 * Specific implementations of OutputStream can write data directly to a stream
 * in order to avoid loading a large object in memory.
 */
class OutputStream {

protected:

    /// The number of bytes written so far
    int bytesWritten;


public:

    /// Constructor
    OutputStream() : bytesWritten(0) {}

    virtual ~OutputStream() {}


    /**
     * Writes 'size' bytes of data to the stream.
     * Returns the number of bytes effectively written.
     * @param buffer    the buffer of data to be written
     * @param size      the size of data to write
     * @return          the number of bytes effectively written
     *                  if this number differs from the size parameter, it
     *                  indicates an error
     */
    virtual int write(const void* buffer, unsigned int size) = 0;



    /**
     * Closes the current output stream.
     * Derived classes SHOULD override this method in order to execute
     * all all necessary operations to close the stream.
     * @return 0 if no errors
     */
    virtual int close() { return 0; }


    /**
     * Returns the number of bytes written so far.
     */
    virtual int size() {
        return bytesWritten;
    }

};


END_FUNAMBOL_NAMESPACE

/** @endcond */
#endif
