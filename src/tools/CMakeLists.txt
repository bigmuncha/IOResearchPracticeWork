cmake_minimum_required (VERSION 3.10)

project(ioresearch)

set(TOOLS_LIB tools.cpp)

add_library(tools STATIC ${TOOLS_LIB})
target_link_libraries(tools)
