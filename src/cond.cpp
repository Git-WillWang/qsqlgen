#include "query.h"
#include "cond.h"
#include <qdebug.h>
#include "qsqlgen.h"

std::unique_ptr<Cond> Cond::And(const Cond& cond)
{
    QString raw =  "("+this->raw+") AND ("+cond.raw+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> Cond::And(const E &e1, const QString &op, const E &e2)
{
    QString raw =  "("+this->raw+") AND ("+cond(e1,op,e2)->raw+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> Cond::And(const _Query& q1, const QString &op, const _Query& q2)
{
    QString raw =  "("+this->raw+") AND ("+cond(q1,op,q2)->raw+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> Cond::And(const _Query& q, const QString &op, const E &e)
{
    QString raw =  "("+this->raw+") AND ("+cond(q,op,e)->raw+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> Cond::And(const E &e, const QString &op, const _Query& q)
{
    QString raw =  "("+this->raw+") AND ("+cond(e,op,q)->raw+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> Cond::Or(const Cond& cond)
{
    QString raw =  "("+this->raw+") OR ("+cond.raw+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> Cond::Or(const E &e1, const QString &op, const E &e2)
{
    QString raw =  "("+this->raw+") OR ("+cond(e1,op,e2)->raw+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> Cond::Or(const _Query& q1, const QString &op, const _Query& q2)
{
    QString raw =  "("+this->raw+") OR ("+cond(q1,op,q2)->raw+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> Cond::Or(const _Query& q, const QString &op, const E &e)
{
    QString raw =  "("+this->raw+") OR ("+cond(q,op,e)->raw+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> Cond::Or(const E &e, const QString &op, const _Query& q)
{
    QString raw =  "("+this->raw+") OR ("+cond(e,op,q)->raw+")";
    return std::make_unique<Cond>(raw);
}

QString Cond::Raw() const
{
    return this->raw;
}



