
add_executable(3.11.1 stringreprentation.cpp)
target_compile_features(3.11.1 PUBLIC 
	cxx_std_17 
	cxx_variadic_templates)
