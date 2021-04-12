cmake_minimum_required(VERSION 3.10)

project(ioresearch)

set(UNIVERSAL_IO_LIB universal_unix_io.c)
set(STANDART_IO_LIB standart_library_io.c)

add_library(standart_io STATIC ${STANDART_IO_LIB})
target_link_libraries(standart_io)

add_library(unix_io STATIC ${UNIVERSAL_IO_LIB})
target_link_libraries(unix_io)
