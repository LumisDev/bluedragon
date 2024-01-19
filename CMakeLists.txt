cmake_minimum_required(VERSION 3.7)
project(bluedragon VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)
find_package(Vulkan REQUIRED)
find_package(Doxygen REQUIRED)
set(FETCHCONTENT_QUIET OFF)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        master  # Specify the version you want
)
FetchContent_MakeAvailable(glfw)

# Use FetchContent to include GLM
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        master  # Specify the version you want
)
FetchContent_MakeAvailable(glm)
set(GLFW_VULKAN_STATIC ON)
set(GLFW_INSTALL OFF)
set(GLFW_BUILD_WIN32 ON)
set(GLFW_BUILD_DOCS OFF)
set(BUILD_SHARED_LIBS ON)
if(Vulkan_FOUND)
    add_library(bluedragon SHARED engine/src/BDWindow.cpp engine/src/BDDevice.cpp)
    add_dependencies(bluedragon glfw glm)
    target_include_directories(bluedragon PUBLIC engine/include ${Vulkan_INCLUDE_DIRS} ${glfw_SOURCE_DIR}/include ${glm_SOURCE_DIR})
    target_link_libraries(bluedragon PUBLIC ${Vulkan_LIBRARIES} glfw glm)
    add_custom_command(
       TARGET bluedragon
       PRE_BUILD
       COMMAND glslc ${CMAKE_SOURCE_DIR}/engine/shader/default.vert --target-env=vulkan1.3 -Os -o ${CMAKE_BINARY_DIR}/default.vert.spv -std=450core
       COMMAND glslc ${CMAKE_SOURCE_DIR}/engine/shader/default.frag --target-env=vulkan1.3 -Os -o ${CMAKE_BINARY_DIR}/default.frag.spv -std=450core
       COMMENT "Building shaders"
    )
    target_compile_features(bluedragon PUBLIC cxx_std_17)
else()
    message(FATAL_ERROR "You didn't install Vulkan! CHeck if you installed it!")
endif()

add_subdirectory(test)
add_subdirectory(docs)