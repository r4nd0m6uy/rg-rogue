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

#include "Square.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Square::Square():
    m_width(0)
{
}

//------------------------------------------------------------------------------
Square::Square(float x, float y, float width):
    m_pos(x, y),
    m_width(width)
{
}

//------------------------------------------------------------------------------
Square::~Square()
{
}

//------------------------------------------------------------------------------
const Vector2D& Square::getPosition() const
{
  return m_pos;
}

//------------------------------------------------------------------------------
void Square::setPosition(float x, float y)
{
  setPosition(Vector2D(x, y));
}

//------------------------------------------------------------------------------
void Square::setPosition(const Vector2D& pos)
{
  m_pos = pos;
}

//------------------------------------------------------------------------------
float Square::getWidth() const
{
  return m_width;
}

//------------------------------------------------------------------------------
int Square::draw() const
{
  glBegin(GL_QUADS);

  glColor3f(0.0f, 1.0f, 0.0f); // Green
  glVertex2f(
      m_pos.getX(),
      m_pos.getY());
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glVertex2f(
      m_pos.getX() + m_width,
      m_pos.getY());
  glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
  glVertex2f(
      m_pos.getX() + m_width,
      m_pos.getY() - m_width);
  glColor3f(1.0f, 1.0f, 1.0f); // White
  glVertex2f(
      m_pos.getX(),
      m_pos.getY() - m_width);

  glEnd();

  return 0;
}

//------------------------------------------------------------------------------
Square& Square::operator+(const Vector2D& rhs)
{
  m_pos += rhs;

  return *this;
}

//------------------------------------------------------------------------------
Square& Square::operator+=(const Vector2D& rhs)
{
  return *this + rhs;
}

}       // namespace
