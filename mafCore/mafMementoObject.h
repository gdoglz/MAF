/*
 *  mafMementoObject.h
 *  mafCore
 *
 *  Created by Paolo Quadrani on 27/03/09.
 *  Copyright 2009 B3C. All rights reserved.
 *  
 *  See Licence at: http://tiny.cc/QXJ4D
 *  
 */

#ifndef MAFMEMENTOOBJECT_H
#define MAFMEMENTOOBJECT_H

// Includes list
#include "mafMemento.h"

namespace mafCore {

// Class forwarding list
class mafObject;

/**
 Class name: mafMementoObject
 This class defines the MAF3 base object for storing a mafObject state.
 This can be used to restore a previous stored object state (undo mechanism or serialization porpouses).
 */
class MAFCORESHARED_EXPORT mafMementoObject : public mafMemento {
    Q_OBJECT
    /// typedef macro.
    mafSuperclassMacro(mafCore::mafMemento);

public:
    /// ObjectMemento constructor.
    mafMementoObject(const mafString code_location = "");

    /// ObjectMemento overloaded constructor.
    mafMementoObject(const mafObject *obj, const mafTagList *tagList, mafDictionary *dic, const mafString code_location = "");

private:
    friend class mafObject;
};

} // mafCore

#endif // MAFMEMENTOOBJECT_H
