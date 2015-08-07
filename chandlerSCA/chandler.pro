#-------------------------------------------------
#
# Project created by QtCreator 2015-06-29T12:20:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = chandlerSCA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    codeeditor.cpp \
    highlighter.cpp \
    slotsautodescribe.cpp

HEADERS  += mainwindow.h \
    codeeditor.h \
    highlighter.h \
    slotsautodescribe.h

FORMS    += mainwindow.ui \
    slotsautodescribe.ui
