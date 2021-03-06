/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI function prototypes
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

#ifndef QMP_COMMANDS_H
#define QMP_COMMANDS_H

#include "qapi-types.h"
#include "error.h"

NameInfo * qmp_query_name(Error **errp);
int qmp_marshal_input_query_name(Monitor *mon, const QDict *qdict, QObject **ret);
VersionInfo * qmp_query_version(Error **errp);
int qmp_marshal_input_query_version(Monitor *mon, const QDict *qdict, QObject **ret);
KvmInfo * qmp_query_kvm(Error **errp);
int qmp_marshal_input_query_kvm(Monitor *mon, const QDict *qdict, QObject **ret);
StatusInfo * qmp_query_status(Error **errp);
int qmp_marshal_input_query_status(Monitor *mon, const QDict *qdict, QObject **ret);
UuidInfo * qmp_query_uuid(Error **errp);
int qmp_marshal_input_query_uuid(Monitor *mon, const QDict *qdict, QObject **ret);
ChardevInfoList * qmp_query_chardev(Error **errp);
int qmp_marshal_input_query_chardev(Monitor *mon, const QDict *qdict, QObject **ret);
CommandInfoList * qmp_query_commands(Error **errp);
int qmp_marshal_input_query_commands(Monitor *mon, const QDict *qdict, QObject **ret);
void qmp_quit(Error **errp);
int qmp_marshal_input_quit(Monitor *mon, const QDict *qdict, QObject **ret);
void qmp_stop(Error **errp);
int qmp_marshal_input_stop(Monitor *mon, const QDict *qdict, QObject **ret);
void qmp_system_reset(Error **errp);
int qmp_marshal_input_system_reset(Monitor *mon, const QDict *qdict, QObject **ret);
void qmp_system_powerdown(Error **errp);
int qmp_marshal_input_system_powerdown(Monitor *mon, const QDict *qdict, QObject **ret);

#endif
