/*
 *  mafLoggerTest.cpp
 *  mafCoreTest
 *
 *  Created by Paolo Quadrani on 27/03/09.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#include <mafTestSuite.h>
#include <mafLoggerFile.h>

#include <QFileInfo>

using namespace mafCore;

/**
 Class name: mafLoggerFileTest
 This class implements the test suite for mafLoggerFile.
 */

//! <title>
//mafLoggerFile
//! </title>
//! <description>
//mafLoggerFile defines the MAF3 logging class that will store messages into a file
//on filesystem. It creates a temporary file into a temporary directory and redifine
//"virtual void loggedMessage(mafMsgType type, mafString &msg)" used to write the given
//message into the temporary file created.
//! </description>

class mafLoggerFileTest : public QObject {
    Q_OBJECT

private slots:
    /// Initialize test variables
    void initTestCase() {
        mafMessageHandler::instance()->installMessageHandler();
        //! <snippet>
        m_Logger = mafNEW(mafCore::mafLoggerFile);
        m_DefaultLogger = mafMessageHandler::instance()->activeLogger();
        mafMessageHandler::instance()->setActiveLogger(m_Logger);
        //! </snippet>
    }

    /// Cleanup tes variables memory allocation.
    void cleanupTestCase() {
        mafMessageHandler::instance()->setActiveLogger(m_DefaultLogger);
        delete m_Logger;
    }

    /// create new object and check that is not NULL test case.
    void mafLoggerFileConstructorTest();

    /// test for the clearBuffer method.
    void clearLogHistoryTest();

    /// log a string into the log file.
    void logMesageTest();

private:
    mafLoggerFile *m_Logger; ///< Test variable
    mafLogger *m_DefaultLogger;
};

void mafLoggerFileTest::mafLoggerFileConstructorTest() {
    QVERIFY(m_Logger != NULL);
    mafString log_file = m_Logger->lastLogFile();
    QVERIFY(QFile::exists(log_file));
}

void mafLoggerFileTest::logMesageTest() {
    mafString log_file = m_Logger->lastLogFile();
    QFileInfo fInfo(log_file);
    QVERIFY(fInfo.size() == 0); // Empty file at begin.

    //! <snippet>
    mafString msg("Test for mafLoggerFile");
    m_Logger->logMessage(mafMsgTypeDebug, msg);
    //! </snippet>

//    QVERIFY(fInfo.size() > 0); // Cannot be verified because the
                                 // file is flushed only when the logger is destroyed.
                                 // I checked the correctness of the file writing manually
                                 // by looking at the file when the test ends :)
}

void mafLoggerFileTest::clearLogHistoryTest() {
    mafString log_file = m_Logger->lastLogFile();
    m_Logger->clearLogHistory();

    QVERIFY(!QFile::exists(log_file)); // Should not exists; after clear the old file is deleted.

    // Get the new log filename (after the clearLogHistory call
    // it has been changed)
    log_file = m_Logger->lastLogFile();
    QVERIFY(QFile::exists(log_file)); // Should exists.
}

MAF_REGISTER_TEST(mafLoggerFileTest);
#include "mafLoggerFileTest.moc"
