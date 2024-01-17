cmake_minimum_required(VERSION 3.5)
project(bluedragon-sdk VERSION 0.0.1 LANGUAGES CXX)

option(BUILD_MESH_MANAGER "Builds the mesh manager" ON)
option(BUILD_EXAMPLES "Builds the examples" ON)

add_subdirectory(engine)
