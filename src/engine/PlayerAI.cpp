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
#include "PlayerAI.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
PlayerAI::PlayerAI(IControllable& actor):
  m_actor(actor),
  m_moveRight(Direction::RIGHT),
  m_moveLeft(Direction::LEFT)
{
}

//------------------------------------------------------------------------------
PlayerAI::~PlayerAI()
{
}

//------------------------------------------------------------------------------
void PlayerAI::onKeyPressed(SDL_Scancode scanCode, SDL_Keycode keyCode,
    Uint16 mode)
{
  switch(scanCode)
  {
  case SDL_SCANCODE_A:
    m_moveLeft.execute(m_actor);
    break;
  case SDL_SCANCODE_D:
    m_moveRight.execute(m_actor);
    break;
  case SDL_SCANCODE_SPACE:
    m_jump.execute(m_actor);
    break;
  default:
    break;
  }
}

//------------------------------------------------------------------------------
void PlayerAI::onKeyReleased(SDL_Scancode scanCode, SDL_Keycode keyCode,
    Uint16 mode)
{
  switch(scanCode)
  {
  case SDL_SCANCODE_A:
    m_moveRight.execute(m_actor);
    break;
  case SDL_SCANCODE_D:
    m_moveLeft.execute(m_actor);
    break;
  case SDL_SCANCODE_SPACE:
    m_stopJump.execute(m_actor);
    break;
  default:
    break;
  }
}

}       // namespace
