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
#include <SDL.h>

#include <imgui.h>
#include <imgui_impl_sdl_gl2.h>

#include "../logging/Loggers.hpp"
#include "MainLoop.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
MainLoop::MainLoop(Options& options, MainWindow& mainWindow):
  m_options(options),
  m_mainWindow(mainWindow),
  m_isRunning(false)
{
}

//------------------------------------------------------------------------------
MainLoop::~MainLoop()
{
}

//------------------------------------------------------------------------------
int MainLoop::run()
{
  SDL_Event event;

  LOG_DB() << "Starting main loop";

  m_isRunning = true;
  while(m_isRunning)
  {
    while(SDL_PollEvent(&event) != 0 )
    {
      ImGui_ImplSdlGL2_ProcessEvent(&event);
      if(event.type == SDL_QUIT)
      {
        m_isRunning = false;
        return 0;
      }

      if(!ImGui::GetIO().WantCaptureMouse &&
          !ImGui::GetIO().WantCaptureMouse)
      {
        // TODO: Dispatch event
        LOG_DB() << "Dispatch event " << event.type;
      }
      else
        LOG_DB() << "IMGUI EVENT";
    }

    // TODO: Tick world

    if(m_mainWindow.draw())
      return -1;
  }

  return 0;
}

}       // namespace
