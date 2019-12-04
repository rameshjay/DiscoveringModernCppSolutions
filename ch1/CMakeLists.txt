add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/1.10.1")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/1.10.2")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/1.10.3")

set_target_properties(
    1.10.1
   	1.10.2.1
   	1.10.2.2
   	1.10.3
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/ch1")
