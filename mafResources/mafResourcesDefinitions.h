/*
 *  mafResourcesDefinitions.h
 *  mafResources
 *
 *  Created by Roberto Mucci on 30/12/09.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#ifndef MAFRESOURCESDEFINITIONS_H
#define MAFRESOURCESDEFINITIONS_H

#define degreesToRadiant(x) (M_PI * (x) / (double)180.0)
#define radiantToDegrees(x) ((x) * (double)180.0/M_PI)

// Includes list
#include "mafResources_global.h"
#include <qmath.h>
#include <QUrl>
#include <mafCoreDefinitions.h>
#include <mafEventBusManager.h>
#include <mafCoreSingletons.h>
#include <mafObject.h>
#include <mafHierarchy.h>


// vnl includes
#include <vnl/vnl_double_4x4.h>
#include <vnl/vnl_vector_fixed.h>


namespace mafResources {

#define mafUrl QUrl

class mafDataSet;
class mafDataSetCollection;
class mafResource;
class mafVME;

/// Type definition for MAF3 pose matrix.
typedef vnl_double_4x4 mafPoseMatrix;

/// Type definition for a list of mafResource.
typedef mafList<mafResource *> mafResourceList;

/// Time varying data set map.
typedef mafMap<double, mafDataSet *> mafDataSetMap;

/// List of dataset used as input list for mafPipe.
typedef mafList<mafDataSet *> mafDataSetList; //to be removed?

/// List of VME used as input list for mafPipe.
typedef mafList<mafVME *> mafVMEList;

/** Structure representing the information about a plug-in library.*/
struct MAFRESOURCESSHARED_EXPORT mafPluginInfo {
    float m_Version;            ///< Plug-in Version
    mafString m_PluginName;     ///< Plug-in name
    mafString m_Author;         ///< Plug-in author
    mafString m_Vendor;         ///< Plug-in company name
    mafString m_VendorHomepage; ///< Plug-in company homepage
    mafString m_Description;    ///< Plug-in general description.
};

/// Hash of plugged objects coming from plig-ins.
//typedef mafHash<mafString, mafCore::mafPluggedObjectInformation> mafPluggedObjectsHash;

///< Enumeration that define the Cartesian Axis.
enum {
    X_AXIS = 0,
    Y_AXIS,
    Z_AXIS
};

/// Enumeration that define the operation type.
typedef enum {
    mafOperationTypeImporter = 0,
    mafOperationTypeExporter,
    mafOperationTypeOperation
} mafOperationType;

}

#endif // MAFRESOURCESDEFINITIONS_H
