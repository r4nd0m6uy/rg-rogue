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

add_executable(${APP_NAME} ${APP_SOURCES})
install(TARGETS ${APP_NAME} DESTINATION bin)