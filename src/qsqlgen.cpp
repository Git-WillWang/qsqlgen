#include "qsqlgen.h"
#include <qdebug.h>
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
Col c(const QString& col){
    return Col(col);
}
Val v(const std::variant<int,double,float,QString>& value,bool toCodecHex){
    return Val(value,toCodecHex);
}
std::unique_ptr<Func> CAST_TO_VARCHAR2(const E& e){
    return std::make_unique<Func>("CAST_TO_VARCHAR2",e);
}
std::unique_ptr<Func> HEXTORAW(const E& e){
    return std::make_unique<Func>("HEXTORAW",e);
}

std::unique_ptr<Cond> in(const E& e,const _Query& q){
    QString raw =e.raw+" IN ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> in(const std::variant<E,_Query>& e,std::initializer_list<std::variant<E,_Query>> set){
    QString raw = std::visit([](auto&& arg) {
                      using T = std::decay_t<decltype(arg)>;
                      if constexpr (std::is_same_v<T, E>) {
                          return arg.raw+",";
                      } else if constexpr (std::is_same_v<T, _Query>) {
                          return "("+arg.Sql() +"),";
                      }
                  }, e)+" IN (";
    if (set.size()!=0){
        for(const auto& s:set){
            raw += std::visit([](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw+",";
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +"),";
                }
            }, s);
        }
        raw.chop(1);
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> in(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") IN ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> in(std::initializer_list<std::variant<E,_Query>> set,const _Query& q){
    if (set.size()!=0){
        QString raw = "(";
        for(const auto& s:set){
            raw += std::visit([](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw+",";
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +"),";
                }
            }, s);
        }
        raw.chop(1);
        raw+=") IN ("+q.Sql()+")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> in(std::initializer_list<std::variant<E,_Query>> set1,std::initializer_list<std::variant<E,_Query>> set2){
    if (set1.size()!=0 && set2.size()!=0){
        QString raw = "(";
        for(const auto& s:set1){
            raw += std::visit([](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw+",";
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +"),";
                }
            }, s);
        }
        raw.chop(1);
        raw+=") IN (";
        for(const auto& s:set2){
            raw += std::visit([](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw+",";
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +"),";
                }
            }, s);
        }
        raw.chop(1);
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}

std::unique_ptr<Cond> notin(const E& e,const _Query& q){
    QString raw =e.raw+" NOT IN ("+q.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> notin(const E& e,const QList<std::variant<E,_Query>>& set){
    QString raw = e.raw+" NOT IN (";
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
std::unique_ptr<Cond> notin(const std::variant<E,_Query>& e,std::initializer_list<std::variant<E,_Query>> set){
    QString raw = std::visit([](auto&& arg) {
                      using T = std::decay_t<decltype(arg)>;
                      if constexpr (std::is_same_v<T, E>) {
                          return arg.raw+",";
                      } else if constexpr (std::is_same_v<T, _Query>) {
                          return "("+arg.Sql() +"),";
                      }
                  }, e)+" NOT IN (";
    if (set.size()!=0){
        for(const auto& s:set){
            raw += std::visit([](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw+",";
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +"),";
                }
            }, s);
        }
        raw.chop(1);
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> notin(const _Query& q1,const _Query& q2){
    QString raw = "("+q1.Sql()+") NOT IN ("+q2.Sql()+")";
    return std::make_unique<Cond>(raw);
}
std::unique_ptr<Cond> notin(std::initializer_list<std::variant<E,_Query>> set,const _Query& q){
    if (set.size()!=0){
        QString raw = "(";
        for(const auto& s:set){
            raw += std::visit([](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw+",";
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +"),";
                }
            }, s);
        }
        raw.chop(1);
        raw+=") NOT IN ("+q.Sql()+")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
std::unique_ptr<Cond> notin(std::initializer_list<std::variant<E,_Query>> set1,std::initializer_list<std::variant<E,_Query>> set2){
    if (set1.size()!=0 && set2.size()!=0){
        QString raw = "(";
        for(const auto& s:set1){
            raw += std::visit([](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw+",";
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +"),";
                }
            }, s);
        }
        raw.chop(1);
        raw+=") NOT IN (";
        for(const auto& s:set2){
            raw += std::visit([](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, E>) {
                    return arg.raw+",";
                } else if constexpr (std::is_same_v<T, _Query>) {
                    return "("+arg.Sql() +"),";
                }
            }, s);
        }
        raw.chop(1);
        raw+=")";
        return std::make_unique<Cond>(raw);
    }
    return nullptr;
}
