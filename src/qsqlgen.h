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
#include "qsqlgen_global.h"
QSQLGEN_EXPORT std::unique_ptr<_Query> Query();
QSQLGEN_EXPORT std::unique_ptr<_Delete> Delete();
QSQLGEN_EXPORT std::unique_ptr<_Update> Update();
QSQLGEN_EXPORT std::unique_ptr<_Insert> Insert();
QSQLGEN_EXPORT std::unique_ptr<Func> CAST_TO_VARCHAR2(const E& e);
QSQLGEN_EXPORT std::unique_ptr<Func> HEXTORAW(const E& e);
QSQLGEN_EXPORT Col c(const QString& col);
QSQLGEN_EXPORT Val v(const std::variant<int,double,float,QString>& value,bool toCodecHex = false);

QSQLGEN_EXPORT std::unique_ptr<Cond> in(const E& e,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const std::variant<E,_Query>& e,std::initializer_list<std::variant<E,_Query>> set);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(std::initializer_list<std::variant<E,_Query>> set,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> in(std::initializer_list<std::variant<E,_Query>> set1,std::initializer_list<std::variant<E,_Query>> set2);

QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const E& e,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const std::variant<E,_Query>& e,std::initializer_list<std::variant<E,_Query>> set);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(const _Query& q1,const _Query& q2);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(std::initializer_list<std::variant<E,_Query>> set,const _Query& q);
QSQLGEN_EXPORT std::unique_ptr<Cond> notin(std::initializer_list<std::variant<E,_Query>> set1,std::initializer_list<std::variant<E,_Query>> set2);

#endif // DB_H
