cmake_minimum_required (VERSION 3.10)

project(ioresearch)

set(STL_IO_LIB stl_io.cpp)

add_library (stl_io STATIC ${STL_IO_LIB})

target_link_libraries(stl_io)
