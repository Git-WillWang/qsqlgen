#include "query.h"
#include "cond.h"
#include "qsqlgen.h"
#include<QMap>
#include<QRegularExpression>
_Query::_Query() {}

_Query& _Query::InnerJoin(const _Query& table,const E& e1,const QString& op,const E& e2){
    this->from = "("+ this->from+") INNER JOIN ("+table.raw+") ON "+cond(e1,op,e2)->Raw();
    this->getRaw();
    return *this;
}
_Query& _Query::InnerJoin(const _Query& table,const _Query& q1,const QString& op,const _Query& q2){
    this->from = "("+ this->from+") INNER JOIN ("+table.raw+") ON "+cond(q1,op,q2)->Raw();
    this->getRaw();return *this;}
_Query& _Query::InnerJoin(const _Query& table,const E& e,const QString& op,const _Query& q){
    this->from = "("+ this->from+") INNER JOIN ("+table.raw+") ON "+cond(e,op,q)->Raw();
    this->getRaw();return *this;}
_Query& _Query::InnerJoin(const _Query& table,const _Query& q,const QString& op,const E& e){
    this->from = "("+ this->from+") INNER JOIN ("+table.raw+") ON "+cond(q,op,e)->Raw();
    this->getRaw();return *this;}

_Query& _Query::InnerJoin(const QString& table,const E& e1,const QString& op,const E& e2){
    this->from = "("+ this->from+") INNER JOIN ("+table+") ON "+cond(e1,op,e2)->Raw();
    this->getRaw();return *this;}
_Query& _Query::InnerJoin(const QString& table,const _Query& q1,const QString& op,const _Query& q2){
    this->from = "("+ this->from+") INNER JOIN ("+table+") ON "+cond(q1,op,q2)->Raw();
    this->getRaw();return *this;}
_Query& _Query::InnerJoin(const QString& table,const E& e,const QString& op,const _Query& q){
    this->from = "("+ this->from+") INNER JOIN ("+table+") ON "+cond(e,op,q)->Raw();
    this->getRaw();return *this;}
_Query& _Query::InnerJoin(const QString& table,const _Query& q,const QString& op,const E& e){
    this->from = "("+ this->from+") INNER JOIN ("+table+") ON "+cond(q,op,e)->Raw();
    this->getRaw();return *this;}


_Query& _Query::LeftJoin(const _Query& table,const E& e1,const QString& op,const E& e2){
    this->from = "("+ this->from+") LEFT JOIN ("+table.raw+") ON "+cond(e1,op,e2)->Raw();
    this->getRaw();return *this;}
_Query& _Query::LeftJoin(const _Query& table,const _Query& q1,const QString& op,const _Query& q2){
    this->from = "("+ this->from+") LEFT JOIN ("+table.raw+") ON "+cond(q1,op,q2)->Raw();
    this->getRaw();return *this;}
_Query& _Query::LeftJoin(const _Query& table,const E& e,const QString& op,const _Query& q){
    this->from = "("+ this->from+") LEFT JOIN ("+table.raw+") ON "+cond(e,op,q)->Raw();
    this->getRaw();return *this;}
_Query& _Query::LeftJoin(const _Query& table,const _Query& q,const QString& op,const E& e){
    this->from = "("+ this->from+") LEFT JOIN ("+table.raw+") ON "+cond(q,op,e)->Raw();
    this->getRaw();return *this;}

_Query& _Query::LeftJoin(const QString& table,const E& e1,const QString& op,const E& e2){
    this->from = "("+ this->from+") LEFT JOIN ("+table+") ON "+cond(e1,op,e2)->Raw();
    this->getRaw();return *this;}
_Query& _Query::LeftJoin(const QString& table,const _Query& q1,const QString& op,const _Query& q2){
    this->from = "("+ this->from+") LEFT JOIN ("+table+") ON "+cond(q1,op,q2)->Raw();
    this->getRaw();return *this;}
_Query& _Query::LeftJoin(const QString& table,const E& e,const QString& op,const _Query& q){
    this->from = "("+ this->from+") LEFT JOIN ("+table+") ON "+cond(e,op,q)->Raw();
    this->getRaw();return *this;}
_Query& _Query::LeftJoin(const QString& table,const _Query& q,const QString& op,const E& e){
    this->from = "("+ this->from+") LEFT JOIN ("+table+") ON "+cond(q,op,e)->Raw();
    this->getRaw();return *this;}

_Query& _Query::From(const _Query& q)
{
    this->from = "("+q.raw+")";
    this->getRaw();
    return *this;
}

