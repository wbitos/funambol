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

#include <Funambol/spds/DataTransformerFactory.h>
#include <Funambol/spds/B64Encoder.h>
#include <Funambol/spds/B64Decoder.h>
#include <Funambol/spds/DESEncoder.h>
#include <Funambol/spds/DESDecoder.h>
#include <Funambol/base/globalsdef.h>

USE_NAMESPACE

DataTransformer* DataTransformerFactory::getEncoder(const char* name) {
    DataTransformer* ret = NULL;

    if (isSupportedEncoder(name) == false) {
        //lastErrorCode = ERR_DT_UNKNOWN;
        //sprintf (lastErrorMsg, ERRMSG_DT_UNKNOWN, name);
        setErrorF(ERR_DT_UNKNOWN, ERRMSG_DT_UNKNOWN, name);
        goto exit;
    } else if (strcmp(name, DT_B64) == 0) {
        //
        // base 64 encoder
        //
        ret = new B64Encoder();
    } else if (strcmp(name, DT_DES) == 0) {
        //
        // DES encoder
        //
        ret = new DESEncoder();
    }

exit:

    return ret;
}

DataTransformer* DataTransformerFactory::getDecoder(const char* name) {
    DataTransformer* ret = NULL;

    if (isSupportedDecoder(name) == false) {
        //lastErrorCode = ERR_DT_UNKNOWN;
        //sprintf (lastErrorMsg, ERRMSG_DT_UNKNOWN, name);
        setErrorF(ERR_DT_UNKNOWN, ERRMSG_DT_UNKNOWN, name);
        goto exit;
    } else if (strcmp(name, DT_B64) == 0) {
        //
        // base 64 decoder
        //
        ret = new B64Decoder();
    } else if (strcmp(name, DT_DES) == 0) {
        //
        // DES decoder
        //
        ret = new DESDecoder();
    }

exit:

    return ret;
}

bool DataTransformerFactory::isSupportedEncoder(const char* name) {
    char* t = new char[strlen(name)+2];

    sprintf(t, "%s;", name);
    //strcpy(t, name); strcat(t, ";");

    bool ret = (strstr(DF_FORMATTERS, t) != NULL);

    delete [] t;

    return ret;

}

bool DataTransformerFactory::isSupportedDecoder(const char* name) {
    //
    // Currently, same encoders/decoders are supported
    //
    return isSupportedEncoder(name);

}

