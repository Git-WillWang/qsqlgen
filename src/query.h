#pragma once
#ifndef Q_H
#define Q_H
#include <QObject>
#include "qsqlgen_global.h"
#include "cond.h"


class QSQLGEN_EXPORT _Query
{
public:
    _Query();

    Cond operator=(const Val& val);
    Cond operator=(const Col& col);
    Cond operator=(const _Query& q);
    Cond operator=(const Func& f);
    Cond operator!=(const Col& col);
    Cond operator!=(const Val& val);
    Cond operator!=(const _Query& q);
    Cond operator!=(const Func& f);
    Cond operator>(const Col& col);
    Cond operator>(const Val& val);
    Cond operator>(const _Query& q);
    Cond operator>(const Func& f);
    Cond operator<(const Col& col);
    Cond operator<(const Val& val);
    Cond operator<(const _Query& q);
    Cond operator<(const Func& f);
    Cond operator<=(const Col& col);
    Cond operator<=(const Val& val);
    Cond operator<=(const _Query& q);
    Cond operator<=(const Func& f);
    Cond operator>=(const Col& col);
    Cond operator>=(const Val& val);
    Cond operator>=(const _Query& q);
    Cond operator>=(const Func& f);
    _Query& InnerJoin(const _Query& table,const E& e1,const QString& op,const E& e2);
    _Query& InnerJoin(const _Query& table,const _Query& q1,const QString& op,const _Query& q2);
    _Query& InnerJoin(const _Query& table,const E& e,const QString& op,const _Query& q);
    _Query& InnerJoin(const _Query& table,const _Query& q,const QString& op,const E& e);

    _Query& InnerJoin(const QString& table,const E& e1,const QString& op,const E& e2);
    _Query& InnerJoin(const QString& table,const _Query& q1,const QString& op,const _Query& q2);
    _Query& InnerJoin(const QString& table,const E& e,const QString& op,const _Query& q);
    _Query& InnerJoin(const QString& table,const _Query& q,const QString& op,const E& e);

    _Query& LeftJoin(const _Query& table,const E& e1,const QString& op,const E& e2);
    _Query& LeftJoin(const _Query& table,const _Query& q1,const QString& op,const _Query& q2);
    _Query& LeftJoin(const _Query& table,const E& e,const QString& op,const _Query& q);
    _Query& LeftJoin(const _Query& table,const _Query& q,const QString& op,const E& e);

    _Query& LeftJoin(const QString& table,const E& e1,const QString& op,const E& e2);
    _Query& LeftJoin(const QString& table,const _Query& q1,const QString& op,const _Query& q2);
    _Query& LeftJoin(const QString& table,const E& e,const QString& op,const _Query& q);
    _Query& LeftJoin(const QString& table,const _Query& q,const QString& op,const E& e);

    _Query& From(const _Query& q);
    _Query& From (const QString& table);
    _Query& Where(const Cond& cond);
    _Query& Where(const E& e1,const QString& op,const E& e2);
    _Query& Where(const _Query& q1,const QString& op,const _Query& q2);
    _Query& Where(const E& e,const QString& op,const _Query& q);
    _Query& Where(const _Query& q,const QString& op,const E& e);

    _Query& Select(const E& e);
    _Query& Select(std::initializer_list<E> cols);
    _Query& GroupBy(const QString& cols);
    _Query& GroupBy(std::initializer_list<Col> cols);
    _Query& GroupBy(std::initializer_list<QString> cols);
    _Query& OrderBy(const QString& col,const QString& order = QString("ASC"));
    _Query& OrderBy(std::initializer_list<QString[2]> orders);
    _Query& Limit(const unsigned n);
    _Query& Limit(const unsigned start,const unsigned n);
    _Query& Offset(const unsigned n);
    QString Sql() const;


private:
    QString raw;
    QString select;
    QString where;
    QString from;
    QString groupBy;
    QString orderBy;
    QString limit;
    QString offset;
    QString getRaw();
};

#endif // Q_H
