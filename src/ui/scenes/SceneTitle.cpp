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
#include <SDL_opengl.h>

#include "../../logging/Loggers.hpp"

#include "SceneTitle.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
SceneTitle::SceneTitle(SceneId id):
    Scene(id)
{
}

//------------------------------------------------------------------------------
SceneTitle::~SceneTitle()
{
}

//------------------------------------------------------------------------------
int SceneTitle::reset()
{
  return 0;
}

//------------------------------------------------------------------------------
int SceneTitle::tick()
{
  return 0;
}

//------------------------------------------------------------------------------
int SceneTitle::draw(SDL_Window* window)
{
  int width;
  int height;

  SDL_GetWindowSize(window, &width, &height);
  glViewport (0, 0, (GLsizei)width, (GLsizei)height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glPopMatrix();

  glBegin(GL_QUADS);
  glVertex2f(-1, 0);
  glVertex2f(1, -0.5f);
  glVertex2f(0.5f, 0.5f);
  glVertex2f(-0.5f, 0.5f);
  glEnd();

  glPopMatrix();

  return 0;
}

}       // namespace
