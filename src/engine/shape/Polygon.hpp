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
#ifndef _RG_ROGUE_POLYGON_HPP_
#define _RG_ROGUE_POLYGON_HPP_

#include <vector>

#include "IShape.hpp"

namespace rgrogue {

class Polygon:
    public IShape
{
public:
  Polygon();
  Polygon(const std::vector<Vector2D>& points);
  virtual ~Polygon();

  virtual const std::vector<Vector2D>& getPoints() const;
  virtual std::vector<Segment> getSegments() const;
  virtual bool isIn(const Vector2D& p) const;
  virtual bool overlaps(const Polygon& s) const;

  // IShape
  virtual ShapeType getShapeType() const override;
  virtual void getBoundingBox(std::unique_ptr<IShape>& bb) const override;

private:
  std::vector<Vector2D> m_points;

  const Vector2D& getLeftMostPoint() const;
};

std::ostream& operator<<(std::ostream& s, const Polygon& p);

}       // namespace
#endif  // _RG_ROGUE_POLYGON_HPP_
