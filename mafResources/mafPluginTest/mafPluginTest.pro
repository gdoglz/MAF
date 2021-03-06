# -------------------------------------------------
# Project created by QtCreator 2010-02-15T12:35:58
# -------------------------------------------------
QT -= gui
TARGET = mafPluginTest
TEMPLATE = lib
CONFIG += create_prl
CONFIG += link_prl
win32:CONFIG += dll
DEFINES += MAFPLUGIN_TEST
SOURCES += mafDataPipeSurfacePluginTest.cpp \
    mafPluginRegistrator.cpp
HEADERS += mafPluginTest_global.h \
    mafPluginTestDefinitions.h \
    mafDataPipeSurfacePluginTest.h \
    mafPluginRegistrator.h
include(../../mafInstallTest.pri)
include(../../mafImportVXL.pri)
INCLUDEPATH += ../../mafResources \
                        ../../mafEventBus \
                        ../../mafCore
LIBS += -L$$DESTDIR \
    -lmafResources$$BUILD_EXT -lmafEventBus$$BUILD_EXT -lmafCore$$BUILD_EXT

#QMAKE_EXTENSION_SHLIB = mafplugin
win32:QMAKE_POST_LINK += $$CP_CMD $$DESTDIR\\$${LIB_PREFIX}$${TARGET}.dll $$DESTDIR\\$${LIB_PREFIX}$${TARGET}.mafplugin
!macx:unix:QMAKE_POST_LINK += $$CP_CMD $$DESTDIR/$${LIB_PREFIX}$${TARGET}.so.1.0.0 $$DESTDIR/$${LIB_PREFIX}$${TARGET}.mafplugin
macx:QMAKE_POST_LINK += $$CP_CMD $$DESTDIR/$${LIB_PREFIX}$${TARGET}.1.0.0.dylib $$DESTDIR/$${LIB_PREFIX}$${TARGET}.mafplugin
