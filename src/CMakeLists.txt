set(APP_NAME rg-rogue)
set(APP_SOURCES
  main.cpp
)

add_executable(${APP_NAME} ${APP_SOURCES})
install(TARGETS ${APP_NAME} DESTINATION bin)