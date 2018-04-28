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
#ifndef _RG_ROGUE_WORLD_HPP_
#define _RG_ROGUE_WORLD_HPP_

#include "Square.hpp"
#include "Rectangle.hpp"

namespace rgrogue {

class World
{
public:
  World();
  ~World();

  int reset();
  void setCameraSize(int width, int height);
  int tick();
  int draw();

private:
  Rectangle m_camera;
  Rectangle m_player;
  Rectangle m_floor;
  Square m_origin;
  Vector2D m_playerSpeed;
};

}       // namespace
#endif  // _RG_ROGUE_WORLD_HPP_
