#include "query.h"
#include "cond.h"
#include "utils.h"

Cond Col::operator=(const Val& val){
    return *cond(*this,"=",val);
}
Cond Col::operator=(const Col& col){
    return *cond(*this,"=",col);
}
Cond Col::operator=(const _Query& q){
    return *cond(*this,"=",q);
}
Cond Col::operator=(const Func& f){
    return *cond(*this,"=",f);
}
Cond Col::operator!=(const Val& val){
    return *cond(*this,"<>",val);
}
Cond Col::operator!=(const Col& col){
    return *cond(*this,"<>",col);
}
Cond Col::operator!=(const _Query& q){
    return *cond(*this,"<>",q);
}
Cond Col::operator!=(const Func& f){
    return *cond(*this,"<>",f);
}
Cond Col::operator>=(const Val& val){
    return *cond(*this,">=",val);
}
Cond Col::operator>=(const Col& col){
    return *cond(*this,">=",col);
}
Cond Col::operator>=(const _Query& q){
    return *cond(*this,">=",q);
}
Cond Col::operator>=(const Func& f){
    return *cond(*this,">=",f);
}
Cond Col::operator<=(const Val& val){
    return *cond(*this,"<=",val);
}
Cond Col::operator<=(const Col& col){
    return *cond(*this,"<=",col);
}
Cond Col::operator<=(const _Query& q){
    return *cond(*this,"<=",q);
}
Cond Col::operator<=(const Func& f){
    return *cond(*this,"<=",f);
}
Cond Col::operator<(const Val& val){
    return *cond(*this,"<",val);
}
Cond Col::operator<(const Col& col){
    return *cond(*this,"<",col);
}
Cond Col::operator<(const _Query& q){
    return *cond(*this,"<",q);
}
Cond Col::operator<(const Func& f){
    return *cond(*this,"<",f);
}
Cond Col::operator>(const Val& val){
    return *cond(*this,">",val);
}
Cond Col::operator>(const Col& col){
    return *cond(*this,">",col);
}
Cond Col::operator>(const _Query& q){
    return *cond(*this,">",q);
}
Cond Col::operator>(const Func& f){
    return *cond(*this,">",f);
}
Cond Val::operator=(const Val& val){
    return *cond(*this,"=",val);
}
Cond Val::operator=(const Col& col){
    return *cond(*this,"=",col);
}
Cond Val::operator=(const _Query& q){
    return *cond(*this,"=",q);
}
Cond Val::operator=(const Func& f){
    return *cond(*this,"=",f);
}
Cond Val::operator!=(const Val& val){
    return *cond(*this,"<>",val);
}
Cond Val::operator!=(const Col& col){
    return *cond(*this,"<>",col);
}
Cond Val::operator!=(const _Query& q){
    return *cond(*this,"<>",q);
}
Cond Val::operator!=(const Func& f){
    return *cond(*this,"<>",f);
}
Cond Val::operator>=(const Val& val){
    return *cond(*this,">=",val);
}
Cond Val::operator>=(const Col& col){
    return *cond(*this,">=",col);
}
Cond Val::operator>=(const _Query& q){
    return *cond(*this,">=",q);
}
Cond Val::operator>=(const Func& f){
    return *cond(*this,">=",f);
}
Cond Val::operator<=(const Val& val){
    return *cond(*this,"<=",val);
}
Cond Val::operator<=(const Col& col){
    return *cond(*this,"<=",col);
}
Cond Val::operator<=(const _Query& q){
    return *cond(*this,"<=",q);
}
Cond Val::operator<=(const Func& f){
    return *cond(*this,"<=",f);
}
Cond Val::operator<(const Val& val){
    return *cond(*this,"<",val);
}
Cond Val::operator<(const Col& col){
    return *cond(*this,"<",col);
}
Cond Val::operator<(const _Query& q){
    return *cond(*this,"<",q);
}
Cond Val::operator<(const Func& f){
    return *cond(*this,"<",f);
}
Cond Val::operator>(const Val& val){
    return *cond(*this,">",val);
}
Cond Val::operator>(const Col& col){
    return *cond(*this,">",col);
}
Cond Val::operator>(const _Query& q){
    return *cond(*this,">",q);
}
Cond Val::operator>(const Func& f){
    return *cond(*this,">",f);
}
Cond Func::operator=(const Val& val){
    return *cond(*this,"=",val);
}
Cond Func::operator=(const Col& col){
    return *cond(*this,"=",col);
}
Cond Func::operator=(const _Query& q){
    return *cond(*this,"=",q);
}
Cond Func::operator=(const Func& f){
    return *cond(*this,"=",f);
}
Cond Func::operator!=(const Val& val){
    return *cond(*this,"<>",val);
}
Cond Func::operator!=(const Col& col){
    return *cond(*this,"<>",col);
}
Cond Func::operator!=(const _Query& q){
    return *cond(*this,"<>",q);
}
Cond Func::operator!=(const Func& f){
    return *cond(*this,"<>",f);
}
Cond Func::operator>=(const Val& val){
    return *cond(*this,">=",val);
}
Cond Func::operator>=(const Col& col){
    return *cond(*this,">=",col);
}
Cond Func::operator>=(const _Query& q){
    return *cond(*this,">=",q);
}
Cond Func::operator>=(const Func& f){
    return *cond(*this,">=",f);
}
Cond Func::operator<=(const Val& val){
    return *cond(*this,"<=",val);
}
Cond Func::operator<=(const Col& col){
    return *cond(*this,"<=",col);
}
Cond Func::operator<=(const _Query& q){
    return *cond(*this,"<=",q);
}
Cond Func::operator<=(const Func& f){
    return *cond(*this,"<=",f);
}
Cond Func::operator<(const Val& val){
    return *cond(*this,"<",val);
}
Cond Func::operator<(const Col& col){
    return *cond(*this,"<",col);
}
Cond Func::operator<(const _Query& q){
    return *cond(*this,"<",q);
}
Cond Func::operator<(const Func& f){
    return *cond(*this,"<",f);
}
Cond Func::operator>(const Val& val){
    return *cond(*this,">",val);
}
Cond Func::operator>(const Col& col){
    return *cond(*this,">",col);
}
Cond Func::operator>(const _Query& q){
    return *cond(*this,">",q);
}
Cond Func::operator>(const Func& f){
    return *cond(*this,">",f);
}

