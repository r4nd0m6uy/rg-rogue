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
#include <cassert>

#include "Bvh.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Bvh::Bvh()
{
}

//------------------------------------------------------------------------------
Bvh::~Bvh()
{
}

//------------------------------------------------------------------------------
void Bvh::addObject(std::unique_ptr<IWorldObject>& object)
{
  m_objects.push_back(std::move(object));
}

//------------------------------------------------------------------------------
void Bvh::getObjects(const Polygon& p,
      std::list<std::reference_wrapper<IWorldObject> >& objects)
{
  objects.clear();

  // Planning to implement a balanced search tree ...
  for(auto& object: m_objects)
  {
    IShape& s = (*object).getShape();

    switch(s.getShapeType())
    {
    case ShapeType::POLYGON:
    {
      Polygon& crtPolygon = static_cast<Polygon&>(s);

      if(p.overlaps(crtPolygon))
        objects.push_back(*object);
    }
    break;
    case ShapeType::CIRCLE:
      // TODO
    default:
      assert(0);
    }
  }
}

}       // namespace
