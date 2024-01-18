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
option(BD_BUILD_DOCS "Build the docs with Doxygen" ON)
if(Vulkan_FOUND)
    add_library(bluedragon SHARED engine/src/BDWindow.cpp)
    target_include_directories(bluedragon PUBLIC engine/include ${Vulkan_INCLUDE_DIRS} ${glfw_SOURCE_DIR}/include ${glm_SOURCE_DIR})
    target_compile_features(bluedragon PUBLIC cxx_std_17)
else()
    message(FATAL_ERROR "You didn't install Vulkan! CHeck if you installed it!")
endif()

if(BD_BUILD_DOCS AND Doxygen_FOUND AND CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
    set(Doxygen_IN ${CMAKE_SOURCE_DIR}/docs/Doxyfile.in)
    set(Doxygen_OUT ${CMAKE_BINARY_DIR}/docs/Doxyfile)
    configure_file(${Doxygen_IN} ${Doxygen_OUT} @ONLY)
    message("Generating docs started!")
    add_custom_target(bluedragon_docs ALL 
        COMMAND ${Doxygen_EXECUTABLE} ${Doxygen_OUT}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Making the docs for you..."
        VERBATIM
    )
elseif(BD_BUILD_DOCS AND NOT Doxygen_FOUND)
    message(FATAL_ERROR "Do you wanna build docs without doxygen ???")
elseif(BD_BUILD_DOCS AND Doxygen_FOUND AND NOT CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
    message(WARNING "ACTIVATE RELEASE FOR THE DOCS!!!")
endif()