add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.1")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.3")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.4")

set_target_properties(
	3.11.1
	3.11.3
	3.11.4
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/ch3")
