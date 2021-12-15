#############################################################################
# Name:        samples/minimal/CMakeListst.txt
# Purpose:     Sample CMake file to show usage of cmake for wxWidgets users
# Author:      Tobias Taschner
# Created:     2016-10-23
# Copyright:   (c) 2016 wxWidgets development team
# Licence:     wxWindows licence
#############################################################################

#
# This file is just a sample to show using cmake from an application
# If you want to build the minimal and other samples please use the
# wxBUILD_SAMPLES option when using cmake on the library
#

# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.16)

if(APPLE AND NOT CMAKE_OSX_DEPLOYMENT_TARGET)
    # If no deployment target has been set default to the minimum supported
    # OS version (this has to be set before the first project() call)
    if(CMAKE_SYSTEM_NAME STREQUAL "iOS")
        set(CMAKE_OSX_DEPLOYMENT_TARGET 12.0 CACHE STRING "iOS Deployment Target")
    else()
        set(CMAKE_OSX_DEPLOYMENT_TARGET 10.10 CACHE STRING "macOS Deployment Target")
    endif()
endif()

# Name the project
project(pdm)

#set(CMAKE_PREFIX_PATH F:/wxWidgets)

# Request the required wxWidgets libs
find_package(wxWidgets 3.0 COMPONENTS core base net webview richtext xml stc html xrc REQUIRED)
#find_package(pdm-network)
# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -O3  -m64")
if (WIN32)
    set(PDM_LIBS pdm-network cc20_multi  ws2_32)

elseif (APPLE)
    set(PDM_LIBS pdm-network cc20_multi )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -D LINUX -D MACOS")
elseif (UNIX)
    set(PDM_LIBS pdm-network cc20_multi )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -D LINUX")
endif ()

# Define a variable containing a list of source files for the project
set(SRC_FILES
        src/cApp.cpp src/cMain.cpp
        file_handles/Tree_Ctrl.cpp file_handles/Tree_Ctrl.h file_handles/pdmrc.cpp file_handles/pdmrc.h file_handles/pdm-sync.h file_handles/pdm-sync.cpp)

if(WIN32)
    # Include a RC file for windows
#    list(APPEND SRC_FILES ../sample.rc)
elseif(APPLE)
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES resources/logonight.icns)
endif()

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
#add_executable(${PROJECT_NAME}  ${SRC_FILES})

add_subdirectory(pdm-network)
add_subdirectory(pdm-crypt-module)
#target_link_libraries(${PROJECT_NAME} PRIVATE )


# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${PDM_LIBS})

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RESOURCE ".logonight.icns"
        MACOSX_BUNDLE_ICON_FILE resources/logonight.icns
        MACOSX_BUNDLE_COPYRIGHT "Copyright Yang Yi"
        MACOSX_BUNDLE_GUI_IDENTIFIER "org.wxwidgets.pdm"
        )
endif()
