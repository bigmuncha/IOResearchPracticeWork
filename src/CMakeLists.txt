cmake_minimum_required (VERSION 3.10)

project(ioresearch)

set (SOURCE_EXE main.cpp)

include_directories(unix_io standart_io stl_io)

add_executable(main ${SOURCE_EXE})

add_subdirectory(libc)
add_subdirectory(libcpp)
add_subdirectory(tools)

target_link_libraries(main stl_io tools unix_io standart_io )
