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
#include "../logging/Loggers.hpp"

#include "Player.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Player::Player():
  m_hitBox(0, 0, 20, 120)
{
}

//------------------------------------------------------------------------------
Player::~Player()
{
}

//------------------------------------------------------------------------------
void Player::move(float deltaMs)
{
  m_hitBox += Vector2D(m_velocity) * (1 / deltaMs);
}

//------------------------------------------------------------------------------
void Player::setPosition(float x, float y)
{
  m_hitBox.setPosition(x, y);
}

//------------------------------------------------------------------------------
float Player::getX()
{
  return m_hitBox.getX();
}

//------------------------------------------------------------------------------
float Player::getY()
{
  return m_hitBox.getY();
}

//------------------------------------------------------------------------------
float Player::getWidth()
{
  return m_hitBox.getWidth();
}

//------------------------------------------------------------------------------
float Player::getHeight()
{
  return m_hitBox.getHeight();
}

//------------------------------------------------------------------------------
Vector2D& Player::getVelocity()
{
  return m_velocity;
}

//------------------------------------------------------------------------------
int Player::draw() const
{
  return m_hitBox.draw();
}

//------------------------------------------------------------------------------
void Player::setVelocity(float x, float y)
{
  m_velocity = Vector2D(x, y);
}

}       // namespace
