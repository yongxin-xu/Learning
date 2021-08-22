project(testContainer)

cmake_minimum_required(VERSION 3.5)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )

include_directories( ../${CMAKE_SOURCE_DIR}/include )

add_executable(main main.cpp ../include/array/array.h ../include/vector/vector.h)