SET(PROJ_NAME sample_circular_cut)
PROJECT(${PROJ_NAME})

# Include directories with headers
#---------------------------------------------------#
INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}/modules/common )
INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}/modules/cutDetector/include )

# Source
#---------------------------------------------------#
FILE(GLOB ${PROJ_NAME}_SRC
    "src/*.cpp"
)
FILE(GLOB ${PROJ_NAME}_HEADERS
    "include/*.h"
)

# Create Executable
#---------------------------------------------------#
ADD_EXECUTABLE( ${PROJ_NAME} ${${PROJ_NAME}_HEADERS} ${${PROJ_NAME}_SRC})

TARGET_LINK_LIBRARIES(${PROJ_NAME} ${OpenCV_LIBS} )

TARGET_LINK_LIBRARIES(${PROJ_NAME} cutDetector)