cmake_minimum_required(VERSION 3.11)
project(RgRogue)

add_compile_options(-std=c++11 -Wall -Werror)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_BUGFIX 0)
exec_program(git ${CMAKE_SOURCE_DIR} 
  ARGS "describe" "--tag" "--abbrev=5" "--dirty" "--always" 
  OUTPUT_VARIABLE VERSION_GIT)
configure_file (
  "${PROJECT_SOURCE_DIR}/src/version.hpp.in"
  "${PROJECT_SOURCE_DIR}/src/version.hpp"
)

add_compile_options(-std=c++11 -Wall -Werror)

add_subdirectory(src)