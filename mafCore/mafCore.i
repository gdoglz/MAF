/*
 *  mafCore.i
 *
 *  Created by Paolo Quadrani - Daniele Giunchi on 27/03/09.
 *  Copyright 2009 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#ifndef MAFCORE_I
#define MAFCORE_I

%module mafCore
%include "carrays.i"
%array_class(double, doubleArray);
%{
#include <QtDebug>
#include <QtCore>

#include <mafCoreDefinitions.h>
#include <mafObjectBase.h>
%}


#pragma SWIG nowarn=389, 401, 509, 801, 472

#undef Q_OBJECT
#undef signals
#undef slots

#define Q_OBJECT
#define signals public
#define slots

#undef  Q_PROPERTY(Type type MODE mode)
#define Q_PROPERTY(Type type MODE mode)

#undef  Q_DECLARE_INTERFACE(IFace, IId)
#define Q_DECLARE_INTERFACE(IFace, IId)

#undef  Q_DECLARE_METATYPE(Type type)
#define Q_DECLARE_METATYPE(Type type)

#undef  MAFCORESHARED_EXPORT
#define MAFCORESHARED_EXPORT

%ignore operator>>;
%ignore operator<<;
%ignore operator==;
%ignore operator[];
%ignore operator!=;
%ignore operator*=;
%ignore operator/=;
%ignore operator bool;
%ignore operator int;
%ignore operator float;
%ignore operator double;
%ignore operator double *;


//%ignore function(type parameter);

%ignore modifiedObject();


#ifdef SWIGPYTHON

%typecheck(SWIG_TYPECHECK_STRING) char * {
  $1 = PyString_Check($input) ? 1 : 0;
}

%typemap(typecheck) QString = char *;

%typemap(in) QString { // Python -> C++
    if (PyString_Check($input)) {
         $1 = QString(PyString_AsString($input));
     } else {
         qDebug("QString expected");
     }
}

%typemap(out) QString { // C++ -> Python
    $result = PyString_FromString($1.toAscii().constData());
}

#elif SWIGTCL

%typemap(in) QString { // Tcl -> C++
    $1 = QString(Tcl_GetString($input));
}

%typemap(out) QString { // C++ -> Tcl
    Tcl_SetStringObj($result, $1.toAscii().constData(), $1.size());
}

#endif

%include <mafCoreDefinitions.h>
%include <mafObjectBase.h>

#ifdef SWIGPYTHON

#endif

#endif
