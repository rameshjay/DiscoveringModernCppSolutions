if(BUILD_EXERCISE_4.8.3) 
	include(FindSDL) 
	if(NOT SDL_FOUND) 
		message(FATAL_ERROR "SDL1 requred for this example")
    endif()

	find_package(SDL2 CONFIG QUIET REQUIRED COMPONENTS SDL2)

	if(NOT SDL2_FOUND)
		message(FATAL_ERROR "SDL2 required build these examples, please check out: https://www.libsdl.org")
	endif()

    add_executable(Mandelbrot mandelbrot.cpp)

	target_link_libraries(mandelbrot.cpp PUBLIC
		${SDL2_LIBRARIES})	

	target_include_directories(mandelbrot.cpp PUBLIC
		${SDL2_INCLUDE_DIRS})
endif()
