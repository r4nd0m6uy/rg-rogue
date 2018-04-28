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
#ifndef _RG_ROGUE_SQUARE_HPP_
#define _RG_ROGUE_SQUARE_HPP_

#include "Vector2D.hpp"

namespace rgrogue {

class Square
{
public:
  Square();
  Square(float x, float y, float width);
  ~Square();

  const Vector2D& getPosition() const;
  float getWidth() const;
  int draw() const;
  void setPosition(float x, float y);
  void setPosition(const Vector2D& pos);

  Square& operator+(const Vector2D& rhs);
  Square& operator+=(const Vector2D& rhs);

private:
  Vector2D m_pos;
  float m_width;
};

}       // namespace
#endif  // _RG_ROGUE_SQUARE_HPP_
