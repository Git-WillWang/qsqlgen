#ifndef UTILS_H
#define UTILS_H
#include<QObject>
#include "qsqlgen_global.h"
class QSQLGEN_EXPORT Utils
{
public:
    Utils();
    static QString Utf8ConvertToCodecHex(const QString& input,const char* toCharset="GBK");
    static QString GBKHexConvertToUtf8(const QString& codecHex);
};

#endif // UTILS_H
