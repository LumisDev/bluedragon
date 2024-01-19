option(BUILD_TEST "Build the Bluedragon engine's test" ON)

if(BUILD_TEST)
    add_executable(bd_test src/main.cpp src/app.cpp)
    target_link_libraries(bd_test PUBLIC bluedragon)
    target_include_directories(bd_test PUBLIC class)
endif()