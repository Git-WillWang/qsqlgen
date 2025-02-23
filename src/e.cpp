#include "e.h"
#include "utils.h"

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

