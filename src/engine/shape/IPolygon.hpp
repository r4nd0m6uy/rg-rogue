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
#ifndef _RG_ROGUE_I_POLYGON_HPP_
#define _RG_ROGUE_I_POLYGON_HPP_

#include <vector>

#include "Vector2D.hpp"

namespace rgrogue {

class IPolygon
{
public:
  IPolygon();
  virtual ~IPolygon();

  virtual const std::vector<Vector2D>& getPoints() const = 0;
//  virtual bool isIn(const Vector2D& p) const = 0;
};

std::ostream& operator<<(std::ostream& s, const IPolygon& p);

}       // namespace
#endif  // _RG_ROGUE_I_POLYGON_HPP_
