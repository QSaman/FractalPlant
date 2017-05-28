#-------------------------------------------------
#
# Project created by QtCreator 2013-09-26T23:12:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FractalPlantApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fractalplant.cpp \
    fractalframe.cpp \
    canvasframe.cpp

HEADERS  += mainwindow.h \
    my_global.h \
    fractalplant.h \
    fractalframe.h \
    canvasframe.h

FORMS    += mainwindow.ui
