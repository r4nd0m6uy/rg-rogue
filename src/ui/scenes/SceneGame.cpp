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
  // FIXME: Always 60 fps, get actual tick in ms
  return m_world.tick(1000 / 60);
}

//------------------------------------------------------------------------------
int SceneGame::draw(SDL_Window* window)
{
  int width;
  int height;

  SDL_GetWindowSize(window, &width, &height);
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
//  glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);
//  width *= 3;
//  height *= 3;
  glOrtho(-(width / 2), width / 2, -(height / 2), height / 2, 0.0f, 1.0f);

  m_world.draw();

  glPopMatrix();

  return 0;
}

}       // namespace
