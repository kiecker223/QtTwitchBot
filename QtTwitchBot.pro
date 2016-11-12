#-------------------------------------------------
#
# Project created by QtCreator 2016-07-26T17:46:34
#
#-------------------------------------------------

QT       += core gui network opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TwitchBot
TEMPLATE = app

CONFIG -= console


SOURCES += main.cpp\
        MainWindow.cpp \
    QTwitchBot.cpp \
    TwitchBotDialog.cpp \
    CommandDialog.cpp \
    UserData.cpp

HEADERS  += MainWindow.h \
    QTwitchBot.h \
    TwitchBotDialog.h \
    CommandDialog.h \
    UserData.h

FORMS    += MainWindow.ui \
    CommandDialog.ui \
    TwitchBotDialog.ui \
    UserData.ui
