add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/2.8.1")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/2.8.2")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/2.8.3")

set_target_properties(
	2.8.1
	2.8.2
	2.8.3
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/ch2")
