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


#include <iostream>



namespace rgrogue {

//------------------------------------------------------------------------------
Polygon::Polygon():
  m_points({Vector2D(0, 0)})
{
}

//------------------------------------------------------------------------------
Polygon::Polygon(const std::vector<Vector2D>& points):
  m_points(points)
{
}

//------------------------------------------------------------------------------
Polygon::~Polygon()
{
}

//------------------------------------------------------------------------------
const std::vector<Vector2D>& Polygon::getPoints() const
{
  return m_points;
}

//------------------------------------------------------------------------------
Vector2D Polygon::getMostLeftPoint() const
{
  Vector2D leftMost = m_points[0];

  for(const auto& p: m_points)
    if(leftMost.getX() > p.getX())
      leftMost = p;

  return leftMost;
}

//------------------------------------------------------------------------------
bool Polygon::isIn(const Vector2D& p) const
{
  int crossingSegements = 0;
  int currentPoint = 0;
  Polygon crtSegment({Vector2D(0, 0), Vector2D(0, 0)});

  for(auto& polPoint: m_points)
  {
    // Two points are touching
    if(polPoint.getX() == p.getX() &&
        polPoint.getY() == p.getX())
      return true;

    crtSegment = Polygon({crtSegment.getPoints()[1], polPoint});

    if(currentPoint >= 1)
    {
      // Point is on the current segment
      float d1 = crtSegment.getPoints()[0].distance(p);
      float d2 = crtSegment.getPoints()[1].distance(p);
      float d3 = crtSegment.getPoints()[0].distance(crtSegment.getPoints()[1]);

      if((d1 + d2) - d3 == 0)
        return true;

      // TODO: casting, get the amount of crossing segments for a polygon
      // If cross this segments
      //   crossingsgemetns++
    }
    currentPoint++;
  }

  // Two points are not on each other
  if(currentPoint == 1)
    return false;

  // Impair amount of crossed segements (ray casting)
  return (crossingSegements % 2) == 0;
}

//------------------------------------------------------------------------------
//const Vector2D& Polygon::getPosition()const
//{
//  return m_pos;
//}
//
////------------------------------------------------------------------------------
//float Polygon::getX() const
//{
//  return m_pos.getX();
//}
//
////------------------------------------------------------------------------------
//float Polygon::getY() const
//{
//  return m_pos.getY();
//}
//
////------------------------------------------------------------------------------
//void Polygon::setPosition(float x, float y)
//{
//  setPosition(Vector2D(x, y));
//}
//
////------------------------------------------------------------------------------
//void Polygon::setPosition(const Vector2D& pos)
//{
//  m_pos = pos;
//}
//
////------------------------------------------------------------------------------
//float Polygon::getWidth() const
//{
//  return m_size.getX();
//}
//
////------------------------------------------------------------------------------
//float Polygon::getHeight() const
//{
//  return m_size.getY();
//}
//
////------------------------------------------------------------------------------
//void Polygon::setSize(float width, float height)
//{
//  setSize(Vector2D(width, height));
//}
//
////------------------------------------------------------------------------------
//void Polygon::setSize(const Vector2D& size)
//{
//  m_size = size;
//}
//
////------------------------------------------------------------------------------
//Polygon& Polygon::operator+(const Vector2D& rhs)
//{
//  m_pos += rhs;
//
//  return *this;
//}
//
////------------------------------------------------------------------------------
//Polygon& Polygon::operator+=(const Vector2D& rhs)
//{
//  return *this + rhs;
//}

}       // namespace
