option(BD_BUILD_DOCS "Build the docs with Doxygen" ON)
if(BD_BUILD_DOCS AND Doxygen_FOUND AND CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
    set(Doxygen_IN ${CMAKE_SOURCE_DIR}/Doxyfile.in)
    set(Doxygen_OUT ${CMAKE_BINARY_DIR}/Doxyfile)
    configure_file(${Doxygen_IN} ${Doxygen_OUT} @ONLY)
    message(STATUS "Generating docs started!")
    add_custom_target(bluedragon_docs ALL 
        COMMAND ${Doxygen_EXECUTABLE} ${Doxygen_OUT}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Making the docs for you..."
        VERBATIM
    )
endif()