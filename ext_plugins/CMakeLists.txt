cmake_minimum_required(VERSION 3.0)

project(zoo_external)

# file globbing is normally discouraged, but this is a toy example
file(GLOB PLUGIN_SRC src/*.cpp)

foreach(SRC_FILE ${PLUGIN_SRC})
  get_filename_component(LIBNAME ${SRC_FILE} NAME_WLE)
  list(APPEND INSTALL_TARGETS ${LIBNAME})
  add_library(${LIBNAME} SHARED ${SRC_FILE})
  target_include_directories(${LIBNAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>)
endforeach()

install(TARGETS ${INSTALL_TARGETS} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/plugins)
