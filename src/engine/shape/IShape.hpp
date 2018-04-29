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
#ifndef _RG_ROGUE_I_SHAPE_HPP_
#define _RG_ROGUE_I_SHAPE_HPP_

#include "Vector2D.hpp"

namespace rgrogue {

class IShape
{
public:
  IShape();
  virtual ~IShape();

  virtual const Vector2D& getPosition() const = 0;
  virtual float getX() const = 0;
  virtual float getY() const = 0;
  virtual void setPosition(float x, float y) = 0;
  virtual void setPosition(const Vector2D& pos) = 0;
  virtual float getWidth() const = 0;
  virtual float getHeight() const = 0;
  virtual void setSize(float width, float height) = 0;
  virtual void setSize(const Vector2D& size) = 0;
};

}       // namespace
#endif  // _RG_ROGUE_I_SHAPE_HPP_
