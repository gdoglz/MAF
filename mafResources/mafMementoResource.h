/*
 *  mafMementoResource.h
 *  mafResources
 *
 *  Created by Roberto Mucci on 27/03/09.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#ifndef MAFMEMENTORESOURCE_H
#define MAFMEMENTORESOURCE_H

// Includes list
#include "mafResourcesDefinitions.h"
#include <mafMemento.h>

namespace mafResources {

// Class forwarding list
class mafResource;

/**
Class name: mafMementoResource
This class defines the MAF3 base resource for storing a mafResource state.
 This can be used to restore a previous stored resource state (undo mechanism or serialization porpouses).
 @sa mafCore::mafMemento
*/
class MAFRESOURCESSHARED_EXPORT mafMementoResource : public mafCore::mafMemento {
    Q_OBJECT
    /// typedef macro.
    mafSuperclassMacro(mafCore::mafMemento);

public:
    /// object constructor.
    mafMementoResource(const mafString code_location = "");
    /// object overloaded constructor.
    mafMementoResource(const mafCore::mafObject *obj, const mafResourceList *inputList, const mafString code_location = "");

private:
    friend class mafResource;
};

} //mafResources
#endif // MAFMEMENTORESOURCE_H
