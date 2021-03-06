/*
 *  mafThreadTimer.h
 *  mafTimeSpace
 *
 *  Created by Daniele Giunchi on 27/03/09.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#ifndef MAFTHREADTIMER_H
#define MAFTHREADTIMER_H

// Includes list
#include "mafTimeSpace_global.h"
#include <mafObjectBase.h>

namespace mafTimeSpace {

// Class forwarding list
class mafTimer;

/**
 Class name: mafThreadedTimer
 This class provides a mafTimer associated with a specific thread.
 */
class MAFTIMESPACESHARED_EXPORT mafThreadedTimer : public mafCore::mafObjectBase {
    Q_OBJECT
    /// typedef macro.
    mafSuperclassMacro(mafCore::mafObjectBase);

public:
    /// Object constructor.
    mafThreadedTimer(const mafString code_location = "");

    /// Object constructor overloaded.
    mafThreadedTimer(mafTimer *timer, const mafString code_location = "");

    /// Object destructor.
    /* virtual */ ~mafThreadedTimer();

    /// Start the timer in the main thread.
    void start();

    /// Start the timer in the thread passed as parameter.
    void startOnThread(mafThread *thread);

    /// Stop the timer.
    void stop();

    /// Return if the timer is active.
    bool isActive() const;

private:
    mafTimer *m_Timer; ///< Timer variable which will be associated with Thread.
    mafThread *m_Thread; ///< Thread variable representing the thread on which Timer runs. If NULL it means the timer is running on the main thread.
};

} // namespace mafTimeSpace

#endif // MAFTHREADTIMER_H
