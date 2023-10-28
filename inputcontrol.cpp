#include <QtCore>
#include <QString>
#include <QRegularExpression>

bool regcheck(QString dat)
{
    static QRegularExpression variabel("&|<|>|\\\\| |/");
    QRegularExpressionMatch match = variabel.match(dat);
    if (match.hasMatch() == true)
    {
        return true;
    }
    else
    {
        return false;
    }

};
