# -------------------------------------------------
# Project created by QtCreator 2009-11-09T12:51:13
# -------------------------------------------------
QT += network
QT += xml
DEFINES += EXCLUDE_SINGLETONS
CONFIG += qtestlib
CONFIG += link_prl
SOURCES += main.cpp \
    mafEventBusManagerTest.cpp \
    mafNetworkConnectorTest.cpp \
    mafEventDispatcherLocalTest.cpp \
    mafEventDispatcherRemoteTest.cpp \
    mafEventDispatcherTest.cpp \
    mafNetworkConnectorQtSoapTest.cpp \
    mafNetworkConnectorQXMLRPCTest.cpp \
    mafEventTest.cpp
include(../../mafInstallTest.pri)
include(../../mafImportQXMLRPC.pri)
include(../../mafImportQtSoap.pri)
INCLUDEPATH += ../../mafCore
LIBS += -L$$DESTDIR \
    -lmafEventBus$$BUILD_EXT -lmafCore$$BUILD_EXT
