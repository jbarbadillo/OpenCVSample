# OPTIONS
#---------------------------------------------------#
OPTION(${PROJ_MAIN_NAME}_SAMPLE_CIRCULAR_CUT   		"Set ON sample circular cut"        	ON  )

IF ( ${PROJ_MAIN_NAME}_SAMPLE_CIRCULAR_CUT  )
  ADD_SUBDIRECTORY( sample_circular_cut )  
ENDIF()