//
//  ErrorReport.cpp
//  Funambol
//
//  Created by yepin wang on 12-10-18.
//  Copyright (c) 2012年 365rili. All rights reserved.
//

#include "base/ErrorReport.h"

USE_NAMESPACE
static ErrorReport lastErrorReport;

StringBuffer ErrorReport::getRefrence() {
    return this->refrence;
}

StringBuffer ErrorReport::getMessage() {
    return this->message;
}

StringBuffer ErrorReport::getClassName() {
    return this->className;
}

StringBuffer ErrorReport::getMethod() {
    return this->method;
}

StringBuffer ErrorReport::getLineNumber() {
    return this->lineNumber;
}

void ErrorReport::setRefrence(StringBuffer ref) {
    this->refrence = ref;
}

void ErrorReport::setMessage(StringBuffer msg) {
    this->message = msg;
}

void ErrorReport::setClassName(StringBuffer cls) {
    this->className = cls;
}

void ErrorReport::setMethod(StringBuffer mth) {
    this->method = mth;
}

void ErrorReport::setLineNumber(StringBuffer lno) {
    this->lineNumber = lno;
}


ErrorReport ErrorReport::getLastErrorReport() {
    return lastErrorReport;
}

void ErrorReport::setLastErrorReport(ErrorReport report) {
    lastErrorReport = report;
}

ErrorReport &ErrorReport::operator=(ErrorReport report) {
    this->setClassName(report.getClassName());
    this->setLineNumber(report.getLineNumber());
    this->setMessage(report.getMessage());
    this->setMethod(report.getMethod());
    this->setRefrence(report.getRefrence());
    return *this;
}
