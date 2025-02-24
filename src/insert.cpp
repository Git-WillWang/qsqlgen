#include "insert.h"
#include <qmetaobject.h>

_Insert::_Insert() {}

_Insert& _Insert::InsertOne(const QString &tableName, const QObject &obj)
{
    this->raw = "INSERT INTO "+tableName+" (";
    auto metaObject = obj.metaObject();
    QString cols;
    QString values;
    for (int i =metaObject->propertyOffset();i<metaObject->propertyCount();++i){
        auto property = metaObject->property(i);
        cols+=QString(property.name())+",";
        if (property.userType()==QMetaType::Int||property.userType()==QMetaType::Float||property.userType()==QMetaType::Double){
            values+= QString::number(obj.property(property.name()).value<int>())+",";
        }else if (property.userType()==QMetaType::QString){
            values+="'"+obj.property(property.name()).value<QString>()+"',";
        }
    }
    if (cols.back()==','){
        cols.chop(1);
    }
    if (values.back()==','){
        values.chop(1);
    }
    this->raw +=cols+") VALUES ("+values+")";
    return *this;
}

_Insert& _Insert::InsertOne(const QString &tableName, std::initializer_list<std::pair<Col,std::variant<E,_Query>>> map)
{
    this->raw = "INSERT INTO "+tableName+" ";
    QString cols,values;
    for (const auto& m:map){
        cols+=m.first.raw + ",";
        values+=std::visit([](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, E>) {
                return arg.raw+",";
            } else if constexpr (std::is_same_v<T, _Query>) {
                return "("+arg.Sql() +"),";
            }
        }, m.second);
    }
    cols.chop(1);
    values.chop(1);
    this->raw += "("+cols+") VALUES ("+values+")";
    return *this;
}

_Insert& _Insert::InsertAll(const QString &tableName, const QList<QObject *> &objs)
{
    this->raw = "INSERT INTO "+tableName+" (";

    QString cols;
    QString values;
    for (auto j = objs.constBegin();j!=objs.constEnd();++j){
            QString valuesList ="(";
        auto metaObject = (*j)->metaObject();
        for (int i =metaObject->propertyOffset();i<metaObject->propertyCount();++i){
            auto property = metaObject->property(i);
            if (!cols.isEmpty()) cols+=QString(property.name())+",";
            if (property.userType()==QMetaType::Int||property.userType()==QMetaType::Float||property.userType()==QMetaType::Double){
                valuesList+= QString::number((*j)->property(property.name()).value<int>())+",";
            }else if (property.userType()==QMetaType::QString){
                valuesList+="'"+(*j)->property(property.name()).value<QString>()+"',";
            }
        }
        if (valuesList.back()==','){
            valuesList.chop(1);
        }
        if (cols.back()==','){
            cols.chop(1);
        }

        valuesList+=")";
        values+=valuesList+",";
    }
    if (values.back()==","){
        values.chop(1);
    }
     this->raw +=cols+") VALUES "+values;
    return *this;
}

_Insert& _Insert::InsertSelect(const QString &tableName, const _Query &q)
{
    this->raw = "INSERT INTO "+tableName+" ("+q.Sql()+")";
    return *this;
}

QString _Insert::Sql() const
{
    return this->raw;
}
