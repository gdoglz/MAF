/*
 *  mafCodec.h
 *  mafSerialization
 *
 *  Created by Paolo Quadrani on 14/12/09.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#ifndef MAFCODEC_H
#define MAFCODEC_H

// Includes list
#include "mafSerialization_global.h"

namespace mafSerialization {

/**
 Class name: mafCodec
 Base class that define the interface for MAF3 codec.
 @sa mafCodecRawBinary, mafSerializationManager
 */
class MAFSERIALIZATIONSHARED_EXPORT mafCodec : public mafCore::mafObjectBase {
    Q_OBJECT
    /// typedef macro.
    mafSuperclassMacro(mafCore::mafObjectBase);

public:
    /// Object constructor.
    mafCodec(const mafString code_location = "");

    /// Object destructor.
    /* virtual */ ~mafCodec() {}

    /// Return the codec output type
    const mafString encodingType();

    /// Encode the memento into the output type.
    virtual void encode(mafCore::mafMemento *memento) = 0;

    /// Decode the output type into the memento.
    virtual mafCore::mafMemento *decode() = 0;

    /// Set device used to interface the physical media.
    void setDevice(mafIODevice *d);

protected:
    mafString m_EncodingType; ///< Encoding type for the codec.
    mafIODevice *m_Device; ///< Media device.
    unsigned int m_Level; ///< Decoding level for compounded memento classes.
};

/////////////////////////////////////////////////////////////
// Inline methods
/////////////////////////////////////////////////////////////

inline const mafString mafCodec::encodingType() {
    return m_EncodingType;
}

inline void mafCodec::setDevice(mafIODevice *d) {
    m_Device = d;
}

} // namespace mafSerialization

#endif // MAFCODEC_H
