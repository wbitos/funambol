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

#ifndef INCL_WHERECLAUSE
#define INCL_WHERECLAUSE
/** @cond DEV */

#include <Funambol/base/fscapi.h>
#include <Funambol/filter/Clause.h>
#include <Funambol/base/globalsdef.h>

BEGIN_NAMESPACE

typedef enum {
    EQ       =  0,
    NE       =  1,
    GT       =  2,
    LT       =  3,
    GE       =  4,
    LE       =  5,
    CONTAIN  =  6,
    NCONTAIN =  7,
    UNKNOWN  = -1
} WhereClauseOperator;

class WhereClause : public Clause {

    // ------------------------------------------------------- Private interface
private:

    char*             property     ;
    char*             value        ;
    WhereClauseOperator op           ;
    bool                caseSensitive;

    // ----------------------------------------------------- Protected interface
protected:

    // -------------------------------------------------------- Public interface
public:

    /*
     * WhereClause constructor
     *
     */
    WhereClause();


    /*
     * WhereClause constructor
     *
     * @param property
     * @param value
     * @param o
     * @param s
     */
    WhereClause(const char*  property, const char*  value, WhereClauseOperator o, bool p3);


    /*
     * WhereClause destructor
     *
     */
    ~WhereClause();

    /*
     * setProperty
     *
     * @param p0
     */
    void setProperty(const char* p);


    /*
     * getProperty
     *
     */
    const char* getProperty();



    /*
     * setValue
     *
     * @param p0
     */
    void setValue(const char* v);


    /*
     * getvalue
     *
     */
    const char* getValue();


    /*
     * getOperator
     *
     */
    WhereClauseOperator getOperator();


    /*
     * setOperator
     *
     * @param o
     */
    void setOperator(WhereClauseOperator o);


    /*
     * isCaseSensitive
     *
     */
    bool isCaseSensitive();


    /*
     * setCaseSensitive
     *
     * @param s
     */
    void setCaseSensitive(bool s);

    /*
     * Creates a new instance of this Clause
     *
     * @return the clone
     */
    ArrayElement* clone();


};



END_NAMESPACE

/** @endcond */
#endif
