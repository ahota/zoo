cmake_minimum_required(VERSION 2.8)
project(cpp_plugin)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(plugins)

add_executable(zoo src/zoo.cpp src/util/globothy.cpp
    src/util/libnameothy.cpp)
target_link_libraries(zoo ${LIB_NAMES} ${CMAKE_DL_LIBS})
