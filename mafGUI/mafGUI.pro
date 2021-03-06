# -------------------------------------------------
# Project created by QtCreator 2010-10-26T11:13:20
# -------------------------------------------------
TARGET = mafGUI
TEMPLATE = lib
CONFIG += uitools
win32:CONFIG += dll
DEFINES += mafGUI_EXPORTS
SOURCES += mafGUIManager.cpp \
    mafGUIRegistration.cpp \
    mafUILoader.cpp \
    mafUILoaderQt.cpp \
    mafTreeModel.cpp \
    mafTreeItem.cpp \
    mafTreeWidget.cpp \
    mafMdiSubWindow.cpp \
    mafTextEditWidget.cpp \
    mafTextHighlighter.cpp
HEADERS += mafGUI_global.h \
    mafGUIManager.h \
    mafGUIRegistration.h \
    mafGUIDefinitions.h \
    mafUILoader.h \
    mafUILoaderQt.h \
    mafTreeModel.h \
    mafTreeItem.h \
    mafTreeWidget.h \
    mafMdiSubWindow.h \
    mafTextEditWidget.h \
    mafTextHighlighter.h
include(../mafInstallModule.pri)
INCLUDEPATH += ../mafCore \
    ../mafEventBus \
    ../mafApplicationLogic
LIBS += -L$$DESTDIR \
    -lmafCore$$BUILD_EXT \
    -lmafEventBus$$BUILD_EXT \
    -lmafApplicationLogic$$BUILD_EXT
RESOURCES += mafAppImages.qrc
FORMS += 
