#include "update.h"
#include "query.h"
#include "qsqlgen.h"
_Update::_Update() {}

_Update& _Update::Table(const QString &table)
{
    this->table = table;
    this->getRaw();
    return *this;
}

_Update& _Update::Set(const Col &col, const Val &value)
{
    this->set += (this->set.isEmpty()?"":",")+col.raw+" = "+value.raw;
    this->getRaw();
    return *this;
}


_Update& _Update::Set(const Col &col, const _Query& q)
{
    this->set += (this->set.isEmpty()?"":",")+col.raw+" = ("+q.Sql()+")";
    this->getRaw();
    return *this;
}

_Update& _Update:: Where(const Cond& cond)
{
    this->where = "("+this->where+") AND ("+cond.Raw()+")";
    this->getRaw();
    return *this;
}

_Update& _Update:: Where(const E &e1, const QString &op, const E &e2)
{
    if (this->where.isEmpty()){
        this->where = cond(e1,op,e2)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(e1,op,e2)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Update& _Update:: Where(const _Query& q1, const QString &op, const _Query& q2)
{
    if (this->where.isEmpty()){
        this->where = cond(q1,op,q2)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(q1,op,q2)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Update& _Update:: Where(const E &e, const QString &op, const _Query& q)
{
    if (this->where.isEmpty()){
        this->where = cond(e,op,q)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(e,op,q)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

_Update& _Update:: Where(const _Query& q, const QString &op, const E &e)
{
    if (this->where.isEmpty()){
        this->where = cond(q,op,e)->Raw();
    }else{
        this->where = "(" +this->where+") AND ("+cond(q,op,e)->Raw()+")";
    }
    this->getRaw();
    return *this;
}

QString _Update::Sql() const
{
    return this->raw;
}


void _Update::getRaw()
{
    if (this->table.isEmpty()||this->set.isEmpty()){
        return;
    }else{
        this->raw = "_Update "+this->table+" SET "+this->set;
    }
    if (!this->where.isEmpty()){
        this->raw+=" WHERE "+this->where;
    }
}
