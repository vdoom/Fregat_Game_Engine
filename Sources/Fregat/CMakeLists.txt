cmake_minimum_required (VERSION 3.6)
project (Fregat)

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
#target_include_directories(OBJViewer ${SDL2_INCLUDE_DIR})
#target_link_libraries(OBJViewer ${SDL2_LIBRARY})  

# SHARED
add_library(Fregat _API.h
./System/Assets/AssetsManagement/AssetBase.h
./System/Assets/AssetsManagement/AssetBin.cpp
./System/Assets/AssetsManagement/AssetBin.h
./System/Assets/AssetsManagement/AssetsInfo.h
./System/Assets/AssetsManagement/AssetsManager.cpp
./System/Assets/AssetsManagement/AssetsManager.h
./System/Assets/AssetsManagement/AssetSys.h
./System/Assets/Render/Components/RendererComponent.cpp
./System/Assets/Render/Components/RendererComponent.h
./System/Assets/Render/Material/MaterialBase.h
./System/Assets/Render/Material/SimpleMaterial.cpp
./System/Assets/Render/Material/SimpleMaterial.h
./System/Assets/Render/Mesh/ComplexGeometry3D.cpp
./System/Assets/Render/Mesh/ComplexGeometry3D.h
./System/Assets/Render/Mesh/Geometry3D.cpp
./System/Assets/Render/Mesh/Geometry3D.h
./System/Assets/Render/Mesh/MeshBase.h
./System/Assets/Render/Mesh/MeshPlane.cpp
./System/Assets/Render/Mesh/MeshPlane.h
./System/Assets/Render/Mesh/MeshStatic.cpp
./System/Assets/Render/Mesh/MeshStatic.h
./System/Assets/Render/Shader/Shader.cpp
./System/Assets/Render/Shader/Shader.h
./System/Assets/Render/Texture/BitMap2D.cpp
./System/Assets/Render/Texture/BitMap2D.h
./System/Assets/Render/Texture/Texture2D.cpp
./System/Assets/Render/Texture/Texture2D.h
./System/Assets/Render/Texture/TextureBase.h
./MathLib/AABB.h
./MathLib/EasingLib.h
./MathLib/Mat3.h
./MathLib/Mat4.h
./MathLib/MathCommon.h
./MathLib/MatOperations.h
./MathLib/Rect.h
./MathLib/Vec2.h
./MathLib/Vec3.h
./MathLib/Vec4.h
./System/OverridedTypes.h
./System/Static3DObjectFabriacator.cpp
./System/Static3DObjectFabriacator.h
./System/Core/App.h
./System/Core/ServiceLocator.h
./System/Core/ServiceLocator.cpp
./System/Core/IService.h
./System/Core/IWindow.h
./System/Core/SDLWindow.h
./System/Core/Component.cpp
./System/Core/Component.h
./System/Core/Entity.cpp
./System/Core/Entity.h
./System/Core/ObjectManager.cpp
./System/Core/ObjectManager.h
./System/Core/Transform.cpp
./System/Core/Transform.h
./System/IO/FileFormats/OBJimporter.cpp
./System/IO/FileFormats/OBJimporter.h
./System/IO/FileFormats/ParsersDataStructures.h
./System/IO/Inputs/BaseInputController.h
./System/IO/Inputs/SDLInputController.h
./System/Renderer/BaseRenderer.cpp
./System/Renderer/BaseRenderer.h
./System/Renderer/Camera.cpp
./System/Renderer/Camera.h
./System/Renderer/FPSCamera.cpp
./System/Renderer/FPSCamera.h
./System/Renderer/ICamera.h
./System/Renderer/OpenGL33Renderer.cpp
./System/Renderer/OpenGL33Renderer.h
./System/Tools/UUID.h
./System/Tools/Delegat.h
./System/Tools/Logger.h
)

SOURCE_GROUP("Fregat\\MathLib" FILES 
./MathLib/AABB.h
./MathLib/EasingLib.h
./MathLib/Mat3.h 
./MathLib/Mat4.h
./MathLib/MathCommon.h
./MathLib/MatOperations.h
./MathLib/Rect.h
./MathLib/Vec2.h
./MathLib/Vec3.h
./MathLib/Vec4.h
)

SOURCE_GROUP("Fregat\\System\\Tools" FILES 
./System/Tools/UUID.h
./System/Tools/Delegat.h
./System/Tools/Logger.h
)

