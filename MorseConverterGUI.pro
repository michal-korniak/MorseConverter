#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T16:38:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MorseConverterGUI
TEMPLATE = app


SOURCES += main.cpp\
        morseconvertergui.cpp \
    morseconverter.cpp

HEADERS  += morseconvertergui.h \
    morseconverter.h

FORMS    += morseconvertergui.ui
CONFIG += c++11
