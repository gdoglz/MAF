/*
 *  mafTreeItem.h
 *  mafGUI
 *
 *  Created by Daniele Giunchi on 26/10/10.
 *  Copyright 2010 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#ifndef MAFTREEITEM_H
#define MAFTREEITEM_H

// Includes list
#include "mafGUIDefinitions.h"
#include <QStandardItem>

namespace mafGUI {

/**
Class Name: mafTreeItem
It represents the single item inside the mafTreeModel, it contains a QObject, and set initially the state
(checked or not) because it will be visualized by a Tree View or a List View.
*/
class MAFGUISHARED_EXPORT mafTreeItem : public QStandardItem
{
public:
    /// Object constructor.
    mafTreeItem(QObject *obj, bool done = false);
    /// Retrieve the current data inside the item
    QObject *data() const { return m_Data; }

private:
    QObject * m_Data; ///< variable which point to the data inside item
};

} // end namespace
#endif // MAFTREEITEM_H
