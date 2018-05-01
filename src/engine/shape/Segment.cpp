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
#include "Segment.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Segment::Segment()
{
}

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

//------------------------------------------------------------------------------
int Segment::orientation(const Vector2D& p) const
{
  int orientation =
      (m_p2.getY() - m_p1.getY()) * (p.getX() - m_p2.getX()) -
      (m_p2.getX() - m_p1.getX()) * (p.getY() - m_p2.getY());

  if(!orientation)          // colinear
    return 0;
  else if(orientation > 0)  // clockwise
    return 1;
  return -1;                // counterclockwise
}

//------------------------------------------------------------------------------
bool Segment::intesects(const Segment& segment) const
{
  // https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
  int o1 = this->orientation(segment.getP1());
  int o2 = this->orientation(segment.getP2());
  int o3 = segment.orientation(getP1());
  int o4 = segment.orientation(getP2());
  if(o1 != o2 && o3 != o4)
    return true;

  // Colinear lines
  if(!o1 && isOn(segment.getP1()))
    return true;
  if(!o2 && isOn(segment.getP2()))
    return true;

  // FIXME Test case ?!
//  if(!o3 && segment.isOn(this->getP1()))
//    return true;
//  if(!o4 && segment.isOn(this->getP2()))
//    return true;

  return false;
}

//------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& s, const Segment& seg)
{
  s << Polygon({seg.getP1(), seg.getP2()});

  return s;
}

}       // namespace
