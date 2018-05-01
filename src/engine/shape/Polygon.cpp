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
std::vector<Segment> Polygon::getSegments() const
{
  std::vector<Segment> segments;

  if(m_points.size() == 1)
    segments.push_back(Segment(m_points[0], m_points[0]));
  else if(m_points.size() == 2)
    segments.push_back(Segment(m_points[0], m_points[1]));
  else
  {
    for(unsigned int crtPoint = 0 ; crtPoint < m_points.size() ; ++crtPoint)
    {
      if(crtPoint < m_points.size() - 1)
        segments.push_back(Segment(m_points[crtPoint], m_points[crtPoint + 1]));
      else
        segments.push_back(Segment(m_points[crtPoint], m_points[0]));
    }
  }

  return segments;
}

//------------------------------------------------------------------------------
bool Polygon::isIn(const Vector2D& p) const
{
  return false;
//  int crossingSegements = 0;
//  int currentPoint = 0;
//  Polygon rayCastLine({getMostLeftPoint(), p});
//  Polygon crtSegment({Vector2D(0, 0), Vector2D(0, 0)});
////
////  std::cout << *this << " contains " << p << std::endl;
////
//  for(auto& polPoint: m_points)
//  {
//    // Two points are touching
////    if(polPoint == p)
////      return true;
//
//    crtSegment = Polygon({crtSegment.getPoints()[1], polPoint});
//
//    if(currentPoint >= 1)
//    {
//      // Point is on the current segment
//      float d1 = crtSegment.getPoints()[0].distance(p);
//      float d2 = crtSegment.getPoints()[1].distance(p);
//      float d3 = crtSegment.getPoints()[0].distance(crtSegment.getPoints()[1]);
//
//      if((d1 + d2) - d3 == 0)
//      {
//        return true;
//      }
//
//      // FIXME: Check polygon in polygon
//      if(rayCastLine.isIn(crtSegment.getPoints()[0]) ||
//          rayCastLine.isIn(crtSegment.getPoints()[1]))
//        crossingSegements++;
//    }
//    currentPoint++;
//  }

//  // Two points are not on each other
//  if(currentPoint == 1)
//    return false;
//
  // Impair amount of crossed segements (ray casting)
//  return (crossingSegements % 2) == 0;
}

//------------------------------------------------------------------------------
//bool Polygon::isIn(const Polygon& p) const
//{
////  std::cout << *this << " contains " << p << std::endl;
////
////  for(const auto& point: p.getPoints())
////  {
////    std::cout << "CHECK if in " << *this << " contains " << point << std::endl;
////    if(this->isIn(point))
////      return true;
////  }
////
////  return false;
//  return false;
//}


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
std::ostream& operator<<(std::ostream& s, const Polygon& p)
{
  int crtPoint = 1;
  int pCount = p.getPoints().size();

  s << "[";
  for(const auto& point : p.getPoints())
  {
    s << point;
    if(crtPoint < pCount)
      s << ", ";
    ++crtPoint;
  }
  s << "]";

  return s;
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
