#ifndef INSERT_H
#define INSERT_H

#include "query.h"
#include <qobject.h>
class QSQLGEN_EXPORT _Insert
{
public:
    _Insert();

    void InsertOne(const QString& tableName,const QObject& obj);
    void InsertOne(const QString& tableName,const QMap<QString,QString>& values);
    void InsertAll(const QString& tableName,const QList<QObject*>& values);
    void InsertSelect(const QString& tableName,const _Query& q);
    QString Sql() const;
private:
    QString raw;
    void getRaw();
};

#endif // INSERT_H
