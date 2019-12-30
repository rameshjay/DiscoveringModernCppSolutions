add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/4.8.1")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/4.8.2")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/4.8.3")

set_target_properties(
	4.8.1
	4.8.2
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/ch4")
