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
  ui/IDrawable.cpp
  ui/scenes/IScene.cpp
  ui/scenes/ScenesPool.cpp
  ui/scenes/Scene.cpp
  ui/scenes/SceneTitle.cpp
  ui/scenes/SceneGame.cpp
  ui/decorators/IShapeDecorator.cpp
  ui/decorators/ColoredShape.cpp
  event-loop/IKeyObserver.cpp
  event-loop/IMainLoop.cpp
  event-loop/MainLoop.cpp
  event-loop/EventDispatcher.cpp
  options/Options.cpp
  engine/shape/Vector2D.cpp
  engine/shape/IShape.cpp
  engine/shape/Shape.cpp
  engine/shape/Square.cpp
  engine/shape/Rectangle.cpp
  engine/commands/IControllable.cpp
  engine/commands/ICommand.cpp
  engine/commands/CommandJump.cpp
  engine/commands/CommandStopJump.cpp
  engine/Camera.cpp
  engine/Player.cpp
  engine/PlayerAI.cpp
  engine/World.cpp
  IRgRogue.cpp
  RgRogue.cpp
)

add_library(${APP_LIB_NAME} ${APP_SOURCES})

include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${OPENGL_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/imgui
)


add_executable(${APP_NAME} main.cpp)
target_link_libraries(
  ${APP_NAME}
  ${APP_LIB_NAME}
  ${SDL2_LIBRARIES}
  ${OPENGL_LIBRARIES}
)
install(TARGETS ${APP_NAME} DESTINATION bin)