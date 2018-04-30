if(DEFINED ENV{CPPUTEST_HOME})
  message(STATUS "Using CppUTest home: $ENV{CPPUTEST_HOME}")
  set(CPPUTEST_INCLUDE_DIRS $ENV{CPPUTEST_HOME}/include)
  set(CPPUTEST_LIBRARIES $ENV{CPPUTEST_HOME}/lib)
  set(CPPUTEST_LDFLAGS CppUTest CppUTestExt)
else()
  pkg_search_module(CPPUTEST REQUIRED cpputest>=3.8)
  message(STATUS "Found CppUTest version ${CPPUTEST_VERSION}")
endif()

# Ignore CppUTest warning
add_compile_options(-Wno-c++14-compat)

set(TEST_APP_NAME ${APP_NAME}_tests)
set(TEST_SOURCES
  Vector2DTest.cpp
  RectangleTest.cpp
  SquareTest.cpp
  main.cpp
)

include_directories(
  ${CPPUTEST_INCLUDE_DIRS}
  ../src/
)

link_directories(
  ${SDL2_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${CPPUTEST_LIBRARIES}
)

add_executable(${TEST_APP_NAME} ${TEST_SOURCES})
target_link_libraries(
  ${TEST_APP_NAME}
  ${APP_LIB_NAME}
  ${SDL2_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${CPPUTEST_LDFLAGS}
)

option(RUN_TESTS "Run the tests" ON)
if(RUN_TESTS)
  add_custom_command(TARGET ${TEST_APP_NAME} COMMAND ./${TEST_APP_NAME} POST_BUILD)
endif(RUN_TESTS)
