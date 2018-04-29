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
#ifndef _RG_ROGUE_PLAYER_HPP_
#define _RG_ROGUE_PLAYER_HPP_

#include "shape/Rectangle.hpp"
#include "../ui/decorators/ColoredShape.hpp"

namespace rgrogue {

class Player
{
public:
  Player();
  virtual ~Player();

  void move(float deltaMs);
  void setPosition(float x, float y);
  float getX();
  float getY();
  float getWidth();
  float getHeight();
  Vector2D& getVelocity();
  void setVelocity(float x, float y);
  int draw() const;

private:
  Vector2D m_velocity;
  Rectangle m_hitBox;
  ColoredShape m_hitBoxPainter;
};

}       // namespace
#endif  // _RG_ROGUE_I_SHAPE_HPP_
