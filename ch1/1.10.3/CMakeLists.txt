add_executable(1.10.3 matrixmarket.cpp) 

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/MatrixMarket.dat"
     DESTINATION "${CMAKE_SOURCE_DIR}/output/ch1")


