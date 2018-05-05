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
  unsigned int crossingSegements = 0;
  Segment rayCast(Vector2D(-1, 0) + getLeftMostPoint(), p);

  for(const auto& s: getSegments())
    if(rayCast.intesects(s))
      crossingSegements++;

  return crossingSegements &= 1; // %2 == 0
}

//------------------------------------------------------------------------------
bool Polygon::overlaps(const Polygon& p) const
{
  for(auto& segThis: getSegments())
    for(auto& segShape: p.getSegments())
      if(segThis.intesects(segShape))
        return true;

  return false;
}

//------------------------------------------------------------------------------
const Vector2D& Polygon::getLeftMostPoint() const
{
  int index = 0;

  for(unsigned int i = 0 ; i < m_points.size() ; ++i)
    if(m_points[index].getX() > m_points[i].getX())
      index = i;

  return m_points[index];
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

}       // namespace