SOURCE_GROUP("Fregat\\System\\Renderer" FILES 
./System/Renderer/BaseRenderer.cpp
./System/Renderer/BaseRenderer.h
./System/Renderer/Camera.cpp
./System/Renderer/Camera.h
./System/Renderer/FPSCamera.cpp
./System/Renderer/FPSCamera.h
./System/Renderer/ICamera.h
./System/Renderer/OpenGL33Renderer.cpp
./System/Renderer/OpenGL33Renderer.h
)

SOURCE_GROUP("Fregat\\System\\IO\\Inputs" FILES 
./System/IO/Inputs/BaseInputController.h
./System/IO/Inputs/SDLInputController.h
)

SOURCE_GROUP("Fregat\\System\\IO\\FileFormats" FILES 
./System/IO/FileFormats/OBJimporter.cpp
./System/IO/FileFormats/OBJimporter.h
./System/IO/FileFormats/ParsersDataStructures.h
)

SOURCE_GROUP("Fregat\\System\\Core" FILES 
./System/Core/App.h
./System/Core/ServiceLocator.h
./System/Core/ServiceLocator.cpp
./System/Core/IService.h
./System/Core/IWindow.h
./System/Core/SDLWindow.h
./System/Core/Component.cpp
./System/Core/Component.h
./System/Core/Entity.cpp
./System/Core/Entity.h
./System/Core/ObjectManager.cpp
./System/Core/ObjectManager.h
./System/Core/Transform.cpp
./System/Core/Transform.h
)

SOURCE_GROUP("Fregat\\System" FILES 
./System/OverridedTypes.h
./System/Static3DObjectFabriacator.cpp
./System/Static3DObjectFabriacator.h
)

SOURCE_GROUP("Fregat\\System\\Assets\\Render\\Texture" FILES 
./System/Assets/Render/Texture/BitMap2D.cpp
./System/Assets/Render/Texture/BitMap2D.h
./System/Assets/Render/Texture/Texture2D.cpp
./System/Assets/Render/Texture/Texture2D.h
./System/Assets/Render/Texture/TextureBase.h
)

SOURCE_GROUP("Fregat\\System\\Assets\\Render\\Shader" FILES 
./System/Assets/Render/Shader/Shader.cpp
./System/Assets/Render/Shader/Shader.h
)

SOURCE_GROUP("Fregat\\System\\Assets\\Render\\Mesh" FILES 
./System/Assets/Render/Mesh/ComplexGeometry3D.cpp
./System/Assets/Render/Mesh/ComplexGeometry3D.h
./System/Assets/Render/Mesh/Geometry3D.cpp
./System/Assets/Render/Mesh/Geometry3D.h
./System/Assets/Render/Mesh/MeshBase.h
./System/Assets/Render/Mesh/MeshPlane.cpp
./System/Assets/Render/Mesh/MeshPlane.h
./System/Assets/Render/Mesh/MeshStatic.cpp
./System/Assets/Render/Mesh/MeshStatic.h
)

SOURCE_GROUP("Fregat\\System\\Assets\\Render\\Material" FILES 
./System/Assets/Render/Material/MaterialBase.h
./System/Assets/Render/Material/SimpleMaterial.cpp
./System/Assets/Render/Material/SimpleMaterial.h
)

SOURCE_GROUP("Fregat\\System\\Assets\\Render\\Components" FILES 
./System/Assets/Render/Components/RendererComponent.cpp
./System/Assets/Render/Components/RendererComponent.h
)

SOURCE_GROUP("Fregat\\System\\Assets\\AssetsManagement" FILES 
./System/Assets/AssetsManagement/AssetBase.h
./System/Assets/AssetsManagement/AssetBin.cpp
./System/Assets/AssetsManagement/AssetBin.h
./System/Assets/AssetsManagement/AssetsInfo.h
./System/Assets/AssetsManagement/AssetsManager.cpp
./System/Assets/AssetsManagement/AssetsManager.h
./System/Assets/AssetsManagement/AssetSys.h
)

# Creates a folder "libraries" and adds target project (math.vcproj) under it
set_property(TARGET Fregat PROPERTY FOLDER "libraries")

# Properties->General->Output Directory
# set_target_properties(Fregat PROPERTIES
#                       RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
					  
					  # Adds logic to INSTALL.vcproj to copy math.dll to the destination directory
# install (TARGETS Fregat
#          RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
#          LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install)