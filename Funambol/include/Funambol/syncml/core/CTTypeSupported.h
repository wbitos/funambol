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


#ifndef INCL_CTTYPE_SUPPORTED
#define INCL_CTTYPE_SUPPORTED
/** @cond DEV */

#include <Funambol/base/fscapi.h>
#include <Funambol/base/util/ArrayList.h>
#include <Funambol/base/util/ArrayElement.h>
#include <Funambol/base/globalsdef.h>

BEGIN_NAMESPACE


class CTTypeSupported : public ArrayElement{

     // ------------------------------------------------------------ Private data
    private:
    char*  ctType;
    ArrayList* ctPropParams;    // CTPropParam[]

    void initialize();

    public:

    CTTypeSupported();
    ~CTTypeSupported();

    /**
     * Creates a new CTTypeSupported object with the given information
     *
     * @param ctType an String CTType - NOT NULL
     * @param ctPropParams the array of content type properties and/or content
     *                     content type parameters - NOT NULL
     *
     */
    CTTypeSupported(char*  ctType, ArrayList* ctPropParams );


    /**
     * Get a CTType String
     *
     * @return a CTType String
     */
    const char* getCTType();

    /**
     * Sets a CTType object
     *
     * @param ctType a CTType object
     */
    void setCTType(const char* ctType);

    /**
     * Gets an array of content type properties and parameters
     *
     * @return an array of content type properties and parameters
     *
     */
    ArrayList* getCTPropParams();

    /**
     * Sets an array of content type properties and parameters
     *
     * @param ctPropParams array of content type properties and parameters
     *
     */
    void setCTPropParams(ArrayList* ctPropParams);

    ArrayElement* clone();

};


END_NAMESPACE

/** @endcond */
#endif
