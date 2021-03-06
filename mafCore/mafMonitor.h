/*
 *  mafMonitor.h
 *  mafCore
 *
 *  Created by Daniele Giunchi on 30/12/09.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#ifndef MAFMONITOR_H
#define MAFMONITOR_H

// Includes list
#include "mafObjectBase.h"

namespace mafCore {

// Class forwarding list

/**
Class name: mafMonitor
This class defines the interface class for MAF3 Monitors.
*/
class MAFCORESHARED_EXPORT mafMonitor : public mafObjectBase {
    Q_OBJECT
    /// typedef macro.
    mafSuperclassMacro(mafCore::mafObjectBase);

public:
    /// Object constructor.
    mafMonitor(const mafString code_location = "");

    /// update space variables
    virtual void update() = 0;

    /// Return the monitor's results.
    mafString *resultBuffer();

protected:
    mafString m_ResultBuffer; ///< String buffer in which save the whole monitor result values.
};


/////////////////////////////////////////////////////////////
// Inline methods
/////////////////////////////////////////////////////////////

inline mafString *mafMonitor::resultBuffer() {
    return &m_ResultBuffer;
}

} // namespace mafCore

#endif // MAFMONITOR_H
