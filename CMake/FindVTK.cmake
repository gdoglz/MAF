#
#  FindVTK.cmake
#  maf
#
#  Created by Daniele Giunchi - Paolo Quadrani on 10/09/10.
#  Copyright 2009 B3C. All rights reserved.
#
#  See Licence at: http://tiny.cc/QXJ4D
#
#

SET(VTK_DIR "$ENV{MAF3_FOUNDATION_LIB_DIR}/vtk-5.6/")
INCLUDE_DIRECTORIES("${VTK_DIR}/include/")
LINK_DIRECTORIES(${LINK_DIRECTORIES} "${VTK_DIR}/lib/")

SET(VTK_LIBRARY )
SET(VTK_LIBRARY_TEMP "MapReduceMPI"
 "mpistubs"
 "QVTK"
 "vtkQtChart"
 "vtkCharts"
 "vtkCommon"
 "vtkDICOMParser"
 "vtkFiltering"
 "vtkfreetype"
 "vtkGenericFiltering"
 "vtkGeovis"
 "vtkGraphics"
 "vtkHybrid"
 "vtkIO"
 "vtkImaging"
 "vtkInfovis"
 "vtkNetCDF"
 "vtkRendering"
 "vtkViews"
 "vtkVolumeRendering"
 "vtkWidgets"
 "vtkalglib"
 "vtkexoIIc"
 "vtkexpat"
 "vtkfreetype"
 "vtkftgl"
 "vtkjpeg"
 "vtklibxml2"
 "vtkmetaio"
 "vtkpng"
 "vtkproj4"
 "vtksqlite"
 "vtksys"
 "vtktiff"
 "vtkverdict"
 "vtkzlib" )
 
IF(CMAKE_BUILD_TYPE MATCHES Debug)
    if(WIN32)
      FOREACH(target_library ${VTK_LIBRARY_TEMP})
         LIST(APPEND VTK_LIBRARY "${target_library}_d")
      ENDFOREACH(target_library ${VTK_LIBRARY_TEMP})
    endif(WIN32)
    
ELSE(CMAKE_BUILD_TYPE MATCHES Debug)
    SET(VTK_LIBRARY ${VTK_LIBRARY_TEMP})
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

SET(VTK_FOUND TRUE)    

