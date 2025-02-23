#ifndef DELETE_H
#define DELETE_H

#include "cond.h"
#include <qobject.h>
class QSQLGEN_EXPORT _Delete
{
public:
    _Delete();
    QString raw;
    QString from;
    QString where;
    _Delete& From(const QString& table);
    _Delete& Where(const Cond& cond);
    _Delete& Where(const E& e1,const QString& op,const E& e2);
    _Delete& Where(const _Query&  q1,const QString& op,const _Query&  q2);
    _Delete& Where(const E& e,const QString& op,const _Query&  q);
    _Delete& Where(const _Query&  q,const QString& op,const E& e);
    QString Sql() const;
private:
    void getRaw();
};

#endif // DELETE_H
