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
#include "../../logging/Loggers.hpp"

#include "CommandMove.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
CommandMove::CommandMove(Direction direction):
  m_direction(direction)
{
}

//------------------------------------------------------------------------------
CommandMove::~CommandMove()
{
}

//------------------------------------------------------------------------------
void CommandMove::execute(IControllable& actor)
{
  float newSpeed = actor.getBaseSpeed();
  float direction;

  if(m_direction == Direction::RIGHT)
    direction = 1;
  else  // LEFT
    direction = -1;

  newSpeed += newSpeed * actor.getSpeed();
  newSpeed *= direction;

  actor.getVelocity() += Vector2D(newSpeed, 0);
}

}       // namespace
