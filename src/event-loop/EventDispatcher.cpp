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
#include "EventDispatcher.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
EventDispatcher::EventDispatcher()
{
}

//------------------------------------------------------------------------------
EventDispatcher::~EventDispatcher()
{
}

//------------------------------------------------------------------------------
void EventDispatcher::dispatch(SDL_Event* event)
{
  if(event->key.repeat)
    return;

  switch(event->type)
  {
  case SDL_KEYDOWN:
    for(auto& keyObserver : m_keyObservers)
      keyObserver.get().onKeyPressed(
          event->key.keysym.scancode,
          event->key.keysym.sym,
          event->key.keysym.mod);
    break;
  case SDL_KEYUP:
    for(auto& keyObserver : m_keyObservers)
      keyObserver.get().onKeyReleased(
          event->key.keysym.scancode,
          event->key.keysym.sym,
          event->key.keysym.mod);
    break;
//          default:
//            LOG_DB() << "Unhandled SDL event " << event.type;
  }
}

//------------------------------------------------------------------------------
int EventDispatcher::registerKeyObserver(IKeyObserver& observer)
{
  m_keyObservers.push_back(observer);

  return 0;
}

}       // namespace
