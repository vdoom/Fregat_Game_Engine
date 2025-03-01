cmake_minimum_required (VERSION 3.6)
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
