if(BUILD_EXERCISE_4.8.3) 
	find_package(SDL2 CONFIG QUIET REQUIRED COMPONENTS SDL2)

	if(NOT SDL2_FOUND)
		message(FATAL_ERROR "SDL2 required build these examples, please check out: https://www.libsdl.org")
	endif()

    add_executable(Mandelbrot mandelbrot.cpp)

	target_link_libraries(Mandelbrot PUBLIC
		${SDL2_LIBRARIES})	

	target_include_directories(Mandelbrot PUBLIC
		${SDL2_INCLUDE_DIRS})

	add_executable(Fatou_Dust fatou_dust.cpp)

	target_link_libraries(Fatou_Dust PUBLIC
		${SDL2_LIBRARIES})	

	target_include_directories(Fatou_Dust PUBLIC
		${SDL2_INCLUDE_DIRS})

endif()
