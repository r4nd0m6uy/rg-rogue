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
#ifndef _RG_ROGUE_VECTOR_2D_HPP_
#define _RG_ROGUE_VECTOR_2D_HPP_

#include <ostream>

namespace rgrogue {

class Vector2D
{
public:
  Vector2D();
  Vector2D(float x, float y);
  ~Vector2D();

  float getX() const;
  float getY() const;
  float distance(const Vector2D& v) const;
  float crossProduct(const Vector2D& v) const;
  float length() const;

  Vector2D& operator+(const Vector2D& rhs);
  Vector2D& operator+=(const Vector2D& rhs);
  Vector2D& operator*(float rhs);
  Vector2D& operator*=(float rhs);
  bool operator==(const Vector2D& rhs) const;
  bool operator!=(const Vector2D& rhs) const;

private:
  float m_x;
  float m_y;
};

std::ostream& operator<<(std::ostream& s, const Vector2D& v);

}       // namespace
#endif  // _RG_ROGUE_VECTOR_2D_HPP_
