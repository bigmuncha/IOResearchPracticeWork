cmake_minimum_required(VERSION 2.8)

project(ioresearch)

set(SOURCE_EXE main.c)

set(UNIVERSAL_IO_LIB universal_unix_io.c)

add_library(universal_io STATIC ${UNIVERSAL_IO_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main universal_io)
