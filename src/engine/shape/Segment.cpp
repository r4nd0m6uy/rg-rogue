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
#include "Segment.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Segment::Segment(const Vector2D& p1, const Vector2D& p2):
  m_p1(p1),
  m_p2(p2)
{
}

//------------------------------------------------------------------------------
Segment::~Segment()
{
}

//------------------------------------------------------------------------------
const Vector2D& Segment::getP1() const
{
  return m_p1;
}

//------------------------------------------------------------------------------
const Vector2D& Segment::getP2() const
{
  return m_p2;
}

//------------------------------------------------------------------------------
bool Segment::isOn(const Vector2D& p) const
{
  float distanceP1;
  float distanceP2;
  float distanceSegment;

  distanceP1 = m_p1.distance(p);
  distanceP2 = m_p2.distance(p);
  distanceSegment = m_p1.distance(m_p2);

  return distanceP1 + distanceP2 == distanceSegment;
}

}       // namespace
