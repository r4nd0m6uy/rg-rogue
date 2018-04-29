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
#ifndef _RG_ROGUE_PLAYER_AI_HPP_
#define _RG_ROGUE_PLAYER_AI_HPP_

#include "../engine/commands/CommandJump.hpp"
#include "../engine/commands/IControllable.hpp"
#include "../event-loop/IKeyObserver.hpp"

namespace rgrogue {

class PlayerAI:
    public IKeyObserver
{
public:
  PlayerAI(IControllable& actor);
  virtual ~PlayerAI();

  // IKeyObserver
  virtual void onKeyPressed(SDL_Scancode scanCode, SDL_Keycode keyCode,
      Uint16 mode);
  virtual void onKeyReleased(SDL_Scancode scanCode, SDL_Keycode keyCode,
      Uint16 mode);

private:
  IControllable& m_actor;
  CommandJump m_jumpCmd;
};

}       // namespace
#endif  // _RG_ROGUE_PLAYER_AI_HPP_
