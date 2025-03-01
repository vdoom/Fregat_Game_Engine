cmake_minimum_required (VERSION 3.22)

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