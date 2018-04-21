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
  m_mainWindow(m_options)
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

  if(m_options.init())
    return -1;

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
  return m_mainLoop.run();
}

}
