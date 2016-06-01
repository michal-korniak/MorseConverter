#include "morseconverter.h"
#include <iterator>


MorseConverter::List_t MorseConverter::dict=List_t
{
    qMakePair(QString("A"),QString(".-")),
    qMakePair(QString("B"),QString("-...")),
    qMakePair(QString("C"),QString("-.-.")),
    qMakePair(QString("D"),QString("-..")),
    qMakePair(QString("E"),QString(".")),
    qMakePair(QString("F"),QString("..-.")),
    qMakePair(QString("G"),QString("--.")),
    qMakePair(QString("H"),QString("....")),
    qMakePair(QString("I"),QString("..")),
    qMakePair(QString("J"),QString(".---")),
    qMakePair(QString("K"),QString("-.-")),
    qMakePair(QString("L"),QString(".-..")),
    qMakePair(QString("M"),QString("--")),
    qMakePair(QString("N"),QString("-.")),
    qMakePair(QString("O"),QString("---")),
    qMakePair(QString("P"),QString(".--.")),
    qMakePair(QString("Q"),QString("--.-")),
    qMakePair(QString("R"),QString(".-.")),
    qMakePair(QString("S"),QString("...")),
    qMakePair(QString("T"),QString("-")),
    qMakePair(QString("U"),QString("..-")),
    qMakePair(QString("V"),QString("...-")),
    qMakePair(QString("W"),QString(".--")),
    qMakePair(QString("X"),QString("-..-")),
    qMakePair(QString("Y"),QString("-.--")),
    qMakePair(QString("Z"),QString("--..")),
    qMakePair(QString("Ą"),QString(".-.-")),
    qMakePair(QString("Ć"),QString("-.-..")),
    qMakePair(QString("Ę"),QString("..-..")),
    qMakePair(QString("Ł"),QString(".-..-")),
    qMakePair(QString("Ń"),QString("--.--")),
    qMakePair(QString("Ó"),QString("---.")),
    qMakePair(QString("Ś"),QString("...-...")),
    qMakePair(QString("Ż"),QString("--..-.")),
    qMakePair(QString("Ź"),QString("--..-")),
    qMakePair(QString("1"),QString(".----")),
    qMakePair(QString("2"),QString("..---")),
    qMakePair(QString("3"),QString("...--")),
    qMakePair(QString("4"),QString("....-")),
    qMakePair(QString("5"),QString(".....")),
    qMakePair(QString("6"),QString("-....")),
    qMakePair(QString("7"),QString("--...")),
    qMakePair(QString("8"),QString("---..")),
    qMakePair(QString("9"),QString("----.")),
    qMakePair(QString("0"),QString("-----")),
    qMakePair(QString("."),QString(".-.-.-")),
    qMakePair(QString(","),QString("--..--")),
    qMakePair(QString("?"),QString("..--..")),
    qMakePair(QString("!"),QString("-.-.--")),


};
QString MorseConverter::convertToMorse(const QString input)
{
    QString result;
    foreach(QChar ch, input)
    {
        if(ch==' ')
        {
            result+="  ";
            continue;
        }
        if(ch=='\n')
        {
            result+='\n';
        }
        List_t::Iterator it=std::find_if(dict.begin(),dict.end(),
                                   [ch](const QPair<QString,QString> x)->bool {return QString(ch.toUpper())==x.first;});
        if(it!=dict.end())
        {
            result+=(*it).second;
            result+=" ";
        }
    }
    return result;
}
QString MorseConverter::convertFromMorse(const QString input)
{
    QString result;
    foreach(QString str, input.split(' '))
    {
        if(str.isEmpty())
        {
            //string is empty, if two spaces stand alongside
            result+=" ";
            continue;
        }
        int newLines=str.count('\n');       //one string can contain more than one new line
        while(newLines--)
        {
            result+='\n';
            //didn't use continue, because string can contain something else than new lines characters
        }
        str=str.trimmed();   //we dealed with new lines characters, so we can get rid theire
        List_t::Iterator it=std::find_if(dict.begin(),dict.end(),
                                   [str](const QPair<QString,QString> x)->bool {return QString(str)==x.second;});
        if(it!=dict.end())
        {
            result+=(*it).first;
        }
    }
    return result;
}
