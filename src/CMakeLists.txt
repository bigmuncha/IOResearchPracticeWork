cmake_minimum_required (VERSION 3.10)

project(ioresearch)

set (SOURCE_EXE main.c)

include_directories(unix_io standart_io)

add_executable(main ${SOURCE_EXE})

add_subdirectory(libc)
#add_subdirectory(libcpp)
add_subdirectory(tools)

target_link_libraries(main unix_io standart_io tools)
