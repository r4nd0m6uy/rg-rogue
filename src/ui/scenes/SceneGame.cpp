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

static const Vector2D GRAVITY = Vector2D(0, -0.9);

//------------------------------------------------------------------------------
SceneGame::SceneGame(SceneId id):
  Scene(id),
  m_player(0, 30, 30),
  m_playerSpeed(4.2, 10),
  m_lastTick(0)
{
}

//------------------------------------------------------------------------------
SceneGame::~SceneGame()
{
}

//------------------------------------------------------------------------------
int SceneGame::reset()
{
  return 0;
}

//------------------------------------------------------------------------------
int SceneGame::tick()
{
  m_lastTick++;

  if(m_player.getPosition().getX() + m_player.getWidth() > 800 ||
      m_player.getPosition().getX() < -800)
    m_playerSpeed = Vector2D(m_playerSpeed.getX() * -1, m_playerSpeed.getY());

  if(m_player.getPosition().getY() - m_player.getWidth() <= 0)
    m_playerSpeed = Vector2D(m_playerSpeed.getX(), 40);
  else
    m_playerSpeed += GRAVITY;

  m_player += m_playerSpeed;

  return 0;
}

//------------------------------------------------------------------------------
int SceneGame::draw(SDL_Window* window)
{
  int width;
  int height;

  SDL_GetWindowSize(window, &width, &height);
  glViewport (0, 0, (GLsizei)width, (GLsizei)height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
//  glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);
  width *= 3;
  height *= 3;
  glOrtho(-(width / 2), width / 2, -(height / 2), height / 2, 0.0f, 1.0f);

  glBegin(GL_QUADS);

  glColor3f(0.0f, 1.0f, 0.0f); // Green
  glVertex2f(
      m_player.getPosition().getX(),
      m_player.getPosition().getY());
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glVertex2f(
      m_player.getPosition().getX() + m_player.getWidth(),
      m_player.getPosition().getY());
  glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
  glVertex2f(
      m_player.getPosition().getX() + m_player.getWidth(),
      m_player.getPosition().getY() - m_player.getWidth());
  glColor3f(1.0f, 1.0f, 1.0f); // White
  glVertex2f(
      m_player.getPosition().getX(),
      m_player.getPosition().getY() - m_player.getWidth());

  // Ground
  glVertex2f(-(width / 2), 0);
  glVertex2f(width / 2, 0);
  glVertex2f(width / 2, -50);
  glVertex2f(-(width / 2), -50);


  glEnd();

  glPopMatrix();

  return 0;
}

}       // namespace
