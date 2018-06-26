/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI visitor function
 *
 * Copyright IBM, Corp. 2011
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#ifndef QAPI_VISIT_H
#define QAPI_VISIT_H

#include "qapi/qapi-visit-core.h"
#include "qapi-types.h"

void visit_type_NameInfo(Visitor *m, NameInfo ** obj, const char *name, Error **errp);
void visit_type_NameInfoList(Visitor *m, NameInfoList ** obj, const char *name, Error **errp);

void visit_type_VersionInfo(Visitor *m, VersionInfo ** obj, const char *name, Error **errp);
void visit_type_VersionInfoList(Visitor *m, VersionInfoList ** obj, const char *name, Error **errp);

void visit_type_KvmInfo(Visitor *m, KvmInfo ** obj, const char *name, Error **errp);
void visit_type_KvmInfoList(Visitor *m, KvmInfoList ** obj, const char *name, Error **errp);

void visit_type_RunState(Visitor *m, RunState * obj, const char *name, Error **errp);

void visit_type_StatusInfo(Visitor *m, StatusInfo ** obj, const char *name, Error **errp);
void visit_type_StatusInfoList(Visitor *m, StatusInfoList ** obj, const char *name, Error **errp);

void visit_type_UuidInfo(Visitor *m, UuidInfo ** obj, const char *name, Error **errp);
void visit_type_UuidInfoList(Visitor *m, UuidInfoList ** obj, const char *name, Error **errp);

void visit_type_ChardevInfo(Visitor *m, ChardevInfo ** obj, const char *name, Error **errp);
void visit_type_ChardevInfoList(Visitor *m, ChardevInfoList ** obj, const char *name, Error **errp);

void visit_type_CommandInfo(Visitor *m, CommandInfo ** obj, const char *name, Error **errp);
void visit_type_CommandInfoList(Visitor *m, CommandInfoList ** obj, const char *name, Error **errp);

#endif