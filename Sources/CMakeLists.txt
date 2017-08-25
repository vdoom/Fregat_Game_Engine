cmake_minimum_required (VERSION 2.6)
project (OBJViewerSolution)

set(INCLUDE_DIR ./)
include_directories(${INCLUDE_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
message ("cxx Flags: " ${CMAKE_CXX_FLAGS})

add_subdirectory(Tests)
add_subdirectory(Fregat)
add_subdirectory(OBJViewer)