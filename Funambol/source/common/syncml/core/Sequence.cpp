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


#include <Funambol/syncml/core/Sequence.h>
#include <Funambol/base/globalsdef.h>

USE_NAMESPACE


Sequence::Sequence() {

    COMMAND_NAME = new char[strlen(SEQUENCE_COMMAND_NAME) + 1];
    sprintf(COMMAND_NAME, SEQUENCE_COMMAND_NAME);
    this->commands = new ArrayList();
}

Sequence::~Sequence() {
    if(COMMAND_NAME) {
        delete [] COMMAND_NAME; COMMAND_NAME = NULL;
    }
    if (commands) {
        commands->clear();
        delete commands;
        commands = NULL;
    }
}

/**
* Create a new Sequence object. The commands in <i>commands</i>
* must be of the allowed types.
*
* @param cmdID command identifier - NOT NULL
* @param noResp is &lt;NoREsponse/&gt; required?
* @param meta meta information
* @param commands the sequenced commands - NOT NULL
*
*/
Sequence::Sequence(CmdID*       cmdID ,
            bool         noResp,
            Meta*        meta  ,
            ArrayList*   commands) : AbstractCommand(cmdID, noResp) {

    COMMAND_NAME = new char[strlen(SEQUENCE_COMMAND_NAME) + 1];
    sprintf(COMMAND_NAME, SEQUENCE_COMMAND_NAME);
    this->commands = new ArrayList();

    setMeta(meta);
    setCommands(commands);
}

/**
* Gets an array of AbstractCommand
*
* @return an array of command objects
*/
ArrayList* Sequence::getCommands() {
    return commands;
}

/**
* Sets the sequenced commands. The given commands must be of the allowed
* types.
*
* @param commands the commands - NOT NULL and o the allawed types
*/
void Sequence::setCommands(ArrayList* commands) {
    bool err = false;
    if (commands == NULL) {
        // TBD
        err = true;
    }
    for (int i = 0; i < commands->size(); i++) {
        if (commands->get(i) == NULL) {
            // TBD
            err = true;
        }
    }
    if (err == false) {
        this->commands->clear();
        delete this->commands;
        this->commands = commands->clone();
    }
}

/**
* Returns the command name
*
* @return the command name
*/
const char* Sequence::getName(){
    return COMMAND_NAME;
}

ArrayElement* Sequence::clone() {
    Sequence* ret = new Sequence(getCmdID(), getNoResp(), getMeta(), commands);
    return ret;

}
