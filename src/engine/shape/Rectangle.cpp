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

#include "Rectangle.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Rectangle::Rectangle()
{
}

//------------------------------------------------------------------------------
Rectangle::Rectangle(float x, float y, float width, float height):
  Polygon(x, y, width, height)
{
}

//------------------------------------------------------------------------------
Rectangle::~Rectangle()
{
}

//------------------------------------------------------------------------------
bool Rectangle::overlaps(const IPolygon& rhs) const
{
  return this->getX() + this->getWidth() > rhs.getX() &&
      this->getX() < rhs.getX() + rhs.getWidth() &&
      this->getY() > rhs.getY() - getHeight() &&
      this->getY() - this->getHeight() < rhs.getY();
}

//------------------------------------------------------------------------------
int Rectangle::draw() const
{
  glBegin(GL_QUADS);

  glVertex2f(
      m_pos.getX(),
      m_pos.getY());
  glVertex2f(
      m_pos.getX() + m_size.getX(),
      m_pos.getY());
  glVertex2f(
      m_pos.getX() + m_size.getX(),
      m_pos.getY() - m_size.getY());
  glVertex2f(
      m_pos.getX(),
      m_pos.getY() - m_size.getY());

  glEnd();

  return 0;
}

}       // namespace
