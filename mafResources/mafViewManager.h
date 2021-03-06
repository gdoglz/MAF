/*
 *  mafViewManager.h
 *  mafResources
 *
 *  Created by Paolo Quadrani on 30/12/09.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#ifndef MAFVIEWMANAGER_H
#define MAFVIEWMANAGER_H

#include "mafResourcesDefinitions.h"

namespace mafResources {

// Class forwarding list
class mafView;
class mafResource;
class mafVME;

/**
Class name: mafViewManager
This class provides the manager class for MAF3 views. The topics are:
- maf.local.resources.view.create allows to create a new View.
- maf.local.resources.view.created notify all the observers that a new View has been created.
- maf.local.resources.view.destroy allows to destroy a given View.
- maf.local.resources.view.select allows to select the active View on which show/hide VMEs.
- maf.local.resources.view.selected allows to retrieve the current selected View.
- maf.local.resources.view.show allow to show/hide a given VME in the selected View.
*/
class MAFRESOURCESSHARED_EXPORT mafViewManager : public mafCore::mafObjectBase {
    Q_OBJECT
    /// typedef macro.
    mafSuperclassMacro(mafCore::mafObjectBase);

public:
    /// Return an instance of the Manager
    static mafViewManager *instance();

    /// Destroy the singleton instance. To be called at the end of the application.
    void shutdown();

public slots:
    /// Create a memento class used to save the status of opened views. The caller has to delete the allocated memory he asked.
    /** This method allows to save the status of opened views when logic
    emits the signal maf.local.logic.settings.view.store.
    The manager save the number and types of opened views, their position and size.
    Then each view save its settings depending on the view itselfs.*/
    mafCore::mafMemento *createMemento() const;

    /// Allows to rebuild a previous saved object's state.
    /**
    This is used to implement a sort of undo mechanism for the object's state, but can be used also by the
    serialization mechanism to serialize data into the selected storage type.
    The 'deep_memento' flag is used to avoid the copy of the object unique hash in normal operation like
    undo or copy/paste operations. The complete object save is instead needed for serialization pourposes.*/
    void setMemento(mafCore::mafMemento *memento, bool deep_memento = false);

signals:
    /// Return the selected view
    void selectedViewSignal(mafCore::mafObjectBase *view);

    /// Signal which allow to keep track of the selected view.
    void selectViewSignal(mafCore::mafObjectBase *view);

    /// Signal which allow to show/hide the given vme passed as argument.
    void vmeShowSignal(mafCore::mafObjectBase *vme, bool show = true);

    /// Signal which allow to remove the view from the manager.
    void destroyViewSignal(mafCore::mafObjectBase *view);

    /// Allow to cdreate a new mafView given the type name as string. Return the created view on success.
    void createViewSignal(mafString view_type);

    /// Notify the view creation to all observers.
    void viewCreatedSignal(mafCore::mafObjectBase *view);

private slots:
    /// Allow to keep track of the selected view.
    void selectView(mafCore::mafObjectBase *view);

    /// Allow to show/hide the given vme passed as argument.
    void vmeShow(mafCore::mafObjectBase *vme, bool show = true);

    /// Remove the view from the manager.
    void destroyView(mafCore::mafObjectBase *view);

    /// Allow to cdreate a new mafView given the type name as string. Return the pointer to the created view on success.
    void createView(mafString view_type);

    /// Method called when a view has been destroyed (by someone else).
    void viewDestroyed();

private:
    /// Object constructor.
    mafViewManager(const mafString code_location = "");

    /// Object destructor
    /*virtual*/ ~mafViewManager();

    /// create IDs and connect signals with slots for View create, destroy, select and VME show.
    void initializeConnections();

    /// Add the created view to the view list.
    void addViewToCreatedList(mafView *v);

    /// Remove the given view from the created list
    void removeView(mafView *view);

    /// Delete all created views
    void destroyAllViews();

    mafResourceList m_CreatedViewList; ///< List of created views.
    mafView *m_SelectedView; ///< Keep trak of the current selected view.
};

} // namespace mafResources

#endif // MAFVIEWMANAGER_H
