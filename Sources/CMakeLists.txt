cmake_minimum_required (VERSION 2.6)
project (OBJViewerSolution)

set(INCLUDE_DIR ./)
include_directories(${INCLUDE_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
message ("cxx Flags: " ${CMAKE_CXX_FLAGS})


get_filename_component(GLM_INCLUDE_ABSOLUTE
                       ".\3rd_party\glm-0.9.8.4\include"
                       ABSOLUTE)
get_filename_component(GLEW_INCLUDE_ABSOLUTE
                       ".\3rd_party\glew-2.0.0\include"
                       ABSOLUTE)
get_filename_component(GLEW_LIBRARIES_ABSOLUTE
                       ".\3rd_party\glew-2.0.0\lib\Release\x64\glew32.lib"
                       ABSOLUTE)
get_filename_component(SDL2_INCLUDE_ABSOLUTE
                       ".\3rd_party\SDL2-2.0.4\include"
                       ABSOLUTE)
get_filename_component(SDL2_LIBRARY_ABSOLUTE
                       ".\3rd_party\SDL2-2.0.4\lib\x64\SDL2.lib"
                       ABSOLUTE)
get_filename_component(SDL2main_LIBRARY_ABSOLUTE
                       ".\3rd_party\SDL2-2.0.4\lib\x64\SDL2main.lib"
                       ABSOLUTE)
get_filename_component(SDL2_IMG_INCLUDE_ABSOLUTE
                       ".\3rd_party\SDL2_image-2.0.1\include"
                       ABSOLUTE)
get_filename_component(SDL2_IMG_LIBRARY_ABSOLUTE
                       ".\3rd_party\SDL2_image-2.0.1\lib\x64\SDL2_image.lib"
                       ABSOLUTE)					   
					  
set(GLM_INC_DIR ${GLM_INCLUDE_ABSOLUTE})
set(GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_ABSOLUTE})
set(GLEW_LIBRARIES ${GLEW_LIBRARIES_ABSOLUTE})
set(SDL2_INCLUDE_DIR ${SDL2_INCLUDE_ABSOLUTE})
set(SDL2_LIBRARY ${SDL2_LIBRARY_ABSOLUTE})
set(SDL2main_LIBRARY ${SDL2main_LIBRARY_ABSOLUTE})
set(SDL2_IMG_INCLUDE_DIR ${SDL2_IMG_INCLUDE_ABSOLUTE})
set(SDL2_IMG_LIBRARY ${SDL2_IMG_LIBRARY_ABSOLUTE})

add_subdirectory(Tests)
add_subdirectory(Fregat)
add_subdirectory(OBJViewer)