#ifndef MORSECONVERTERGUI_H
#define MORSECONVERTERGUI_H

#include <QMainWindow>

namespace Ui {
class MorseConverterGUI;
}

class MorseConverterGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MorseConverterGUI(QWidget *parent = 0);
    ~MorseConverterGUI();

private slots:
    void translate();
    void saveFile();
    void loadFile();


private:
    Ui::MorseConverterGUI *ui;

    void connectSignalAndSlots();

};

#endif // MORSECONVERTERGUI_H
