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

#include "ColoredShape.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
ColoredShape::ColoredShape(float r, float g, float b, float alpha):
  m_r(r),
  m_g(g),
  m_b(b),
  m_a(1)
{
}
//------------------------------------------------------------------------------
ColoredShape::ColoredShape():
  m_r(1),
  m_g(1),
  m_b(1),
  m_a(0)
{
}

//------------------------------------------------------------------------------
ColoredShape::~ColoredShape()
{
}

//------------------------------------------------------------------------------
int ColoredShape::draw(const IShape& shape) const
{
  glColor3f(m_r, m_g, m_b);

  return shape.draw();
}

}       // namespace
