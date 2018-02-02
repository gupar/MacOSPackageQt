#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T16:22:29
#
#-------------------------------------------------

QT       -= gui

TARGET = DynLib
TEMPLATE = lib

DEFINES += DYNLIB_LIBRARY

SOURCES += dynlib.cpp

HEADERS += dynlib.h\
        dynlib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(../../MainApp.pri)
