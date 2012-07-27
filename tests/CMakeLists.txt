cmake_minimum_required(VERSION 2.6)
 

FIND_PACKAGE(DGtal REQUIRED)
INCLUDE_DIRECTORIES(${DGTAL_INCLUDE_DIRS})
LINK_DIRECTORIES(${DGTAL_LIBRARY_DIRS})



if(WIN32)
	set(CMAKE_MODULE_PATH "$ENV{OGRE_HOME}/CMake/;${CMAKE_MODULE_PATH}")
endif(WIN32)
 

if(UNIX AND NOT APPLE)

if(NOT DEFINED OGRE_PLUGINS)
	if(EXISTS "/usr/local/lib/OGRE/")
                set(OGRE_PLUGINS "/usr/local/lib/OGRE/")
        elseif(EXISTS "/usr/lib/OGRE/")
                set(OGRE_PLUGINS "/usr/lib/OGRE/")
        elseif (EXISTS "/usr/lib/i386-linux-gnu/OGRE/")
                set(OGRE_PLUGINS "/usr/lib/i386-linux-gnu/OGRE/")
        else()
	     message(SEND_ERROR "Unable to find Ogre plugins, please set OGRE_PLUGINS variable")
	    
        endif(EXISTS "/usr/local/lib/OGRE/")
endif()

	if(EXISTS "/usr/local/lib/OGRE/cmake")
	  	set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")

	 elseif(EXISTS "/usr/share/OGRE/cmake")
	     set(CMAKE_MODULE_PATH "/usr/share/OGRE/cmake/modules;${CMAKE_MODULE_PATH}")
	  else ()
	     message(SEND_ERROR "Failed to find module path, please set OGRE_DIR variable to the folder containing FindOgre.cmake")
             find_package(OGRE_FIND REQUIRED)
	 endif(EXISTS "/usr/local/lib/OGRE/cmake")

 endif(UNIX AND NOT APPLE)




if(APPLE)
     set( OGRE_HOME $ENV{OGRE_HOME})
     if(NOT DEFINED OGRE_HOME)
	     message("The variable OGRE_HOME is unset, please set it, this cake lists has very low chances to compile")
	set(CMAKE_MODULE_PATH "${OGRE_DIR}/cmake/;${CMAKE_MODULE_PATH}")
	set(OGRE_PLUGINS "${OGRE_DIR}/lib/")
     else()
        message ("Ogre home variable defined")
        set(OGRE_HOME "$ENV{OGRE_HOME}")
        set(OGRE_DIR OGRE_HOME)
		set(CMAKE_MODULE_PATH "${OGRE_HOME}/cmake/;${CMAKE_MODULE_PATH}")
		set(OGRE_PLUGINS "${OGRE_HOME}/lib/")
     endif()
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
 


set(HDRS ../Functions.h
	 ../Representation.h
         ../DGtalNode.h
         ../Ogre3DDisplayFactory.h
	 ../mousecursor.h
	 ../ViewerOgre3D.h
	 ../InputListener.h
	 ../CameraMan.h
	 ../DrawableWithOgreWrapper.h
	 ../DrawableWithOgre.h
)
 
set(SRCS ../Representation.cpp 
         ../DGtalNode.cpp 
         ../mousecursor.cpp
	 ../DrawableWithOgre.cpp
         ../TextZone.cpp
         ../XMLExporter.cpp
)
 
include_directories( ${OIS_INCLUDE_DIRS}
	${OGRE_INCLUDE_DIRS}
	${OGRE_SAMPLES_INCLUDEPATH}
)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

if(MINGW OR UNIX)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
endif(MINGW OR UNIX)



SET(DGTAL_TESTS_SRC
  testDGtalSet
  testDomain
  testKalimskySpace
  testManipulate
  testSelection
  )
		

IF(NOT APPLE)

		FOREACH(FILE ${DGTAL_TESTS_SRC})
		  add_executable(${FILE} ${FILE} ${HDRS}  ${GUI_TYPE} ${SRCS})
		  target_link_libraries (${FILE} ${OGRE_LIBRARIES} ${OIS_LIBRARIES} ${DGTAL_LIBRARIES}  ${EXTRA_LIBS})
		ENDFOREACH(FILE)
else()

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/Contents/MacOS)

		
		FOREACH(FILE ${DGTAL_TESTS_SRC})
		

  
		 file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/${FILE})
		 file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/${FILE}/Contents)
		 file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/${FILE}/Contents/MacOS)
		 
		 configure_file(${PROJECT_SOURCE_DIR}/../Requirements/info.plist.in 
		${PROJECT_BINARY_DIR}/${FILE}/Contents/info.plist)
  
		  add_executable(${FILE} ${FILE} ${HDRS}  ${GUI_TYPE} ${SRCS})
		  
		  target_link_libraries (${FILE} ${OGRE_LIBRARIES} ${OIS_LIBRARIES} ${DGTAL_LIBRARIES}  ${EXTRA_LIBS})
		  
			ADD_CUSTOM_COMMAND(TARGET ${FILE}
			          POST_BUILD
			          COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/Contents/MacOS/${FILE} ${PROJECT_BINARY_DIR}/${FILE}/Contents/MacOS
			)


		ENDFOREACH(FILE)

ENDIF(NOT APPLE)
 


 
if(APPLE)
ADD_DEFINITIONS("-x objective-c++")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/Contents/MacOS)
endif(APPLE)


configure_file(${PROJECT_SOURCE_DIR}/../Requirements.h.in 
  ${PROJECT_SOURCE_DIR}/../Requirements.h)

configure_file(${PROJECT_SOURCE_DIR}/../Requirements/plugins.cfg.in 
  ${PROJECT_SOURCE_DIR}/../Requirements/plugins.cfg)


