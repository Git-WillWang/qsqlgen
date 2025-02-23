#include "utils.h"
#include <QtCore5Compat/qtextcodec.h>

Utils::Utils() {}

QString Utils::Utf8ConvertToCodecHex(const QString &input, const char *toCharset)
{
    QTextCodec *codec = QTextCodec::codecForName(toCharset);
    QByteArray CodecBytes = codec->fromUnicode(input);
    return CodecBytes.toHex().toUpper();
}

QString Utils::GBKHexConvertToUtf8(const QString &codecHex)
{
    QByteArray codecBytes=QByteArray::fromHex(codecHex.toUtf8());
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QString gbkString = codec->toUnicode(codecBytes);
    QString utf8String = QString::fromUtf8(gbkString.toUtf8());
    return utf8String;
}
