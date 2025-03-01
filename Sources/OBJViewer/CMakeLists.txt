cmake_minimum_required (VERSION 3.22)
project (OBJViewer)

set(INCLUDE_DIR ./)
include_directories(${INCLUDE_DIR})
include_directories (.)

find_path(GLEW_INCLUDE_DIRS GL/glew.h)
find_library(GLEW_LIBRARIES NAME glew32)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})
#find_package(GLEW REQUIRED)
#if (GLEW_FOUND)
#    include_directories(${GLEW_INCLUDE_DIRS})
#    link_libraries(${GLEW_LIBRARIES})
#endif()

#find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
find_path(SDL2_INCLUDE_DIR SDL.h)
find_library(SDL2_LIBRARY NAME SDL2)
find_library(SDL2main_LIBRARY NAME SDL2)
include_directories(${SDL2_INCLUDE_DIR})
link_libraries(${SDL2_LIBRARY})
link_libraries(${SDL2main_LIBRARY})

find_path(SDL2_IMG_INCLUDE_DIR SDL_image.h)
find_library(SDL2_IMG_LIBRARY NAME SDL2_image)
include_directories(${SDL2_IMG_INCLUDE_DIR})
link_libraries(${SDL2_IMG_LIBRARY})

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS})
#find_library(OPENGL32 opengl32.lib)
link_libraries(${OPENGL_LIBRARIES})

add_executable(OBJViewer OBJviewer.cpp
./ViewerApp.cpp
./ViewerApp.h
./ViewerObjectManager.cpp
./ViewerObjectManager.h
)

target_link_libraries (OBJViewer Fregat)

# Creates a folder "executables" and adds target 
# project (app.vcproj) under it
set_property(TARGET OBJViewer PROPERTY FOLDER "executables")

# Properties->General->Output Directory
set_target_properties(OBJViewer PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
					  
install (TARGETS OBJViewer
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install)
		 
add_custom_command(TARGET OBJViewer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shaders"
        "${CMAKE_CURRENT_BINARY_DIR}/Shaders")
		
add_custom_command(TARGET OBJViewer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/glew-2.0.0/bin/Release/x64/glew32.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/glew32.dll")
		
add_custom_command(TARGET OBJViewer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/SDL2_image-2.0.1/lib/x64/zlib1.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/zlib1.dll")
		
add_custom_command(TARGET OBJViewer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/SDL2_image-2.0.1/lib/x64/SDL2_image.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/SDL2_image.dll")

add_custom_command(TARGET OBJViewer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/SDL2_image-2.0.1/lib/x64/libwebp-4.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/libwebp-4.dll")
		
add_custom_command(TARGET OBJViewer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/SDL2_image-2.0.1/lib/x64/libtiff-5.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/libtiff-5.dll")	
		
add_custom_command(TARGET OBJViewer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/SDL2_image-2.0.1/lib/x64/libpng16-16.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/libpng16-16.dll")
		
add_custom_command(TARGET OBJViewer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/SDL2_image-2.0.1/lib/x64/libjpeg-9.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/libjpeg-9.dll")
		
add_custom_command(TARGET OBJViewer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/SDL2-2.0.4/lib/x64/SDL2.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/SDL2.dll")
		
		