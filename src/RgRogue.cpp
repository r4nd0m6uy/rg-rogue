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

#include "logging/Loggers.hpp"
#include "RgRogue.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
RgRogue::RgRogue():
  m_isRunning(false)
{
}

//------------------------------------------------------------------------------
RgRogue::~RgRogue()
{
  SDL_Quit();
}

//------------------------------------------------------------------------------
int RgRogue::init()
{
  LOG_DB() << "Initializing";

  if(SDL_Init(SDL_INIT_EVERYTHING))
  {
    LOG_ER() << "SDL initialization failed:" << SDL_GetError();
    return -1;
  }

  if(m_mainWindow.init())
    return -1;

  LOG_IN() << "Initialization done";

  return 0;
}

//------------------------------------------------------------------------------
int RgRogue::runGame()
{
  Uint32 lastTick = SDL_GetTicks();
  SDL_Event event;

  LOG_DB() << "Starting main loop";

  m_isRunning = true;
  while(m_isRunning)
  {
    Uint32 loopDuration;

    while(SDL_PollEvent(&event) != 0 )
    {
      if(event.type == SDL_QUIT)
        m_isRunning = false;
    }

    // TODO: Tick world
    // TODO: Redraw

    loopDuration = SDL_GetTicks() - lastTick;
    if(loopDuration < 16) // ~60 fps
      SDL_Delay(16 - loopDuration);
    else
      LOG_WA() << "No time to sleep in event loop!";

    lastTick = SDL_GetTicks();
  }

  return 0;
}

}
