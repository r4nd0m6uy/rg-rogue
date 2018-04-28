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
#include "Vector2D.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Vector2D::Vector2D():
  m_x(0),
  m_y(0)
{
}

//------------------------------------------------------------------------------
Vector2D::Vector2D(float x, float y):
  m_x(x),
  m_y(y)
{
}

//------------------------------------------------------------------------------
Vector2D::~Vector2D()
{
}

//------------------------------------------------------------------------------
float Vector2D::getX() const
{
  return m_x;
}

//------------------------------------------------------------------------------
float Vector2D::getY() const
{
  return m_y;
}

//------------------------------------------------------------------------------
Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
  m_x += rhs.m_x;
  m_y += rhs.m_y;

  return *this;
}

//------------------------------------------------------------------------------
Vector2D& Vector2D::operator+(const Vector2D& rhs)
{
  *this += rhs;

  return *this;
}

}       // namespace
