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
#include <imgui.h>
#include <imgui_impl_sdl_gl2.h>

#include "../logging/Loggers.hpp"
#include "MainWindow.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
MainWindow::MainWindow(Options& options):
  m_options(options),
  m_mainMenu(options),
  m_sdlWindow(nullptr),
  m_sdlGlContext(nullptr)
{
}

//------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
  ImGui_ImplSdlGL2_Shutdown();
  ImGui::DestroyContext();

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
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetSwapInterval(0);

  ImGui::CreateContext();
  ImGui_ImplSdlGL2_Init(m_sdlWindow);
  ImGui::StyleColorsDark();

  return 0;
}

//------------------------------------------------------------------------------
int MainWindow::draw()
{
  // Render imgui
  ImGui_ImplSdlGL2_NewFrame(m_sdlWindow);
  if(m_mainMenu.draw())
    return -1;

  // TODO render world
  glViewport(0, 0,
      (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  ImGui::Render();
  ImGui_ImplSdlGL2_RenderDrawData(ImGui::GetDrawData());
  SDL_GL_SwapWindow(m_sdlWindow);

  return 0;
}

}       // namespace
