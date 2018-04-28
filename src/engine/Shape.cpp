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

#include "Shape.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Shape::Shape()
{
}

//------------------------------------------------------------------------------
Shape::Shape(float x, float y, float width, float height):
  m_pos(x, y),
  m_size(width, height)
{
}

//------------------------------------------------------------------------------
Shape::~Shape()
{
}

//------------------------------------------------------------------------------
const Vector2D& Shape::getPosition()const
{
  return m_pos;
}

//------------------------------------------------------------------------------
void Shape::setPosition(float x, float y)
{
  setPosition(Vector2D(x, y));
}

//------------------------------------------------------------------------------
void Shape::setPosition(const Vector2D& pos)
{
  m_pos = pos;
}

//------------------------------------------------------------------------------
float Shape::getWidth() const
{
  return m_size.getY();
}

//------------------------------------------------------------------------------
float Shape::getHeight() const
{
  return m_size.getX();
}

//------------------------------------------------------------------------------
int Shape::draw() const
{
  glBegin(GL_QUADS);

  glColor3f(0.0f, 1.0f, 0.0f); // Green
  glVertex2f(
      m_pos.getX(),
      m_pos.getY());
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glVertex2f(
      m_pos.getX() + m_size.getX(),
      m_pos.getY());
  glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
  glVertex2f(
      m_pos.getX() + m_size.getX(),
      m_pos.getY() - m_size.getY());
  glColor3f(1.0f, 1.0f, 1.0f); // White
  glVertex2f(
      m_pos.getX(),
      m_pos.getY() - m_size.getY());

  glEnd();

  return 0;
}

//------------------------------------------------------------------------------
Shape& Shape::operator+(const Vector2D& rhs)
{
  m_pos += rhs;

  return *this;
}

//------------------------------------------------------------------------------
Shape& Shape::operator+=(const Vector2D& rhs)
{
  return *this + rhs;
}

}       // namespace
