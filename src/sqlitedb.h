#ifndef SQLITEDB_H
#define SQLITEDB_H
#include <QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlError>
#include "qsqlgen_global.h"


class QSQLGEN_EXPORT Sqlitedb
{
public:
    Sqlitedb();
    bool open();
    void createTable();
    void query(QString& str);
    void isTableExist(QString& tableName);
    void insertOne(const QString& tableName,const QObject *obj);

    quint32 deleteData(const QString& tableName,const QMap<QString,QVariant>& cond);

};

#endif // SQLITEDB_H
