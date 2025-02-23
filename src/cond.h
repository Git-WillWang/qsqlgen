#pragma once

#include <memory>
#ifndef COND_H
#define COND_H
#include <QObject>
#include "e.h"
#include "query.h"
class QSQLGEN_EXPORT Cond
{
public:
    Cond(const QString& raw){
        this->raw = raw;
    }

    std::unique_ptr<Cond> And(const Cond& cond);
    std::unique_ptr<Cond> And(const E& e1,const QString& op,const E& e2);
    std::unique_ptr<Cond> And(const _Query& q1,const QString& op,const _Query& q2);
    std::unique_ptr<Cond> And(const _Query& q,const QString& op,const E& e);
    std::unique_ptr<Cond> And(const E& e,const QString& op,const _Query& q);
    std::unique_ptr<Cond> Or(const Cond& cond);
    std::unique_ptr<Cond> Or(const E& e1,const QString& op,const E& e2);
    std::unique_ptr<Cond> Or(const _Query& q1,const QString& op,const _Query& q2);
    std::unique_ptr<Cond> Or(const _Query& q,const QString& op,const E& e);
    std::unique_ptr<Cond> Or(const E& e,const QString& op,const _Query& q);
    QString Raw() const;
private:
    QString raw;
};
#endif
