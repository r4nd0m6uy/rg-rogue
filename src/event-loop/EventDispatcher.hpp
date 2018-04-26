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
#ifndef _RG_ROGUE_EVENT_DISPATCHER_HPP_
#define _RG_ROGUE_EVENT_DISPATCHER_HPP_

#include <SDL.h>

#include <list>
#include <functional>

#include "IKeyObserver.hpp"

namespace rgrogue {

class EventDispatcher
{
public:
  EventDispatcher();
  ~EventDispatcher();

  void dispatch(SDL_Event* event);
  int registerKeyObserver(IKeyObserver& observer);

private:
  std::list<std::reference_wrapper<IKeyObserver>> m_keyObservers;
};

}       // namespace
#endif  // _RG_ROGUE_EVENT_DISPATCHER_HPP_
