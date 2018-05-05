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
#include "Circle.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Circle::Circle():
  m_center(0, 0),
  m_radius(0)
{
}

//------------------------------------------------------------------------------
Circle::Circle(const Vector2D& center, double radius):
   m_center(center),
   m_radius(radius)
{
}

//------------------------------------------------------------------------------
Circle::~Circle()
{
}

//------------------------------------------------------------------------------
double Circle::getRadius() const
{
  return m_radius;
}

//------------------------------------------------------------------------------
const Vector2D& Circle::getCenter() const
{
  return m_center;
}

//------------------------------------------------------------------------------
bool Circle::isIn(const Vector2D& p) const
{
  double distance = p.distance(m_center);

  return distance <= m_radius;
}

//------------------------------------------------------------------------------
bool Circle::overlaps(const Polygon& p) const
{
  for(auto& s: p.getSegments())
  {
    Segment ac(s.getP1(), getCenter());
    Vector2D vAc = ac.toVector();
    Vector2D vAb = s.toVector();
    Vector2D projAcAb = vAc.projectionOn(vAb);
    Segment ad(s.getP1(), s.getP1() + projAcAb);
    float adLength = ad.toVector().length();

    /*
     * A * Segment(A,B)
     *    \
     *     \     * C (circle center)
     *    D *
     *       \
     *        \
     *         * B
     */

    // Projection bigger than segment
    if(adLength >= vAb.length())
    {
      // FIXME: Test case!?
      if(this->isIn(s.getP2()))// || this->isIn(s.getP1()))
        return true;
    }
    else if(adLength <= getRadius())
      return true;
  }

  return false;
}

}       // namespace
