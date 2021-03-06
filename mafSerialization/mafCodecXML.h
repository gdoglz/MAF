/*
 *  mafCodecXML.h
 *  mafSerialization
 *
 *  Created by Daniele Giunchi on 19/01/10.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#ifndef MAFCODECXML_H
#define MAFCODECXML_H

// Includes list
#include "mafCodec.h"

namespace mafSerialization {


/**
 Class name: mafCodecXML
 Codec to Encode/Decode maf objects into XML structure.
 @sa mafCodec, mafSerializationManager
 */
class MAFSERIALIZATIONSHARED_EXPORT mafCodecXML : public mafCodec {
    Q_OBJECT
    /// typedef macro.
    mafSuperclassMacro(mafCodec);

public:
    /// Object constructor.
    mafCodecXML(const mafString code_location = "");

    /// Object destructor.
    ~mafCodecXML();

    /// Encode the memento into the output type.
    /*virtual*/ void encode(mafCore::mafMemento *memento);

    /// Decode the output type into the memento.
    /*virtual*/ mafCore::mafMemento *decode();

private:
    /// marshalling of QVariant data type in order to write the correct type.
    void marshall(const QVariant &value );

    /// unmarshalling of QVariant data type in order to write the correct type.
    mafVariant demarshall( const mafDomElement &elem );

    mafCore::mafMementoPropertyItem setPropertyItem(mafDomElement eChild);

    mafXmlStreamWriter m_XMLStreamWriter; ///

    mafDomDocument m_XMLDocument;
    mafDomNode m_CurrentNode;

    int m_MementoLevel; ///
    bool m_Valid;
};


} // mafSerialization

#endif //MAFCODECXML_H