_Query& _Query::From(const QString &table)
{
    this->from = table;
    this->getRaw();
    qDebug()<<this->select;
    return *this;
}


_Query& _Query::Where(const Cond& cond)
{
    this->where = "("+this->where+") AND ("+cond.Raw()+")";
    this->getRaw();
    return *this;
}

_Query& _Query::Where(const E &e1, const QString &op, const E &e2)
{
    if (this->where.isEmpty()){
        this->where = cond(e1,op,e2)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(e1,op,e2)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Query& _Query::Where(const _Query& q1, const QString &op, const _Query& q2)
{
    if (this->where.isEmpty()){
        this->where = cond(q1,op,q2)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(q1,op,q2)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Query& _Query::Where(const E &e, const QString &op, const _Query &q)
{
    if (this->where.isEmpty()){
        this->where = cond(e,op,q)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(e,op,q)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Query& _Query::Where(const _Query &q, const QString &op, const E &e)
{
    if (this->where.isEmpty()){
        this->where = cond(q,op,e)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(q,op,e)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Query& _Query::Select(const E &e)
{
    this->select += (this->select.isEmpty()?"":",") + e.raw;
    this->getRaw();
    return *this;
}

_Query& _Query::Select(const QList<E> &cols)
{
    if (cols.size()>0 && !this->select.isEmpty()){
        this->select+=",";
    }
    for (auto i = 0; i < cols.size(); ++i) {
        this->select+=cols[i].raw+(i==cols.size()-1?"":",");
    }
    this->getRaw();
    return *this;
}

_Query& _Query::Select(const E cols[],int size)
{
    if (size>0 && !this->select.isEmpty()){
        this->select+=",";
    }
    for (auto i = 0; i < size; ++i) {
        this->select+=cols[i].raw+(i==size-1?"":",");
    }
    this->getRaw();
    return *this;
}
_Query& _Query::GroupBy(const QString &cols)
{
    this->groupBy+=(this->groupBy.isEmpty()?"":",")+cols;
    this->getRaw();
    return *this;
}

_Query& _Query::GroupBy(const QList<QString> &cols)
{
    if (cols.size()>0 && !this->groupBy.isEmpty()){
        this->groupBy+=",";
    }
    for (auto i = 0; i < cols.size(); ++i) {
        this->groupBy+=cols.at(i)+(i==cols.size()-1?"":",");
    }
    this->getRaw();
    return *this;
}

_Query& _Query::OrderBy(const QString &col,const QString& order)
{
    auto upper = order.toUpper();
    if (upper=="ASC" || upper =="DESC"){
        this->orderBy += (this->orderBy.isEmpty()?"":",")+col+" "+order;
    }
    this->getRaw();
    return *this;
}

_Query& _Query::OrderBy(const QMap<QString,QString>& cols)
{
    if (!this->orderBy.isEmpty()&&!cols.isEmpty())
    for(auto i =cols.constBegin();i!=cols.constEnd();++i){
        auto upper = i.value().toUpper();
        if (upper=="ASC" || upper =="DESC"){
            this->orderBy+=","+i.key()+" "+upper;
        }
    }
    const auto re = QRegularExpression("^-|-$");
    this->orderBy.remove(re);
    this->getRaw();
    return *this;
}

_Query& _Query::Limit(const unsigned int n)
{
    this->limit = QString::number(n);
    this->getRaw();
    return *this;
}

_Query& _Query::Limit(const unsigned int start, const unsigned int n)
{
    this->limit = QString::number(start)+","+QString::number(n);
    this->getRaw();
    return *this;
}

_Query& _Query::Offset(const unsigned int n)
{
    this->offset = QString::number(n);
    this->getRaw();
    return *this;
}

QString _Query::getRaw()
{
    if(this->select.isEmpty() || this->from.isEmpty()){
        return "";
    }else{
        this->raw = "SELECT "+this->select+" FROM "+this->from;
    }
    if (!this->where.isEmpty()){
        this->raw += " WHERE "+ this->where;
    }
    if (!this->groupBy.isEmpty()){
        this->raw += " GROUP BY "+this->groupBy;
    }
    if (!this->orderBy.isEmpty()){
        this->raw+=" ORDER BY "+this->orderBy;
    }
    if (!this->limit.isEmpty()){
        this->raw +=" LIMIT "+this->limit;
    }
    if (!this->offset.isEmpty()){
        this->raw+=" OFFSET "+this->offset;
    }
    return this->raw;
}
QString _Query::Sql() const{
    return this->raw;
}
