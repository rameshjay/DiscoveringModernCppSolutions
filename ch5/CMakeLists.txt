add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/5.5.1")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/5.5.2")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/5.5.3")

set_target_properties(
	5.5.1
	5.5.2
	5.5.3
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/ch5")
