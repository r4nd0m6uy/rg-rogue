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
    Scene(id),
    m_radius(50),
    m_xPos(0),
    m_yPos(0 + m_radius),
    m_xSpeed(4.2),
    m_ySpeed(10),
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

  m_xPos += m_xSpeed;
  m_yPos += m_ySpeed;

  if(m_xPos + m_radius > 400 || m_xPos < -400)
    m_xSpeed *= -1;

  if(m_yPos - m_radius <= 0)
    m_ySpeed = 10;
  else
    m_ySpeed -= 0.2;


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
//  width *= 3;
//  height *= 3;
  glOrtho(-(width / 2), width / 2, -(height / 2), height / 2, 0.0f, 1.0f);

  glBegin(GL_QUADS);

  glColor3f(0.0f, 1.0f, 0.0f); // Green
  glVertex2f(m_xPos, m_yPos);
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glVertex2f(m_xPos + m_radius, m_yPos);
  glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
  glVertex2f(m_xPos + m_radius, m_yPos - m_radius);
  glColor3f(1.0f, 1.0f, 1.0f); // White
  glVertex2f(m_xPos, m_yPos - m_radius);

  glVertex2f(-(width / 2), 0);
  glVertex2f(width / 2, 0);
  glVertex2f(width / 2, -50);
  glVertex2f(-(width / 2), -50);


  glEnd();

  glPopMatrix();

  return 0;
}

}       // namespace
