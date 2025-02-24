#ifndef INSERT_H
#define INSERT_H

#include "query.h"
#include <qobject.h>
class QSQLGEN_EXPORT _Insert
{
public:
    _Insert();

    _Insert& InsertOne(const QString& tableName,const QObject& obj);
    _Insert& InsertOne(const QString& tableName,const QMap<QString,QString>& values);
    _Insert& InsertOne(const QString &tableName, std::initializer_list<std::pair<Col,std::variant<E,_Query>>> map);
    _Insert& InsertAll(const QString& tableName,const QList<QObject*>& values);
    _Insert& InsertSelect(const QString& tableName,const _Query& q);
    QString Sql() const;
private:
    QString raw;
    void getRaw();
};

#endif // INSERT_H
