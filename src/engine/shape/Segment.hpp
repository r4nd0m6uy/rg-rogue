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
#ifndef _RG_ROGUE_SEGMENT_HPP_
#define _RG_ROGUE_SEGMENT_HPP_

#include <ostream>

#include "Vector2D.hpp"

namespace rgrogue {

class Segment
{
public:
  Segment();
  Segment(const Vector2D& p1, const Vector2D& p2);
  virtual ~Segment();

  const Vector2D& getP1() const;
  const Vector2D& getP2() const;
  bool isOn(const Vector2D& p) const;
  int orientation(const Vector2D& p) const;
  bool intesects(const Segment& segment) const;
  Vector2D toVector() const;

private:
  Vector2D m_p1;
  Vector2D m_p2;
};

std::ostream& operator<<(std::ostream& s, const Segment& seg);

}       // namespace
#endif  // _RG_ROGUE_POLYGON_HPP_