Col::Col(const QString& col){
    this->raw = col;
}
Val::Val(const std::variant<int, double, float, QString> &val, bool toCodecHex)
{
    this->raw = std::visit([toCodecHex](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, int>) {
            if(toCodecHex){
                return "'"+Utils::Utf8ConvertToCodecHex(QString::number(arg),"GBK")+"'";
            }else{
                return QString::number(arg);
            }
        } else if constexpr (std::is_same_v<T, double>) {
            if(toCodecHex){
                return "'"+Utils::Utf8ConvertToCodecHex(QString::number(arg),"GBK")+"'";
            }else{
                return QString::number(arg);
            }
        }else if  constexpr (std::is_same_v<T, float>){
            if(toCodecHex){
                return "'"+Utils::Utf8ConvertToCodecHex(QString::number(arg),"GBK")+"'";
            }else{
                return QString::number(arg);
            }
        } else if constexpr (std::is_same_v<T, QString>){
            if(toCodecHex){
                return "'"+Utils::Utf8ConvertToCodecHex(arg,"GBK")+"'";
            }else{
                return "'"+arg+"'";
            }
        }
    }, val);
}
Func::Func(const QString& f,const E& e){
    this->raw = f+"("+e.raw+")";
}
std::unique_ptr<Cond> cond(const E& e1,const QString& op,const E& e2){
    QString raw =e1.raw+" "+op+" "+e2.raw;
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> cond(const _Query& q1,const QString& op,const _Query& q2){
    QString raw ="("+q1.Sql()+") "+op+" ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> cond(const E& e,const QString& op,const _Query& q){
    QString raw =e.raw+" "+op+" ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> cond(const _Query& q,const QString& op,const E& e){
    QString raw ="("+q.Sql()+") "+op+" "+e.raw;
    return std::make_unique<Cond>(raw);
}
Cond equal(const E& e1,const E& e2){
    QString raw = e1.raw+" = "+e2.raw;
    return Cond(raw);
}

Cond equal(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") = ("+q2.Sql()+")";
    return Cond(raw);
}

Cond equal(const E& e,const _Query& q){
    QString raw = e.raw+" = ("+q.Sql()+")";
    return Cond(raw);
}
Cond equal(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") = "+e.raw;
    return Cond(raw);
}

Cond notequal(const E& e1,const E& e2){
    QString raw = e1.raw+" <> "+e2.raw;
    return Cond(raw);
}

Cond notequal(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") <> ("+q2.Sql()+")";
    return Cond(raw);
}

Cond notequal(const E& e,const _Query& q){
    QString raw = e.raw+" <> ("+q.Sql()+")";
    return Cond(raw);
}
Cond notequal(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") <> "+e.raw;
    return Cond(raw);
}

Cond less(const E& e1,const E& e2){
    QString raw = e1.raw+" < "+e2.raw;
    return Cond(raw);
}

Cond less(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") < ("+q2.Sql()+")";
    return Cond(raw);
}

Cond less(const E& e,const _Query& q){
    QString raw = e.raw+" < ("+q.Sql()+")";
    return Cond(raw);
}
Cond less(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") < "+e.raw;
    return Cond(raw);
}
Cond more(const E& e1,const E& e2){
    QString raw = e1.raw+" > "+e2.raw;
    return Cond(raw);
}

Cond more(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") > ("+q2.Sql()+")";
    return Cond(raw);
}

Cond more(const E& e,const _Query& q){
    QString raw = e.raw+" > ("+q.Sql()+")";
    return Cond(raw);
}
Cond more(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") > "+e.raw;
    return Cond(raw);
}

Cond lessequal(const E& e1,const E& e2){
    QString raw = e1.raw+" <= "+e2.raw;
    return Cond(raw);
}

Cond lessequal(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") <= ("+q2.Sql()+")";
    return Cond(raw);
}

Cond lessequal(const E& e,const _Query& q){
    QString raw = e.raw+" <= ("+q.Sql()+")";
    return Cond(raw);
}
Cond lessequal(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") <= "+e.raw;
    return Cond(raw);
}
Cond moreequal(const E& e1,const E& e2){
    QString raw = e1.raw+" >= "+e2.raw;
    return Cond(raw);
}

Cond moreequal(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") >= ("+q2.Sql()+")";
    return Cond(raw);
}

Cond moreequal(const E& e,const _Query& q){
    QString raw = e.raw+" >= ("+q.Sql()+")";
    return Cond(raw);
}
Cond moreequal(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") >= "+e.raw;
    return Cond(raw);
}


Cond::Cond(const QString &raw)
{
    this->raw = raw;
}

Cond& Cond::And(const Cond& cond)
{
    this->raw =  "("+this->raw+") AND ("+cond.raw+")";
    return *this;
}
Cond& Cond::And(const E &e1, const QString &op, const E &e2)
{
    this->raw =  "("+this->raw+") AND ("+cond(e1,op,e2)->raw+")";
    return *this;
}

Cond& Cond::And(const _Query& q1, const QString &op, const _Query& q2)
{
    this->raw  = "("+this->raw+") AND ("+cond(q1,op,q2)->raw+")";
    return *this;
}

Cond& Cond::And(const _Query& q, const QString &op, const E &e)
{
    this->raw =  "("+this->raw+") AND ("+cond(q,op,e)->raw+")";
    return *this;
}

Cond& Cond::And(const E &e, const QString &op, const _Query& q)
{
    this->raw =  "("+this->raw+") AND ("+cond(e,op,q)->raw+")";
    return *this;
}

Cond& Cond::Or(const Cond& cond)
{
    this->raw =  "("+this->raw+") OR ("+cond.raw+")";
    return *this;
}

Cond& Cond::Or(const E &e1, const QString &op, const E &e2)
{
    this->raw =  "("+this->raw+") OR ("+cond(e1,op,e2)->raw+")";
    return *this;
}
Cond& Cond::Or(const _Query& q1, const QString &op, const _Query& q2)
{
    this->raw =  "("+this->raw+") OR ("+cond(q1,op,q2)->raw+")";
    return *this;
}

Cond& Cond::Or(const _Query& q, const QString &op, const E &e)
{
    this->raw =  "("+this->raw+") OR ("+cond(q,op,e)->raw+")";
    return *this;
}

Cond& Cond::Or(const E &e, const QString &op, const _Query& q)
{
    this->raw =  "("+this->raw+") OR ("+cond(e,op,q)->raw+")";
    return *this;
}

QString Cond::Raw() const
{
    return this->raw;
}

Cond& Cond::operator||(const Cond& other) {
    return this->Or(other);
}
Cond& Cond::operator&&(const Cond& other) {
    return this->And(other);
}
