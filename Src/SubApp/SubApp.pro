#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T10:53:28
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = SubApp
TEMPLATE = app

RECOMPILED_HEADER = stdafx.h

SOURCES += main.cpp\
        widget.cpp \
        stdafx.cpp

HEADERS  += widget.h \
        stdafx.h

FORMS    += widget.ui

mac{
        QT += macextras
}


include(../../MainApp.pri)
