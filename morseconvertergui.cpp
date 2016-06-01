#include "morseconvertergui.h"
#include "ui_morseconvertergui.h"
#include "morseconverter.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

MorseConverterGUI::MorseConverterGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MorseConverterGUI)
{
    ui->setupUi(this);
    connectSignalAndSlots();

}
MorseConverterGUI::~MorseConverterGUI()
{
    delete ui;
}
void MorseConverterGUI::connectSignalAndSlots()
{
    connect(ui->BtnTranslate,SIGNAL(clicked()),this,SLOT(translate()));
    connect(ui->actionLoad,SIGNAL(triggered()),this,SLOT(loadFile()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveFile()));
}
void MorseConverterGUI::translate()
{
    if(ui->CmbSelect->currentText()=="Text -> Morse")
    {
        QString output=MorseConverter::convertToMorse(ui->TxtLeft->toPlainText());
        ui->TxtRight->setPlainText(output);
    }
    else
    {
        QString output=MorseConverter::convertFromMorse(ui->TxtLeft->toPlainText());
        ui->TxtRight->setPlainText(output);
    }
}


void MorseConverterGUI::loadFile()
{
    QString dir=QFileDialog::getOpenFileName(this,"MorseConverter", QString(), "Text files (*.txt)");
    if(dir.isNull())
        return;
    QFile file(dir);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::about(this,"MorseConverter", "The file cannot be open!");
        return;
    }
    ui->TxtLeft->setPlainText(file.readAll());
}
void MorseConverterGUI::saveFile()
{
    QString dir=QFileDialog::getSaveFileName(this,"MorseConverter", QString(), "Text files (*.txt)");
    if(dir.isNull())
        return;
    QFile file(dir);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::about(this,"MorseConverter", "The file cannot be save!");
        return;
    }
    QTextStream fileStream(&file);
    fileStream<<ui->TxtRight->toPlainText();

}

