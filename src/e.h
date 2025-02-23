#ifndef E_H
#define E_H

#include <qobject.h>
class E{
public :
    QString raw;
};

class Col:public E{
public:
    Col(const QString& col){
        this->raw = col;
    }
};
class Val:public E{
public:
    Val(const std::variant<int,double,float,QString>& val,bool toCodecHex);
};
class Func:public E{
public:
    Func(const QString& f,const E& e){
        this->raw = f+"("+e.raw+")";
    }
};
#endif // E_H
