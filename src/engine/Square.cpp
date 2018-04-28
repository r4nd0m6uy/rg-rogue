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
float Square::getWidth() const
{
  return m_width;
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
