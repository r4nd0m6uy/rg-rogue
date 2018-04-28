cmake_minimum_required(VERSION 3.11)
project(RgRogue)

add_compile_options(-Wall -Werror)
set(CMAKE_CXX_STANDARD 11)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_BUGFIX 0)
exec_program(
  git ${CMAKE_SOURCE_DIR}
  ARGS "describe" "--tag" "--abbrev=5" "--dirty" "--always" 
  OUTPUT_VARIABLE VERSION_GIT)
configure_file (
  "${PROJECT_SOURCE_DIR}/src/version.hpp.in"
  "${PROJECT_SOURCE_DIR}/src/version.hpp"
)

set(APP_NAME rg-rogue)
set(APP_LIB_NAME ${APP_NAME}lib)

find_package(PkgConfig REQUIRED)

add_subdirectory(src)

option(COMPILE_TESTS "Compile the tests" OFF)
if(COMPILE_TESTS)
  add_subdirectory(tests)
endif(COMPILE_TESTS)
