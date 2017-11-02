# Main header: Project name & Configuration
# ------------------------------------------------------------------------------------------------------
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

SET(PROJ_MAIN_NAME "ComputerVisionSample")
PROJECT(${PROJ_MAIN_NAME})

# Paths
SET(LIBRARY_OUTPUT_PATH          ${PROJECT_BINARY_DIR}/bin                   CACHE PATH "Library output" FORCE)
SET(EXECUTABLE_OUTPUT_PATH       ${PROJECT_BINARY_DIR}/bin                   CACHE PATH "Executable output" FORCE)
SET(${PROJ_MAIN_NAME}_DATA 	"" 	CACHE PATH "This directory contains all DATA and RESOURCES")

SET(TEST_DATA                  	${CMAKE_SOURCE_DIR}/tests/data           CACHE PATH "Path to data for tests")

SET(GTEST_PATH 			${CMAKE_SOURCE_DIR}/thirdparties/googletest-master 	CACHE PATH "Path for google test")

add_definitions(-std=c++11)
enable_testing()

FIND_PACKAGE( OpenCV )
IF(OpenCV_DIR STREQUAL NOT_FOUND)
  MESSAGE(FATAL_ERROR "Install OpenCV")
ENDIF()

######################################################################################
# ADD SUB FOLDERS
######################################################################################
ADD_SUBDIRECTORY(modules)	
ADD_SUBDIRECTORY(samples)
#ADD_SUBDIRECTORY (tests)
configure_file("${CMAKE_SOURCE_DIR}/modules/common/config.h.in"  "${CMAKE_SOURCE_DIR}/modules/common/config.h")