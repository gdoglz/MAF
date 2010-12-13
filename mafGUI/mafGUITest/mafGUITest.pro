# -------------------------------------------------
# Project created by QtCreator 2009-10-26T18:49:18
# -------------------------------------------------
CONFIG += uitools
CONFIG += qtestlib
CONFIG += link_prl
CONFIG -= app_bundle
SOURCES += main.cpp \
    mafGUIManagerTest.cpp \
    mafUILoaderTest.cpp \
    mafUILoaderQtTest.cpp
include(../../mafInstallTest.pri)
include(../../mafImportQXMLRPC.pri)
include(../../mafImportQtSoap.pri)

# Foundation libraries dependencies
INCLUDEPATH += ../../mafEventBus \
    ../../mafCore
LIBS += -L$$DESTDIR \
    -lmafEventBus$$BUILD_EXT \
    -lmafCore$$BUILD_EXT \
    -lmafGUI$$BUILD_EXT

win32:system(copy testUIFile.ui $$DESTDIR)
unix:system(cp testUIFile.ui $$DESTDIR/)
