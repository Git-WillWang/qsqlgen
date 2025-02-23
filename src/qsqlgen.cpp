#include "qsqlgen.h"
std::unique_ptr<_Query> Query(){
    return std::make_unique<_Query>();
}
std::unique_ptr<_Delete> Delete(){
    return std::make_unique<_Delete>();
}
std::unique_ptr<_Update> Update(){
    return std::make_unique<_Update>();
}
 std::unique_ptr<_Insert> Insert(){
    return std::make_unique<_Insert>();
}
std::unique_ptr<Col> c(const QString& col){
    return std::make_unique<Col>(col);
}
std::unique_ptr<Val> v(const std::variant<int,double,float,QString>& value,bool toCodecHex){
    return std::make_unique<Val>(value,toCodecHex);
}
std::unique_ptr<Func> CAST_TO_VARCHAR2(const E& e){
    return std::make_unique<Func>("CAST_TO_VARCHAR2",e);
}
std::unique_ptr<Func> HEXTORAW(const E& e){
    return std::make_unique<Func>("HEXTORAW",e);
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
std::unique_ptr<Cond> in(const E& e,const _Query& q){
    QString raw =e.raw+" IN ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> in(const E& e,const QList<std::variant<E,_Query>>& set){
    QString raw = e.raw+" IN (";
    if (!set.isEmpty()){
        for (auto i = 0; i < set.size(); ++i) {
            auto size = set.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);

    }
    return nullptr;
}
std::unique_ptr<Cond> in(const E& e,const std::variant<E,_Query> set[],unsigned size){
    if (size!=0){
        QString raw = e.raw+" IN (";
        for (auto i = 0; i < size; ++i) {
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> in(const _Query& q,const QList<std::variant<E,_Query>>& set){
    QString raw = q.Sql()+" IN (";
    if (!set.isEmpty()){
        for (auto i = 0; i < set.size(); ++i) {
            auto size = set.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> in(const _Query& q,const std::variant<E,_Query> set[],unsigned size){
    QString raw = q.Sql()+" IN (";
    if (size!=0){
        for (auto i = 0; i < size; ++i) {
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> in(const QList<std::variant<E,_Query>>& set,const _Query& q){
    QString raw = q.Sql()+" IN (";
    if (!set.isEmpty()){
        for (auto i = 0; i < set.size(); ++i) {
            auto size = set.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> in(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") IN ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> in(const QList<std::variant<E,_Query>>& set1,const QList<std::variant<E,_Query>>& set2){
    QString raw;
    if (!set1.isEmpty() &&!set2.isEmpty()){
        for (auto i = 0; i < set1.size(); ++i) {
            auto size = set1.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set1[i]);

        }
        raw+=") IN (";
        for (auto i = 0; i < set2.size(); ++i) {
            auto size = set2.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set2[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> in(const std::variant<E,_Query> set1[],unsigned size1,const std::variant<E,_Query> set2[],unsigned size2){
    QString raw;
    if (size1!=0 &&size2!=0){
        for (auto i = 0; i < size1; ++i) {
            raw += std::visit([i,size1](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size1-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size1-1?"":",");
                }
            }, set1[i]);

        }
        raw+=") IN (";
        for (auto i = 0; i < size2; ++i) {
            raw += std::visit([i,size2](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size2-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size2-1?"":",");
                }
            }, set2[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}

template<AllowedType... Args>
QSQLGEN_EXPORT  std::unique_ptr<Cond> notin(const E& e, Args&... args){
    QString raw = e.raw+" NOT IN ("+_in(args...)+")";
    return std::make_unique<Cond>(raw);
}
template<AllowedType... Args>
QSQLGEN_EXPORT  std::unique_ptr<Cond> notin(const _Query& q, Args&... args){
    QString raw = "("+q.Sql()+") NOT IN ("+_in(std::forward<Args>(args)...)+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> notin(const E& e,const _Query& q){
    QString raw =e.raw+" IN ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> notin(const E& e,const QList<std::variant<E,_Query>>& set){
    QString raw = e.raw+" IN (";
    if (!set.isEmpty()){
        for (auto i = 0; i < set.size(); ++i) {
            auto size = set.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);

    }
    return nullptr;
}
std::unique_ptr<Cond> notin(const E& e,const std::variant<E,_Query> set[],unsigned size){
    QString raw = e.raw+" IN (";
    if (size!=0){
        for (auto i = 0; i < size; ++i) {
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> notin(const _Query& q,const QList<std::variant<E,_Query>>& set){
    QString raw = q.Sql()+" IN (";
    if (!set.isEmpty()){
        for (auto i = 0; i < set.size(); ++i) {
            auto size = set.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> notin(const _Query& q,const std::variant<E,_Query> set[],unsigned size){
    QString raw = q.Sql()+" IN (";
    if (size!=0){
        for (auto i = 0; i < size; ++i) {
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> notin(const QList<std::variant<E,_Query>>& set,const _Query& q){
    QString raw = q.Sql()+" IN (";
    if (!set.isEmpty()){
        for (auto i = 0; i < set.size(); ++i) {
            auto size = set.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> notin(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") IN ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> notin(const QList<std::variant<E,_Query>>& set1,const QList<std::variant<E,_Query>>& set2){
    QString raw;
    if (!set1.isEmpty() &&!set2.isEmpty()){
        for (auto i = 0; i < set1.size(); ++i) {
            auto size = set1.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set1[i]);

        }
        raw+=") IN (";
        for (auto i = 0; i < set2.size(); ++i) {
            auto size = set2.size();
            raw += std::visit([i,size](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size-1?"":",");
                }
            }, set2[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> notin(const std::variant<E,_Query> set1[],unsigned size1,const std::variant<E,_Query> set2[],unsigned size2){
    QString raw;
    if (size1!=0 &&size2!=0){
        for (auto i = 0; i < size1; ++i) {
            raw += std::visit([i,size1](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size1-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size1-1?"":",");
                }
            }, set1[i]);

        }
        raw+=") IN (";
        for (auto i = 0; i < size2; ++i) {
            raw += std::visit([i,size2](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw + (i==size2-1?"":",");
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +")"+ (i==size2-1?"":",");
                }
            }, set2[i]);

        }
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}

std::unique_ptr<Cond> equal(const E& e1,const E& e2){
    QString raw = e1.raw+" = "+e2.raw;
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> equal(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") = ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> equal(const E& e,const _Query& q){
    QString raw = e.raw+" = ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> equal(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") = "+e.raw;
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> notequal(const E& e1,const E& e2){
    QString raw = e1.raw+" <> "+e2.raw;
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> notequal(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") <> ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> notequal(const E& e,const _Query& q){
    QString raw = e.raw+" <> ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> notequal(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") <> "+e.raw;
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> less(const E& e1,const E& e2){
    QString raw = e1.raw+" < "+e2.raw;
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> less(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") < ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> less(const E& e,const _Query& q){
    QString raw = e.raw+" < ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> less(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") < "+e.raw;
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> more(const E& e1,const E& e2){
    QString raw = e1.raw+" > "+e2.raw;
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> more(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") > ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> more(const E& e,const _Query& q){
    QString raw = e.raw+" > ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> more(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") > "+e.raw;
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> lessequal(const E& e1,const E& e2){
    QString raw = e1.raw+" <= "+e2.raw;
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> lessequal(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") <= ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> lessequal(const E& e,const _Query& q){
    QString raw = e.raw+" <= ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> lessequal(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") <= "+e.raw;
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> moreequal(const E& e1,const E& e2){
    QString raw = e1.raw+" >= "+e2.raw;
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> moreequal(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") >= ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}

std::unique_ptr<Cond> moreequal(const E& e,const _Query& q){
    QString raw = e.raw+" >= ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> moreequal(const _Query& q,const E& e){
    QString raw = "("+q.Sql()+") >= "+e.raw;
    return std::make_unique<Cond>(raw);
}



QString _in()
{
    return "";
}
