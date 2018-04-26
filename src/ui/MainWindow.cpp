/*
 * Random Rogue an open source platform rogue like
 *
 * Copyright (C) 2017 R4nd0m6uy <r4nd0m6uy@r4nd0m6uy.ch>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "../logging/Loggers.hpp"
#include "MainWindow.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
MainWindow::MainWindow(Options& options, IMainLoop& mainLoop,
    ImGuiAdapter& imgui, IScene& scene):
  m_options(options),
  m_mainMenu(options, mainLoop, *this),
  m_imgui(imgui),
  m_scene(scene),
  m_sdlWindow(nullptr),
  m_sdlGlContext(nullptr)
{
}

//------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
  m_imgui.cleanup();

  if(m_sdlWindow)
    SDL_DestroyWindow(m_sdlWindow);

  if(m_sdlGlContext)
    SDL_GL_DeleteContext(m_sdlGlContext);
}

//------------------------------------------------------------------------------
int MainWindow::init()
{
  Uint32 sdlCreateWindowFlag = SDL_WINDOW_OPENGL;

  if(SDL_Init(SDL_INIT_EVERYTHING))
  {
    LOG_ER() << "SDL initialization failed:" << SDL_GetError();
    return -1;
  }

  if(m_options.isFullScreen())
    sdlCreateWindowFlag |= SDL_WINDOW_FULLSCREEN;

  m_sdlWindow = SDL_CreateWindow("rg-rogue",
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      m_options.getXResolution(), m_options.getYResolution(),
      sdlCreateWindowFlag);
  if(!m_sdlWindow)
  {
    LOG_ER() << "Error creating SDL window: " << SDL_GetError();
    return -1;
  }

  m_sdlGlContext = SDL_GL_CreateContext(m_sdlWindow);
  if(!m_sdlGlContext)
  {
    LOG_ER() << "Error creating OpenGl context: " << SDL_GetError();
    return -1;
  }

  if(SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1))
  {
    LOG_ER() << "Cannot set OpenGl double buffering: " << SDL_GetError();
    return -1;
  }

  if(SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24))
  {
    LOG_ER() << "Cannot set OpenGl color deppth: " << SDL_GetError();
    return -1;
  }

  if(SDL_GL_SetSwapInterval(0))
  {
    LOG_ER() << "Cannot set OpenGl swap interval: " << SDL_GetError();
    return -1;
  }

  glClearColor(0, 0, 0, 1);

  if(m_imgui.init(m_sdlWindow))
    return -1;

  return m_mainMenu.init();
}

//------------------------------------------------------------------------------
int MainWindow::draw()
{
  // Render imgui
  m_imgui.newFrame(m_sdlWindow);

  glClear(GL_COLOR_BUFFER_BIT);

  if(m_mainMenu.draw())
    return -1;

  // Render scene
  m_scene.draw(m_sdlWindow);

  if(m_imgui.draw())
    return -1;

  SDL_GL_SwapWindow(m_sdlWindow);

  return 0;
}

//------------------------------------------------------------------------------
int MainWindow::applyVideoConfig(Options& options)
{
  if(options.isFullScreen() != m_options.isFullScreen())
  {
    Uint32 flags = 0;

    if(options.isFullScreen())
      flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_SetWindowFullscreen(m_sdlWindow, flags))
    {
      LOG_ER() << "Cannot change full screen configuration: " << SDL_GetError();
      return -1;
    }
  }

  return 0;
}

}       // namespace
