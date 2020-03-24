include(bsfUtility/CMakeSources.cmake)

add_common_flags(bsf_copy)
 
target_include_directories(bsf_copy PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/bsfUtility>
)
 
set_property(TARGET bsd_copy PROPERTY FOLDER Foundation)
 
if(NOT BS_IS_BANSHEE3D)
	install(
		DIRECTORY bsfUtility
		DESTINATION include
		FILES_MATCHING
		PATTERN "*.h"
		PATTERN "*.hpp"
		PATTERN "Private" EXCLUDE
	)
	
	
	
endif()