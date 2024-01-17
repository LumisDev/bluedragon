cmake_minimum_required(VERSION 3.7)
project(bluedragon VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)
find_package(Vulkan REQUIRED)
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
if(Vulkan_FOUND)
    add_library(bluedragon engine/src/BDWindow.cpp)
    target_include_directories(bluedragon PUBLIC engine/include ${Vulkan_INCLUDE_DIRS} ${glfw_SOURCE_DIR}/include ${glm_SOURCE_DIR})
    target_compile_features(bluedragon PUBLIC cxx_std_17)
else()
    message(FATAL_ERROR "You didn't install Vulkan! CHeck if you installed it!")
endif()