#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T10:53:28
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = TestApp
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

LIBS += -lDynLib

mac{
        QT += macextras
}

include(../../MainApp.pri)
