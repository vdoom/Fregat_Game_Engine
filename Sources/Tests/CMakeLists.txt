cmake_minimum_required (VERSION 2.6)

#project (Tests)
set(INCLUDE_DIR ./)
include_directories(${INCLUDE_DIR})
include_directories (.)
#find_package(GLEW REQUIRED)
#if (GLEW_FOUND)
#    include_directories(${GLEW_INCLUDE_DIRS})
#    link_libraries(${GLEW_LIBRARIES})
#endif()

#find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
#find_path(SDL2_INCLUDE_DIR SDL.h)
#find_library(SDL2_LIBRARY NAME SDL2)
#find_library(SDL2main_LIBRARY NAME SDL2)
#include_directories(${SDL2_INCLUDE_DIR})
#link_libraries(${SDL2_LIBRARY})
#link_libraries(${SDL2main_LIBRARY})

#find_path(SDL2_IMG_INCLUDE_DIR SDL_image.h)
#find_library(SDL2_IMG_LIBRARY NAME SDL2_image)
#include_directories(${SDL2_IMG_INCLUDE_DIR})
#link_libraries(${SDL2_IMG_LIBRARY})

#find_package(OpenGL REQUIRED)
#include_directories( ${OPENGL_INCLUDE_DIRS})
#find_library(OPENGL32 opengl32.lib)
#link_libraries(${OPENGL_LIBRARIES})
#target_include_directories(OBJViewer ${SDL2_INCLUDE_DIR})
#target_link_libraries(OBJViewer ${SDL2_LIBRARY})  

find_path(GLM_INC_DIR glm/glm.hpp)
include_directories (${GLM_INC_DIR})
#add_subdirectory (glm-0.9.8.4)

add_executable(Tests ./math_test.cpp
					 ./Math_tests.h
					 ./EntityComponent_tests.h
					 ./Transform_tests.h
					 ./TestingTools.h)
						
target_link_libraries (Tests Fregat)

# Creates a folder "executables" and adds target 
# project (app.vcproj) under it
set_property(TARGET Tests PROPERTY FOLDER "executables")

# Properties->General->Output Directory
set_target_properties(Tests PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
					  # Adds logic to INSTALL.vcproj to copy app.exe to destination directory
install (TARGETS Tests
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install)