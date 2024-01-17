find_package(Vulkan REQUIRED)
add_library(bluedragon src/BDApp.cpp)
target_include_directories(bluedragon PUBLIC headers)