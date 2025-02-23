#ifndef _Update_H
#define _Update_H

#include "cond.h"
#include <qobject.h>
#include "query.h"

class QSQLGEN_EXPORT _Update
{
public:
    _Update();

    _Update& Table(const QString& table);
    _Update& Set(const Col& col,const Val& value);
    _Update& Set(const Col& col,const _Query&  q);
    _Update& Where(const Cond& cond);
    _Update& Where(const E& e1,const QString& op,const E& e2);
    _Update& Where(const _Query&  q1,const QString& op,const _Query&  q2);
    _Update& Where(const E& e,const QString& op,const _Query&  q);
    _Update& Where(const _Query&  q,const QString& op,const E& e);
    QString Sql() const;
private:
    QString raw;
    QString table;
    QString set;
    QString where;
    void getRaw();
};

#endif // _Update_H
