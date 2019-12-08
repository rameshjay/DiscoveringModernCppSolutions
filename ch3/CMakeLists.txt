add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.1")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.3")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.4")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.5")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.6")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.8")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3.11.9")

set_target_properties(
	3.11.1
	3.11.3
	3.11.4
	3.11.5
	3.11.6
	3.11.8
	3.11.9
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/ch3")
