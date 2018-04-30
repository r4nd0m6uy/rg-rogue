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
#ifndef _RG_ROGUE_SHAPE_HPP_
#define _RG_ROGUE_SHAPE_HPP_

#include "Vector2D.hpp"

namespace rgrogue {

class Polygon
{
public:
  Polygon();
  Polygon(float x, float y, float width, float height);
  virtual ~Polygon();

  // IPolygon
//  virtual const Vector2D& getPosition() const;
//  virtual float getX() const;
//  virtual float getY() const;
//  virtual void setPosition(float x, float y);
//  virtual void setPosition(const Vector2D& pos);
//  virtual float getWidth() const;
//  virtual float getHeight() const;
//  virtual void setSize(float width, float height);
//  virtual void setSize(const Vector2D& size);

//  Polygon& operator+(const Vector2D& rhs);
//  Polygon& operator+=(const Vector2D& rhs);

protected:
  Vector2D m_pos;
  Vector2D m_size;
};

}       // namespace
#endif  // _RG_ROGUE_SHAPE_HPP_
