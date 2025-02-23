#pragma once
#ifndef DB_H
#define DB_H
#include <memory>
#include <Qobject.h>
#include "delete.h"
#include "query.h"
#include "update.h"
#include "insert.h"
#include "cond.h"
#include"e.h"
#include "qsqlgen_global.h"

QSQLGEN_EXPORT std::unique_ptr<_Query> Query();
QSQLGEN_EXPORT std::unique_ptr<_Delete> Delete();
QSQLGEN_EXPORT std::unique_ptr<_Update> Update();
QSQLGEN_EXPORT std::unique_ptr<_Insert> Insert();
QSQLGEN_EXPORT std::unique_ptr<Func> CAST_TO_VARCHAR2(const E& e);
QSQLGEN_EXPORT std::unique_ptr<Func> HEXTORAW(const E& e);
QSQLGEN_EXPORT std::unique_ptr<Col> c(const QString& col);
QSQLGEN_EXPORT std::unique_ptr<Val> v(const std::variant<int,double,float,QString>& value,bool toCodecHex = false);
QSQLGEN_EXPORT std::unique_ptr<Cond> cond(const E& e1,const QString& op,const E& e2);
QSQLGEN_EXPORT std::unique_ptr<Cond> cond(const _Query& q1,const QString& op,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> cond(const E& e,const QString& op,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> cond(const _Query& q,const QString& op,const E& e);

template<typename T>
concept AllowedType=std::is_same_v<T,_Query>||std::is_same_v<T,Val>||std::is_same_v<T,Func>;

template<AllowedType... Args>
std::unique_ptr<Cond> in(const E& e, Args&... args){
    QString raw = e.raw+" IN ("+_in(std::forward<Args>(args)...)+")";
    return std::make_unique<Cond>(raw);
}
template<AllowedType... Args>
std::unique_ptr<Cond> in(const _Query& q, Args&... args){
    QString raw = "("+q.Sql()+") IN ("+_in(std::forward<Args>(args)...)+")";
    return std::make_unique<Cond>(raw);
}
extern template QSQLGEN_EXPORT std::unique_ptr<Cond> in<_Query,Val,Func>(const _Query&,_Query&,Val&,Func&);
extern template QSQLGEN_EXPORT std::unique_ptr<Cond> in<_Query,Val,Func>(const E&,_Query&,Val&,Func&);
QString _in();
template<AllowedType... Args>
QString _in(const std::variant<E,Func,Val>&& c,Args&&... args){
    QString raw = std::visit([](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, E>||std::is_same_v<T, Val>||std::is_same_v<T, Func>) {
            return arg.raw;
        }
    }, c);
    if(sizeof ...(args) >0){
        raw+=","+_in(std::forward<Args>(args)...);
    }
    return raw;
}
template<AllowedType... Args>
QString _in(const _Query&& c,Args&&... args){
    QString raw = "(+"+c.Sql()+")";
    if(sizeof ...(args) >0){
        raw+=","+_in(std::forward<Args>(args)...);
    }
    return raw;
}
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const E& e,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const E& e,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const E& e,const QList<std::variant<E,_Query>>& set);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const E& e,const std::variant<E,_Query> set[],unsigned size);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const _Query& q,const QList<std::variant<E,_Query>>& set);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const _Query& q,const std::variant<E,_Query> set[],unsigned size);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const QList<std::variant<E,_Query>>& set,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const QList<std::variant<E,_Query>>& set1,const QList<std::variant<E,_Query>>& set2);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const std::variant<E,_Query> set1[],unsigned size1,const std::variant<E,_Query> set2[],unsigned size2);

template<AllowedType... Args>
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const E& e, Args&... args);

template<AllowedType... Args>
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const _Query& q, Args&... args);
extern template QSQLGEN_EXPORT std::unique_ptr<Cond> notin<_Query,Val,Func>(const _Query&,_Query&,Val&,Func&);
extern template QSQLGEN_EXPORT std::unique_ptr<Cond> notin<_Query,Val,Func>(const E&,_Query&,Val&,Func&);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const E& e,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const E& e,const QList<std::variant<E,_Query>>& set);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const E& e,const std::variant<E,_Query> set[],unsigned size);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const _Query& q,const QList<std::variant<E,_Query>>& set);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const _Query& q,const std::variant<E,_Query> set[],unsigned size);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const QList<std::variant<E,_Query>>& set,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const QList<std::variant<E,_Query>>& set1,const QList<std::variant<E,_Query>>& set2);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const std::variant<E,_Query> set1[],unsigned size1,const std::variant<E,_Query> set2[],unsigned size2);

QSQLGEN_EXPORT std::unique_ptr<Cond> equal(const E& e1,const E& e2);
QSQLGEN_EXPORT std::unique_ptr<Cond> equal(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> equal(const E& value,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> equal(const _Query& q,const E& e);

QSQLGEN_EXPORT std::unique_ptr<Cond> notequal(const E& e1,const E& e2);
QSQLGEN_EXPORT std::unique_ptr<Cond> notequal(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> notequal(const E& value,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> notequal(const _Query& q,const E& e);

QSQLGEN_EXPORT std::unique_ptr<Cond> less(const E& e1,const E& e2);
QSQLGEN_EXPORT std::unique_ptr<Cond> less(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> less(const E& value,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> less(const _Query& q,const E& e);

QSQLGEN_EXPORT std::unique_ptr<Cond> more(const E& e1,const E& e2);
QSQLGEN_EXPORT std::unique_ptr<Cond> more(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> more(const E& value,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> more(const _Query& q,const E& e);

QSQLGEN_EXPORT std::unique_ptr<Cond> lessequal(const E& e1,const E& e2);
QSQLGEN_EXPORT std::unique_ptr<Cond> lessequal(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> lessequal(const E& value,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> lessequal(const _Query& q,const E& e);

QSQLGEN_EXPORT std::unique_ptr<Cond> moreequal(const E& e1,const E& e2);
QSQLGEN_EXPORT std::unique_ptr<Cond> moreequal(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> moreequal(const E& value,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> moreequal(const _Query& q,const E& e);
#endif // DB_H
