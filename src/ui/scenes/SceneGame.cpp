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
#include <cmath>

#include <SDL_opengl.h>

#include "../../logging/Loggers.hpp"
#include "SceneGame.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
SceneGame::SceneGame(SceneId id):
  Scene(id)
{
}

//------------------------------------------------------------------------------
SceneGame::~SceneGame()
{
}

//------------------------------------------------------------------------------
int SceneGame::reset()
{
  return m_world.reset();
}

//------------------------------------------------------------------------------
int SceneGame::tick()
{
  return m_world.tick();
}

//------------------------------------------------------------------------------
int SceneGame::draw(SDL_Window* window)
{
  int width;
  int height;

  SDL_GetWindowSize(window, &width, &height);
  m_world.setCameraSize(width, height);

  m_world.draw();

  return 0;
}

}       // namespace
