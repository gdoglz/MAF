/*
 *  mafGUIManagerTest.cpp
 *  mafGUITest
 *
 *  Created by Paolo Quadrani on 26/10/10.
 *  Copyright 2010 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#include <mafTestSuite.h>
#include <mafCoreSingletons.h>
#include <mafGUIRegistration.h>
#include <mafGUIManager.h>

using namespace mafCore;
using namespace mafGUI;

/**
 Class name: mafGUIManagerTest
 This class implements the test suite for mafGUIManager.
 */
class mafGUIManagerTest : public QObject {
    Q_OBJECT

private slots:
    /// Initialize test variables
    void initTestCase() {
        mafMessageHandler::instance()->installMessageHandler();
        // Register all the creatable objects for the mafGUI module.
        mafGUIRegistration::registerGUIObjects();
        m_GUIManager = mafNEW(mafGUI::mafGUIManager);
    }

    /// Cleanup test variables memory allocation.
    void cleanupTestCase() {
        mafDEL(m_GUIManager);
    }

    /// mafGUIManager allocation test case.
    void mafGUIManagerAllocationTest();

private:
    mafGUIManager *m_GUIManager; ///< Reference to the GUI Manager.
};

void mafGUIManagerTest::mafGUIManagerAllocationTest() {
    QVERIFY(m_GUIManager != NULL);
}

MAF_REGISTER_TEST(mafGUIManagerTest);
#include "mafGUIManagerTest.moc"
