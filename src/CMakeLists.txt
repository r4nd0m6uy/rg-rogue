set(APP_NAME rg-rogue)
set(APP_SOURCES
  logging/ILogSink.cpp
  logging/LogFormatter.cpp
  logging/ILogger.cpp
  logging/Logger.cpp
  logging/LoggerConsole.cpp
  logging/Loggers.cpp
  RgRogue.cpp
  main.cpp
)

find_package(PkgConfig REQUIRED)

pkg_search_module(SDL2 REQUIRED sdl2>=2.0.0)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${APP_NAME} ${APP_SOURCES})
target_link_libraries(${APP_NAME}
  ${SDL2_LIBRARIES}
)
install(TARGETS ${APP_NAME} DESTINATION bin)