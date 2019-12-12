add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/4.8.1")

set_target_properties(
	4.8.1
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/ch4")
