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

#include "../logging/Loggers.hpp"

#include "World.hpp"

namespace rgrogue {

static Vector2D GRAVITY = Vector2D(0, -8.9);

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
  m_player = Rectangle(0, 800, 50, 100);
  m_playerSpeed = Vector2D(0, 0);
  m_origin = Square(-10, 10, 20);
  m_floor =  Rectangle(-500, 0, 1000, 50);

  return 0;
}

//------------------------------------------------------------------------------
void World::setCameraSize(int width, int height)
{
  m_camera.setSize(width, height);
}

//------------------------------------------------------------------------------
Vector2D& World::getPlayerSpeed()
{
  return m_playerSpeed;
}

//------------------------------------------------------------------------------
int World::tick()
{
  // FIXME: Always 60 fps, get actual tick in ms
  float deltaMs = 1000 / 60;

  // Apply gravity
  if(m_player.getPosition().getY() - m_player.getWidth() <= 0)
  {
    if(m_playerSpeed.getY() < 0)
      m_playerSpeed = Vector2D(m_playerSpeed.getX(), 0);
    m_player.setPosition(m_player.getPosition().getX(), m_player.getWidth());
  }
  else
    m_playerSpeed += GRAVITY;

  // Center camera to player
  m_player += Vector2D(m_playerSpeed) * (1 / deltaMs);
  Vector2D playerCenter(
      m_player.getX() + (m_player.getWidth() / 2),
      m_player.getY() + (m_player.getHeight() / 2));

  m_camera.setPosition(
      playerCenter.getX() - (m_camera.getWidth() / 2),
      playerCenter.getY() + (m_camera.getHeight() / 2));

  return 0;
}

//------------------------------------------------------------------------------
int World::draw()
{
  glViewport(0, 0, (GLsizei)m_camera.getWidth(), (GLsizei)m_camera.getHeight());

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(
    m_camera.getX(),
    m_camera.getX() + m_camera.getWidth(),
    m_camera.getY() - m_camera.getHeight(), m_camera.getY(),
    0.0f, 1.0f);

  if(m_player.draw())
    return -1;
  if(m_floor.draw())
    return -1;
  if(m_origin.draw())
    return -1;

  glPopMatrix();

  return 0;
}

}       // namespace
