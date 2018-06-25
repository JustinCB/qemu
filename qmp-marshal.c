/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QMP->QAPI command dispatch
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

#include "qemu-objects.h"
#include "qapi/qmp-core.h"
#include "qapi/qapi-visit-core.h"
#include "qapi/qmp-output-visitor.h"
#include "qapi/qmp-input-visitor.h"
#include "qapi/qapi-dealloc-visitor.h"
#include "qapi-types.h"
#include "qapi-visit.h"

#include "qmp-commands.h"

static void qmp_marshal_output_query_name(NameInfo * ret_in, QObject **ret_out, Error **errp)
{
    QapiDeallocVisitor *md = qapi_dealloc_visitor_new();
    QmpOutputVisitor *mo = qmp_output_visitor_new();
    Visitor *v;

    v = qmp_output_get_visitor(mo);
    visit_type_NameInfo(v, &ret_in, "unused", errp);
    if (!error_is_set(errp)) {
        *ret_out = qmp_output_get_qobject(mo);
    }
    qmp_output_visitor_cleanup(mo);
    v = qapi_dealloc_get_visitor(md);
    visit_type_NameInfo(v, &ret_in, "unused", errp);
    qapi_dealloc_visitor_cleanup(md);
}

int qmp_marshal_input_query_name(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    NameInfo * retval = NULL;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    retval = qmp_query_name(errp);
    qmp_marshal_output_query_name(retval, ret, errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

static void qmp_marshal_output_query_version(VersionInfo * ret_in, QObject **ret_out, Error **errp)
{
    QapiDeallocVisitor *md = qapi_dealloc_visitor_new();
    QmpOutputVisitor *mo = qmp_output_visitor_new();
    Visitor *v;

    v = qmp_output_get_visitor(mo);
    visit_type_VersionInfo(v, &ret_in, "unused", errp);
    if (!error_is_set(errp)) {
        *ret_out = qmp_output_get_qobject(mo);
    }
    qmp_output_visitor_cleanup(mo);
    v = qapi_dealloc_get_visitor(md);
    visit_type_VersionInfo(v, &ret_in, "unused", errp);
    qapi_dealloc_visitor_cleanup(md);
}

int qmp_marshal_input_query_version(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    VersionInfo * retval = NULL;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    retval = qmp_query_version(errp);
    qmp_marshal_output_query_version(retval, ret, errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

static void qmp_marshal_output_query_kvm(KvmInfo * ret_in, QObject **ret_out, Error **errp)
{
    QapiDeallocVisitor *md = qapi_dealloc_visitor_new();
    QmpOutputVisitor *mo = qmp_output_visitor_new();
    Visitor *v;

    v = qmp_output_get_visitor(mo);
    visit_type_KvmInfo(v, &ret_in, "unused", errp);
    if (!error_is_set(errp)) {
        *ret_out = qmp_output_get_qobject(mo);
    }
    qmp_output_visitor_cleanup(mo);
    v = qapi_dealloc_get_visitor(md);
    visit_type_KvmInfo(v, &ret_in, "unused", errp);
    qapi_dealloc_visitor_cleanup(md);
}

int qmp_marshal_input_query_kvm(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    KvmInfo * retval = NULL;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    retval = qmp_query_kvm(errp);
    qmp_marshal_output_query_kvm(retval, ret, errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

static void qmp_marshal_output_query_status(StatusInfo * ret_in, QObject **ret_out, Error **errp)
{
    QapiDeallocVisitor *md = qapi_dealloc_visitor_new();
    QmpOutputVisitor *mo = qmp_output_visitor_new();
    Visitor *v;

    v = qmp_output_get_visitor(mo);
    visit_type_StatusInfo(v, &ret_in, "unused", errp);
    if (!error_is_set(errp)) {
        *ret_out = qmp_output_get_qobject(mo);
    }
    qmp_output_visitor_cleanup(mo);
    v = qapi_dealloc_get_visitor(md);
    visit_type_StatusInfo(v, &ret_in, "unused", errp);
    qapi_dealloc_visitor_cleanup(md);
}

int qmp_marshal_input_query_status(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    StatusInfo * retval = NULL;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    retval = qmp_query_status(errp);
    qmp_marshal_output_query_status(retval, ret, errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

static void qmp_marshal_output_query_uuid(UuidInfo * ret_in, QObject **ret_out, Error **errp)
{
    QapiDeallocVisitor *md = qapi_dealloc_visitor_new();
    QmpOutputVisitor *mo = qmp_output_visitor_new();
    Visitor *v;

    v = qmp_output_get_visitor(mo);
    visit_type_UuidInfo(v, &ret_in, "unused", errp);
    if (!error_is_set(errp)) {
        *ret_out = qmp_output_get_qobject(mo);
    }
    qmp_output_visitor_cleanup(mo);
    v = qapi_dealloc_get_visitor(md);
    visit_type_UuidInfo(v, &ret_in, "unused", errp);
    qapi_dealloc_visitor_cleanup(md);
}

int qmp_marshal_input_query_uuid(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    UuidInfo * retval = NULL;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    retval = qmp_query_uuid(errp);
    qmp_marshal_output_query_uuid(retval, ret, errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

static void qmp_marshal_output_query_chardev(ChardevInfoList * ret_in, QObject **ret_out, Error **errp)
{
    QapiDeallocVisitor *md = qapi_dealloc_visitor_new();
    QmpOutputVisitor *mo = qmp_output_visitor_new();
    Visitor *v;

    v = qmp_output_get_visitor(mo);
    visit_type_ChardevInfoList(v, &ret_in, "unused", errp);
    if (!error_is_set(errp)) {
        *ret_out = qmp_output_get_qobject(mo);
    }
    qmp_output_visitor_cleanup(mo);
    v = qapi_dealloc_get_visitor(md);
    visit_type_ChardevInfoList(v, &ret_in, "unused", errp);
    qapi_dealloc_visitor_cleanup(md);
}

int qmp_marshal_input_query_chardev(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    ChardevInfoList * retval = NULL;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    retval = qmp_query_chardev(errp);
    qmp_marshal_output_query_chardev(retval, ret, errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

static void qmp_marshal_output_query_commands(CommandInfoList * ret_in, QObject **ret_out, Error **errp)
{
    QapiDeallocVisitor *md = qapi_dealloc_visitor_new();
    QmpOutputVisitor *mo = qmp_output_visitor_new();
    Visitor *v;

    v = qmp_output_get_visitor(mo);
    visit_type_CommandInfoList(v, &ret_in, "unused", errp);
    if (!error_is_set(errp)) {
        *ret_out = qmp_output_get_qobject(mo);
    }
    qmp_output_visitor_cleanup(mo);
    v = qapi_dealloc_get_visitor(md);
    visit_type_CommandInfoList(v, &ret_in, "unused", errp);
    qapi_dealloc_visitor_cleanup(md);
}

int qmp_marshal_input_query_commands(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    CommandInfoList * retval = NULL;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    retval = qmp_query_commands(errp);
    qmp_marshal_output_query_commands(retval, ret, errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

int qmp_marshal_input_quit(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    qmp_quit(errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

int qmp_marshal_input_stop(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    qmp_stop(errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

int qmp_marshal_input_system_reset(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    qmp_system_reset(errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

int qmp_marshal_input_system_powerdown(Monitor *mon, const QDict *qdict, QObject **ret)
{
    Error *local_err = NULL;
    Error **errp = &local_err;
    QDict *args = (QDict *)qdict;
    (void)args;
    if (error_is_set(errp)) {
        goto out;
    }
    qmp_system_powerdown(errp);

out:


    if (local_err) {
        qerror_report_err(local_err);
        error_free(local_err);
        return -1;
    }
    return 0;
}

