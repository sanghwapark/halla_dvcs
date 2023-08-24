cmake_minimum_required(VERSION 3.5)

PROJECT(ARSWAVE)
	
SET(ARSWAVE_LIB arswave)
SET(PROJ_DIR ${PROJECT_SOURCE_DIR})

SET(ARSWAVE_ROOTMAP ${CMAKE_CURRENT_BINARY_DIR}/libarswave_rdict.pcm ${CMAKE_CURRENT_BINARY_DIR}/libarswave.rootmap)

IF( NOT CMAKE_BUILD_TYPE )
    SET( CMAKE_BUILD_TYPE Debug )
ENDIF()

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

# ROOT
FIND_PACKAGE(ROOT 6.0.0 REQUIRED)
INCLUDE(${ROOT_USE_FILE})

INCLUDE_DIRECTORIES(${PROJ_DIR}/include)
SET(SRC_DIR ${PROJ_DIR}/source)

SET( CMAKE_CXX_FLAGS "-g -Wall -fPIC -Wno-misleading-indentation" )

ROOT_GENERATE_DICTIONARY(G__arswave TARSBase.h TARSArray.h TARSConst.h TARSParameters.h TARSCalibration.h TARSBlock.h TARSWave.h TDVCSDB.h TDoubleArray.h TARSWave2.h LINKDEF include/TARSWaveLinkDef.h)

ADD_LIBRARY(${ARSWAVE_LIB} SHARED source/TARSArray.cxx source/TARSBase.cxx source/TARSBlock.cxx source/TARSCalibration.cxx source/TARSConst.cxx  source/TARSParameters.cxx source/TDoubleArray.cxx source/TDVCSDB.cxx source/TARSWave.cxx source/TARSWave2.cxx G__arswave.cxx)

TARGET_LINK_LIBRARIES(${ARSWAVE_LIB} ${ROOT_LIBRARIES})

INSTALL(TARGETS ${ARSWAVE_LIB} DESTINATION lib)
INSTALL(FILES ${ARSWAVE_ROOTMAP} DESTINATION lib)
