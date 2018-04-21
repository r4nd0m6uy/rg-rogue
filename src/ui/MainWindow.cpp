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
MainWindow::MainWindow():
  m_window(nullptr)
{
}

//------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
  if(m_window)
    SDL_DestroyWindow(m_window);
}

//------------------------------------------------------------------------------
int MainWindow::init()
{
  SDL_Surface* surface;

  if(SDL_Init(SDL_INIT_EVERYTHING))
  {
    LOG_ER() << "SDL initialization failed:" << SDL_GetError();
    return -1;
  }

  m_window = SDL_CreateWindow("rg-rogue",
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      640, 480,
      SDL_WINDOW_OPENGL);
  if(!m_window)
  {
    LOG_ER() << "Error creating SDL window: " << SDL_GetError();
    return -1;
  }

  surface = SDL_GetWindowSurface(m_window);
  if(SDL_FillRect(
      surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF)))
  {
    LOG_ER() << "Error painting SDL window: " << SDL_GetError();
    return -1;
  }

  if(SDL_UpdateWindowSurface(m_window))
  {
    LOG_ER() << "Error Updating SDL window: " << SDL_GetError();
    return -1;
  }

  return 0;
}

}       // namespace
