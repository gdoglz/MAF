/*
 *  mafObjectFactoryTest.cpp
 *  mafCoreTest
 *
 *  Created by Paolo Quadrani on 22/09/09.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#include <mafTestSuite.h>
#include <mafObjectBase.h>
#include <mafObject.h>
#include <mafSmartPointer.h>

using namespace mafCore;

/**
 Class name: mafObjectFactoryTest
 This class implements the test suite for mafObjectFactory.
 */

//! <title>
//mafObjectFactory
//! </title>
//! <description>
//mafObjectFactory represent the factory for all the MAF3 objects.
//Objects are instantiated by calling the static method CreateObject and passing as argument the typename of the object to create.
//! </description>

class mafObjectFactoryTest : public QObject {
    Q_OBJECT

private slots:
    /// Initialize test variables
    void initTestCase() {
        mafMessageHandler::instance()->installMessageHandler();
    }

    /// Cleanup tes variables memory allocation.
    void cleanupTestCase() {
    }

    /// register new object in factory test case.
    void registerObjectTest();

    /// create object instance test case.
    void instantiateObjectTest();

    /// create object instance test case (return the base type).
    void instantiateObjectBaseTest();

    /// unregister object test case.
    void unregisterObjectTest();

    /// smart pointer creation test case.
    void instantiateSmartObjectTest();

private:
};

void mafObjectFactoryTest::registerObjectTest() {    
    mafUnregisterObject(mafCore::mafObjectBase);
    // Not registered object should not be present in factory.
    bool res = mafObjectFactory::instance()->isObjectRegistered("mafCore::mafObjectBase");

    QVERIFY(res == false);

    // Register mafObjectBase.
    //! <snippet>
    mafRegisterObject(mafCore::mafObjectBase);
    //! </snippet>
    // Now mafObjectBase is present into the factory.
    //! <snippet>
    res = mafObjectFactory::instance()->isObjectRegistered("mafCore::mafObjectBase");
    //! </snippet>
    QVERIFY(res == true);
}

void mafObjectFactoryTest::instantiateObjectTest() {
    // registered object.
    mafObjectBase *obj_base = mafNEW(mafCore::mafObjectBase);
    QVERIFY(obj_base != NULL);
    delete obj_base;
}

void mafObjectFactoryTest::instantiateObjectBaseTest() {
    mafRegisterObject(mafCore::mafObject);
    mafObjectBase *obj = mafNEWFromString("mafCore::mafObject");
    QVERIFY(obj != NULL);
    mafString cn = obj->metaObject()->className();
    QVERIFY(cn == "mafCore::mafObject");
    delete obj;
}

void mafObjectFactoryTest::unregisterObjectTest() {
    mafUnregisterObject(mafCore::mafObjectBase);
    bool res = mafObjectFactory::instance()->isObjectRegistered("mafCore::mafObjectBase");
    QVERIFY(res == false);
}

void mafObjectFactoryTest::instantiateSmartObjectTest() {
    // Register again mafObjectBase (previous test case unregistered it).
    mafRegisterObject(mafCore::mafObjectBase);
    mafSmartPointer<mafObjectBase> obj = mafCreateSmartObject(mafCore::mafObjectBase);
    QVERIFY(obj.isNull() == false);
}

MAF_REGISTER_TEST(mafObjectFactoryTest);
#include "mafObjectFactoryTest.moc"
