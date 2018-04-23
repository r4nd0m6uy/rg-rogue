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
  int framesCount = 0;
  Uint32 lastTick = SDL_GetTicks();
  Uint32 lastFrame = SDL_GetTicks();

  LOG_DB() << "Starting main loop";

  m_isRunning = true;
  while(m_isRunning)
  {
    Uint32 loopDuration;

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
        switch(event.type)
        {
        case SDL_KEYDOWN:
          for(auto& keyObserver : m_keyObservers)
            keyObserver.get().onKeyPressed(
                event.key.keysym.scancode,
                event.key.keysym.sym,
                event.key.keysym.mod);
          break;
        case SDL_KEYUP:
          for(auto& keyObserver : m_keyObservers)
            keyObserver.get().onKeyReleased(
                event.key.keysym.scancode,
                event.key.keysym.sym,
                event.key.keysym.mod);
          break;
//          default:
//            LOG_DB() << "Unhandled SDL event " << event.type;
        }
      }
    }

    // TODO: Tick world
    lastTick = SDL_GetTicks();

    if(m_mainWindow.draw())
      return -1;

    // Limit FPS
    if(m_options.getFps() > 0)
    {
      Uint32 fpsDuration = 1000 / m_options.getFps();

      loopDuration = SDL_GetTicks() - lastTick;
      if(loopDuration < fpsDuration)
        SDL_Delay(fpsDuration - loopDuration);
      else
        LOG_WA() << "No time to sleep in event loop!";
    }

    if(SDL_GetTicks() - lastFrame >= 1000)
    {
      LOG_DB() << framesCount << " FPS";
      framesCount = 0;
      lastFrame = SDL_GetTicks();
    }
    else
      framesCount++;
  }

  return 0;
}

//------------------------------------------------------------------------------
int MainLoop::registerKeyObserver(IKeyObserver& observer)
{
  m_keyObservers.push_back(observer);

  return 0;
}

//------------------------------------------------------------------------------
void MainLoop::breakLoop()
{
  m_isRunning = false;
}
}       // namespace
