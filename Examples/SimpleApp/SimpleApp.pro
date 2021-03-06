# -------------------------------------------------
# Project created by QtCreator 2010-09-21T13:47:18
# -------------------------------------------------
QT += webkit \
    network
TARGET = SimpleApp
TEMPLATE = app
CONFIG += uitools

# Removing the line below, uncomment the post link instruction at the end
CONFIG -= app_bundle
SOURCES += main.cpp \
    mafMainWindow.cpp \
    googlechat.cpp \
    mafOperationSimpleApp.cpp
HEADERS += mafMainWindow.h \
    googlechat.h \
    mafOperationSimpleApp.h
FORMS += mafMainWindow.ui \
    form.ui
include(../../mafCommon.pri)
include(../../mafImportVTK.pri)
include(../../mafImportVXL.pri)
include(../../mafImportQXMLRPC.pri)
include(../../mafImportQtSoap.pri)
DEPENDPATH += $$DESTDIR
INCLUDEPATH += ../../mafCore \
    ../../mafEventBus \
    ../../mafApplicationLogic \
    ../../mafResources \
    ../../mafGUI
LIBS += -L$$DESTDIR \
    -lmafCore$$BUILD_EXT \
    -lmafEventBus$$BUILD_EXT \
    -lmafResources$$BUILD_EXT \
    -lmafApplicationLogic$$BUILD_EXT \
    -lmafGUI$$BUILD_EXT
RESOURCES += mafAppImages.qrc
