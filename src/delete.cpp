#include "delete.h"
#include "cond.h"
#include "query.h"
_Delete::_Delete(){}

_Delete& _Delete::From(const QString &table)
{
    this->from = table;
    this->getRaw();
    return *this;
}

_Delete& _Delete::Where(const Cond& cond)
{
    this->where = "("+this->where+") AND ("+cond.Raw()+")";
    this->getRaw();
    return *this;
}

_Delete& _Delete::Where(const E &e1, const QString &op, const E &e2)
{
    if (this->where.isEmpty()){
        this->where = cond(e1,op,e2)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(e1,op,e2)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Delete& _Delete::Where(const _Query& q1, const QString &op, const _Query& q2)
{
    if (this->where.isEmpty()){
        this->where = cond(q1,op,q2)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(q1,op,q2)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Delete& _Delete:: Where(const E &e, const QString &op, const _Query& q)
{
    if (this->where.isEmpty()){
        this->where = cond(e,op,q)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(e,op,q)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Delete& _Delete::Where(const _Query& q, const QString &op, const E &e)
{
    if (this->where.isEmpty()){
        this->where = cond(q,op,e)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(q,op,e)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

QString _Delete::Sql() const
{
    return this->raw;
}


void _Delete::getRaw()
{
    if (this->from.isEmpty()){
        return;
    }else{
        this->raw = "DELETE FROM "+this->from;
    }
    if (!this->where.isEmpty()){
        this->raw += " WHERE "+this->where;
    }
}

