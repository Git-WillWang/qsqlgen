#pragma once
#ifndef COND_H
#define COND_H
#include <QObject>
#include "qsqlgen_global.h"
class _Query;
class E;
class Val;
class Func;
class QSQLGEN_EXPORT Cond
{
public:
    Cond(const QString& raw);

    Cond& And(const Cond& cond);
    Cond& And(const E& e1,const QString& op,const E& e2);
    Cond& And(const _Query& q1,const QString& op,const _Query& q2);
    Cond& And(const _Query& q,const QString& op,const E& e);
    Cond& And(const E& e,const QString& op,const _Query& q);
    Cond& Or(const Cond& cond);
    Cond& Or(const E& e1,const QString& op,const E& e2);
    Cond& Or(const _Query& q1,const QString& op,const _Query& q2);
    Cond& Or(const _Query& q,const QString& op,const E& e);
    Cond& Or(const E& e,const QString& op,const _Query& q);
    Cond& operator||(const Cond& other);
    Cond& operator&&(const Cond& other);
    QString Raw() const;
    QString raw;
private:
};
class QSQLGEN_EXPORT E{
public :
    QString raw;
};

class QSQLGEN_EXPORT Col:public E{
public:
    Col(Col&& other) noexcept {
        raw = other.raw;
    }
    Col(const QString& col);
    Cond operator=(const Col& col);
    Cond operator=(const Val& val);
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
};
class  QSQLGEN_EXPORT  Val:public E{
public:
    Val(Val&& other) noexcept {
        raw = other.raw;
    }
    Val(const std::variant<int,double,float,QString>& val,bool toCodecHex);
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
};
class QSQLGEN_EXPORT Func:public E{
public:
    Func(Func&& other) noexcept {
        raw = other.raw;
    }
    Func(const QString& f,const E& e);
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
};
QSQLGEN_EXPORT std::unique_ptr<Cond> cond(const E& e1,const QString& op,const E& e2);
QSQLGEN_EXPORT std::unique_ptr<Cond> cond(const _Query& q1,const QString& op,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> cond(const E& e,const QString& op,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> cond(const _Query& q,const QString& op,const E& e);
QSQLGEN_EXPORT Cond equal(const E& e1,const E& e2);
QSQLGEN_EXPORT Cond equal(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT Cond equal(const E& value,const _Query& q);
QSQLGEN_EXPORT Cond equal(const _Query& q,const E& e);

QSQLGEN_EXPORT Cond notequal(const E& e1,const E& e2);
QSQLGEN_EXPORT Cond notequal(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT Cond notequal(const E& value,const _Query& q);
QSQLGEN_EXPORT Cond notequal(const _Query& q,const E& e);

QSQLGEN_EXPORT Cond less(const E& e1,const E& e2);
QSQLGEN_EXPORT Cond less(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT Cond less(const E& value,const _Query& q);
QSQLGEN_EXPORT Cond less(const _Query& q,const E& e);

QSQLGEN_EXPORT Cond more(const E& e1,const E& e2);
QSQLGEN_EXPORT Cond more(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT Cond more(const E& value,const _Query& q);
QSQLGEN_EXPORT Cond more(const _Query& q,const E& e);

QSQLGEN_EXPORT Cond lessequal(const E& e1,const E& e2);
QSQLGEN_EXPORT Cond lessequal(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT Cond lessequal(const E& value,const _Query& q);
QSQLGEN_EXPORT Cond lessequal(const _Query& q,const E& e);

QSQLGEN_EXPORT Cond moreequal(const E& e1,const E& e2);
QSQLGEN_EXPORT Cond moreequal(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT Cond moreequal(const E& value,const _Query& q);
QSQLGEN_EXPORT Cond moreequal(const _Query& q,const E& e);
#endif
