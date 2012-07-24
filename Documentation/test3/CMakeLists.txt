cmake_minimum_required(VERSION 2.6)
 



FIND_PACKAGE(DGtal REQUIRED)
INCLUDE_DIRECTORIES(${DGTAL_INCLUDE_DIRS})
LINK_DIRECTORIES(${DGTAL_LIBRARY_DIRS})


if(WIN32)
	set(CMAKE_MODULE_PATH "$ENV{OGRE_HOME}/CMake/;${CMAKE_MODULE_PATH}")
endif(WIN32)
 

if(UNIX AND NOT APPLE)

	if(EXISTS "/usr/local/lib/OGRE/cmake")
	  	set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
	 elseif(EXISTS "/usr/share/OGRE/cmake")
	     set(CMAKE_MODULE_PATH "/usr/share/OGRE/cmake/modules;${CMAKE_MODULE_PATH}")
	   else ()
	     message(SEND_ERROR "Failed to find module path.")
	 endif(EXISTS "/usr/local/lib/OGRE/cmake")

 endif(UNIX AND NOT APPLE)



if(APPLE)
	if(EXISTS "/Applications/OgreSDK/CMake")
	  	set(CMAKE_MODULE_PATH "/Applications/OgreSDK/CMake/;${CMAKE_MODULE_PATH}")
	elseif(EXISTS "/usr/lib/OGRE/cmake/")
	  	set(CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
	else ()
	  	message(SEND_ERROR "Failed to find module path.")
	endif(EXISTS "/Applications/OgreSDK/CMake")
endif(APPLE)
 


if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()
 






IF(APPLE)
   #SET(GUI_TYPE MACOSX_BUNDLE)
   FIND_LIBRARY(CARBON_LIBRARY Carbon)
   FIND_LIBRARY(COCOA_LIBRARY Cocoa)
   FIND_LIBRARY(IOKIT_LIBRARY IOKit )
   FIND_LIBRARY(FOUNDATION_LIBRARY Foundation )
     MARK_AS_ADVANCED (CARBON_LIBRARY
COCOA_LIBRARY)
   SET(EXTRA_LIBS ${CARBON_LIBRARY} ${COCOA_LIBRARY}  ${IOKIT_LIBRARY} ${FOUNDATION_LIBRARY})
ENDIF (APPLE)



set(CMAKE_DEBUG_POSTFIX "_d")
 
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}")
 
find_package(OGRE REQUIRED)
 
find_package(OIS REQUIRED)
 
if(NOT OIS_FOUND)
	message(SEND_ERROR "Failed to find OIS.")
endif()
 

# Find Boost
if (NOT OGRE_BUILD_PLATFORM_IPHONE)
	if (WIN32 OR APPLE)
		set(Boost_USE_STATIC_LIBS TRUE)
	else ()
		# Statically linking boost to a dynamic Ogre build doesn't work on Linux 64bit
		set(Boost_USE_STATIC_LIBS ${OGRE_STATIC})
	endif ()
	if (MINGW)
		# this is probably a bug in CMake: the boost find module tries to look for
		# boost libraries with name libboost_*, but CMake already prefixes library
		# search names with "lib". This is the workaround.
		set(CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES} "")
	endif ()
	set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37" )
	# Components that need linking (NB does not include header-only components like bind)
	set(OGRE_BOOST_COMPONENTS thread date_time)
	find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	if (NOT Boost_FOUND)
		# Try again with the other type of libs
		set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
		find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	endif()
	find_package(Boost QUIET)
 
	# Set up referencing of Boost
	include_directories(${Boost_INCLUDE_DIR})
	add_definitions(-DBOOST_ALL_NO_LIB)
	set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
endif()
 
INCLUDE_DIRECTORIES("/home/stagiaire/Documents/DGtalViewer/tests/;${DGTAL_INCLUDE_DIRS}")
INCLUDE_DIRECTORIES("/home/stagiaire/Documents/DGtalViewer/;${DGTAL_INCLUDE_DIRS}")

set(HDRS /home/stagiaire/Documents/DGtalViewer/Functions.h
	 /home/stagiaire/Documents/DGtalViewer/Representation.h
         /home/stagiaire/Documents/DGtalViewer/DGtalNode.h
         /home/stagiaire/Documents/DGtalViewer/Ogre3DDisplayFactory.h
	 /home/stagiaire/Documents/DGtalViewer/mousecursor.h
	 /home/stagiaire/Documents/DGtalViewer/ViewerOgre3D.h
	 /home/stagiaire/Documents/DGtalViewer/InputListener.h
	 /home/stagiaire/Documents/DGtalViewer/CameraMan.h
	 /home/stagiaire/Documents/DGtalViewer/DrawableWithOgreWrapper.h
	 /home/stagiaire/Documents/DGtalViewer/DrawableWithOgre.h
)
 
set(SRCS /home/stagiaire/Documents/DGtalViewer/Representation.cpp 
         /home/stagiaire/Documents/DGtalViewer/DGtalNode.cpp 
         /home/stagiaire/Documents/DGtalViewer/mousecursor.cpp
	 /home/stagiaire/Documents/DGtalViewer/DrawableWithOgre.cpp
         /home/stagiaire/Documents/DGtalViewer/TextZone.cpp
)
 
include_directories( ${OIS_INCLUDE_DIRS}
	${OGRE_INCLUDE_DIRS}
	${OGRE_SAMPLES_INCLUDEPATH}
)


SET(DGTAL_TESTS_SRC
  testMode1
  )

FOREACH(FILE ${DGTAL_TESTS_SRC})
  add_executable(${FILE} ${FILE} ${HDRS}  ${GUI_TYPE} ${SRCS})
  target_link_libraries (${FILE} ${OGRE_LIBRARIES} ${OIS_LIBRARIES} ${DGTAL_LIBRARIES}  ${EXTRA_LIBS})
ENDFOREACH(FILE)

 
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

 
if(MINGW OR UNIX)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
endif(MINGW OR UNIX)
 

 

