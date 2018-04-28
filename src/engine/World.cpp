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

#include "World.hpp"

namespace rgrogue {

static Vector2D GRAVITY = Vector2D(0, -0.09);

//------------------------------------------------------------------------------
World::World()
{
}

//------------------------------------------------------------------------------
World::~World()
{
}

//------------------------------------------------------------------------------
int World::reset()
{
  m_player = Square(300, 300, 20);
  m_playerSpeed = Vector2D(20, 1);
  m_origin = Square(-10, 10, 20);

  return 0;
}

//------------------------------------------------------------------------------
int World::tick(float deltaMs)
{
  if(m_player.getPosition().getX() + m_player.getWidth() > 400 ||
      m_player.getPosition().getX() < -400)
    m_playerSpeed = Vector2D(m_playerSpeed.getX() * -1, m_playerSpeed.getY());

  if(m_player.getPosition().getY() - m_player.getWidth() <= 0)
    m_playerSpeed = Vector2D(m_playerSpeed.getX(), 5);
  else
    m_playerSpeed += GRAVITY;

  m_player += m_playerSpeed;

  return 0;
}

//------------------------------------------------------------------------------
int World::draw()
{
  float width = 1000;

  if(m_player.draw())
    return -1;

  // Ground
  glBegin(GL_QUADS);
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glVertex2f(-(width / 2), 0);
  glVertex2f(width / 2, 0);
  glVertex2f(width / 2, -50);
  glVertex2f(-(width / 2), -50);
  glEnd();

  if(m_origin.draw())
    return -1;
  return 0;
}

}       // namespace
