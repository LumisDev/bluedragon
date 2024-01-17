add_subdirectory(ext/glm)
add_subdirectory(ext/glfw)
find_package(Vulkan REQUIRED QUIET)


if(Vulkan_FOUND)
    message(STATUS "Vulkan libs are in: ${Vulkan_LIBRARIES}")
    message(STATUS "Vulkan headers path: ${Vulkan_INCLUDE_DIRS}")
    add_library(bluedragon src/BDWindow.cpp)
    target_include_directories(bluedragon PUBLIC ${Vulkan_INCLUDE_DIRS})
    target_link_libraries(bluedragon PUBLIC ${Vulkan_LIBRARIES})
    add_dependencies(bluedragon glfw glm)
    add_custom_command(TARGET bluedragon PRE_BUILD
        COMMENT "Building shaders..."
        COMMAND glslc ${CMAKE_CURRENT_SOURCE_DIR}/shader/default.vert -std=450core -Os -O -o ${CMAKE_CURRENT_BINARY_DIR}/default.vert.spv --target-spv=spv1.6 --target-env=vulkan1.3
        COMMAND glslc ${CMAKE_CURRENT_SOURCE_DIR}/shader/default.frag -std=450core -o ${CMAKE_CURRENT_BINARY_DIR}/default.frag.spv --target-spv=spv1.6 --target-env=vulkan1.3
    )
    target_include_directories(bluedragon PUBLIC include)
else()
    message(FATAL_ERROR "Could NOT fild Vulkan SDK!")
endif()