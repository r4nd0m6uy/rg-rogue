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
#include "Polygon.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Polygon::Polygon()
{
}

//------------------------------------------------------------------------------
Polygon::Polygon(float x, float y, float width, float height):
  m_pos(x, y),
  m_size(width, height)
{
}

//------------------------------------------------------------------------------
Polygon::~Polygon()
{
}

//------------------------------------------------------------------------------
const Vector2D& Polygon::getPosition()const
{
  return m_pos;
}

//------------------------------------------------------------------------------
float Polygon::getX() const
{
  return m_pos.getX();
}

//------------------------------------------------------------------------------
float Polygon::getY() const
{
  return m_pos.getY();
}

//------------------------------------------------------------------------------
void Polygon::setPosition(float x, float y)
{
  setPosition(Vector2D(x, y));
}

//------------------------------------------------------------------------------
void Polygon::setPosition(const Vector2D& pos)
{
  m_pos = pos;
}

//------------------------------------------------------------------------------
float Polygon::getWidth() const
{
  return m_size.getX();
}

//------------------------------------------------------------------------------
float Polygon::getHeight() const
{
  return m_size.getY();
}

//------------------------------------------------------------------------------
void Polygon::setSize(float width, float height)
{
  setSize(Vector2D(width, height));
}

//------------------------------------------------------------------------------
void Polygon::setSize(const Vector2D& size)
{
  m_size = size;
}

//------------------------------------------------------------------------------
Polygon& Polygon::operator+(const Vector2D& rhs)
{
  m_pos += rhs;

  return *this;
}

//------------------------------------------------------------------------------
Polygon& Polygon::operator+=(const Vector2D& rhs)
{
  return *this + rhs;
}

}       // namespace
