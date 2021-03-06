/*
 *  mafLogicTest.cpp
 *  mafLogicTest
 *
 *  Created by Paolo Quadrani on 12/11/10.
 *  Copyright 2010 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#include "mafTestSuite.h"
#include <mafLogic.h>
#include <mafCoreSingletons.h>
#include <mafObject.h>

using namespace mafCore;
using namespace mafApplicationLogic;
using namespace mafEventBus;

//----------------------------------------------------------------------

/**
 Class name: testObjectCustomPlugged
 Test class used to test mafLogic::plugObject method.
 */
class testObjectCustomPlugged : public mafObject {
    /// Typedef macro
    mafSuperclassMacro(mafCore::mafObject);

public:
    testObjectCustomPlugged(const mafString code_location = "");

};

testObjectCustomPlugged::testObjectCustomPlugged(mafString code_location) : mafObject(code_location) {
}
//----------------------------------------------------------------------

/**
 Class name: mafLogicTest
 This class implements the test suite for mafLogic.
 */
class mafLogicTest : public QObject {
    Q_OBJECT

private slots:
    /// Initialize test variables
    void initTestCase() {
        // Calls needed to initialize settings' information.
        qApp->setOrganizationName("SCS");
        qApp->setOrganizationDomain("scsolutions.org");
        qApp->setApplicationName("mafApplicationLogicTest");
        // Create the instance of mafLogic.
        m_Logic = mafNEW(mafApplicationLogic::mafLogic);
    }

    /// Cleanup tes variables memory allocation.
    void cleanupTestCase() {
        mafDEL(m_Logic);
    }

    /// Check the existence of the mafLogic allocation.
    void mafLogicAllocationTest();

    /// Test the initialization of the mafLogic
    void initializeTest();

    /// Test the working directory accessors.
    void workingDirectoryTest();

    /// Test the plugObject functionality.
    void plugObjectTest();

private:
    mafLogic *m_Logic; ///< Test variable.
};

void mafLogicTest::mafLogicAllocationTest() {
    QVERIFY(m_Logic != NULL);
}

void mafLogicTest::initializeTest() {
    bool result = m_Logic->initialize();
    QVERIFY(result);
}

void mafLogicTest::workingDirectoryTest() {
    mafString res = QDir::toNativeSeparators("/myBaseDir/myDir1/myDir2/");
    m_Logic->setWorkingDirectory("/myBaseDir/myDir1/myDir2/");
    mafString wd = m_Logic->workingDirectory();
    QCOMPARE(wd, res);
    m_Logic->setWorkingDirectory("\\myBaseDir\\myDir1\\myDir2\\");
    wd = m_Logic->workingDirectory();
    QCOMPARE(wd, res);
    m_Logic->setWorkingDirectory("/myBaseDir\\myDir1\\myDir2/");
    wd = m_Logic->workingDirectory();
    QCOMPARE(wd, res);
    m_Logic->setWorkingDirectory("/myBaseDir/myDir1");
    wd = m_Logic->workingDirectory();
    QVERIFY(res != wd);
}

void mafLogicTest::plugObjectTest() {
    // Plug the custom object; it will be added to the plugin manager and available into the framework
    m_Logic->plugObject("mafCore::mafObject", "testObjectCustomPlugged", "Custom Object");
    m_Logic->loadPlugins();

    // Query for the plugged object, so to verify the functionality.
    mafEventArgumentsList argList;
    mafString baseClassType("mafCore::mafObject");
    argList.append(mafEventArgument(mafString, baseClassType));
    mafPluggedObjectInformationList *pluggedObjectList = NULL;
    mafGenericReturnArgument ret_val = mafEventReturnArgument(mafCore::mafPluggedObjectInformationList *, pluggedObjectList);
    mafEventBusManager::instance()->notifyEvent("maf.local.resources.plugin.resourcesQuery", mafEventTypeLocal, &argList, &ret_val);

    QVERIFY(pluggedObjectList != NULL);
    int num = pluggedObjectList->size();
    QVERIFY(num == 1);
    mafPluggedObjectInformation info = pluggedObjectList->at(0);
    mafString ct = info.m_ClassType;
    QVERIFY(ct == "testObjectCustomPlugged");
}

MAF_REGISTER_TEST(mafLogicTest);
#include "mafLogicTest.moc"
