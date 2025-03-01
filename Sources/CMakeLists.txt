cmake_minimum_required (VERSION 3.22)
project (OBJViewerSolution)

set(INCLUDE_DIR ./)
include_directories(${INCLUDE_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
message ("cxx Flags: " ${CMAKE_CXX_FLAGS})

#file(COPY ./Shaders/simple_with_light.frag 
#	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/ )
	
#file(COPY ./Shaders/simple_with_light.vert 
#	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/ )
	
#file(COPY ./Shaders/simple_without_light.frag
#	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/ )

#file(COPY ./Shaders/simple_without_light.vert
#	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/ )

include(cmake/3rd_party.cmake)

add_subdirectory(Tests)
add_subdirectory(Fregat)
add_subdirectory(OBJViewer)