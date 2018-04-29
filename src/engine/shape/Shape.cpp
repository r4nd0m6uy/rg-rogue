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
float Shape::getX() const
{
  return m_pos.getX();
}

//------------------------------------------------------------------------------
float Shape::getY() const
{
  return m_pos.getY();
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
  return m_size.getX();
}

//------------------------------------------------------------------------------
float Shape::getHeight() const
{
  return m_size.getY();
}

//------------------------------------------------------------------------------
void Shape::setSize(float width, float height)
{
  setSize(Vector2D(width, height));
}

//------------------------------------------------------------------------------
void Shape::setSize(const Vector2D& size)
{
  m_size = size;
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
