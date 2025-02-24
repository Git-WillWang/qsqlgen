#include "sqlitedb.h"
Sqlitedb::Sqlitedb() {}


void Sqlitedb::insertOne(const QString& tableName,const QObject *obj){
    auto metaObject = obj->metaObject();
    for (int i =metaObject->propertyOffset();i<metaObject->propertyCount();++i){
        auto property = metaObject->property(i);
        if (property.userType()==QMetaType::Int){
            qDebug()<<property.name()<<" "<<obj->property(property.name()).value<int>();
        }else if (property.userType()==QMetaType::QString){
            qDebug()<<property.name()<<" "<<obj->property(property.name()).value<QString>();
        }

    }
}

unsigned Sqlitedb::deleteData(const QString& tableName,const QMap<QString,QVariant>& cond){
    return 0;
}
