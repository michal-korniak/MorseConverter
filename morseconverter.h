#ifndef MORSECONVERTER_H
#define MORSECONVERTER_H
#include <QList>
#include <QPair>
#include <QString>
#include <algorithm>


class MorseConverter
{
private:
    typedef QList<QPair<QString,QString>> List_t;
    static List_t dict;
public:
    static QString convertToMorse(const QString input);
    static QString convertFromMorse(const QString input);

};


#endif // MORSECONVERTER_H
