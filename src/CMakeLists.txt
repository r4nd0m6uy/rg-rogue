set(APP_NAME rg-rogue)
set(APP_SOURCES
  ../imgui/imgui.cpp
  ../imgui/imgui_draw.cpp
  logging/ILogSink.cpp
  logging/LogFormatter.cpp
  logging/ILogger.cpp
  logging/Logger.cpp
  logging/LoggerConsole.cpp
  logging/Loggers.cpp
  ui/IMainWindow.cpp
  ui/ImGuiAdapter.cpp
  ui/MainWindow.cpp
  ui/MainMenu.cpp
  ui/scenes/IScene.cpp
  ui/scenes/ScenesPool.cpp
  ui/scenes/Scene.cpp
  ui/scenes/SceneTitle.cpp
  ui/scenes/SceneGame.cpp
  event-loop/IKeyObserver.cpp
  event-loop/IMainLoop.cpp
  event-loop/MainLoop.cpp
  event-loop/EventDispatcher.cpp
  options/Options.cpp
  IRgRogue.cpp
  RgRogue.cpp
  main.cpp
)

find_package(PkgConfig REQUIRED)

pkg_search_module(SDL2 REQUIRED sdl2>=2.0.0)
pkg_search_module(OPENGL REQUIRED gl>=17.3.3)

include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${OPENGL_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/imgui
)


add_executable(${APP_NAME} ${APP_SOURCES})
target_link_libraries(${APP_NAME}
  ${SDL2_LIBRARIES}
  ${OPENGL_LIBRARIES}
)
install(TARGETS ${APP_NAME} DESTINATION bin)