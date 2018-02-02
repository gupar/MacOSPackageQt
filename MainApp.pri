PROJECT_BINDIR          = $$PWD/OutDir
PROJECT_3RD_INCLUDE_DIR = $$PWD/3rdParty/include
PROJECT_3RD_LIB_DIR     = $$PWD/Lib
PROJECT_3RD_SRC_DIR     = $$PWD/Src

PROJECT_MOC_DIR         = $$PWD/IntDir/$$TARGET/moc/
PROJECT_OBJ_DIR         = $$PWD/IntDir/$$TARGET/


CONFIG += c++11 precompile_header


UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
INCLUDEPATH += ./GeneratedFiles \
    $(NEWCOM)Include

CONFIG(debug, debug|release) {
    DESTDIR = $$PROJECT_BINDIR/Debug
    OBJECTS_DIR =$$PROJECT_OBJ_DIR/Debug
    MOC_DIR = ./GeneratedFiles/Debug
    LIBS += -L$$DESTDIR
    INCLUDEPATH +=./GeneratedFiles/Debug
} else {
    DESTDIR = $$PROJECT_BINDIR/Release
    OBJECTS_DIR =$$PROJECT_OBJ_DIR/Release
    MOC_DIR = ./GeneratedFiles/Release
    LIBS += -L$$DESTDIR
    INCLUDEPATH +=./GeneratedFiles/Release
}

