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
#include <cmath>

#include <SDL_opengl.h>

#include "../../logging/Loggers.hpp"
#include "SceneGame.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
SceneGame::SceneGame(SceneId id):
  Scene(id),
  m_isRegistered(false)
{
}

//------------------------------------------------------------------------------
SceneGame::~SceneGame()
{
}

//------------------------------------------------------------------------------
int SceneGame::onDisplayed(IMainLoop& mainLoop)
{
  // FIXME: Deregister key handler
  if(!m_isRegistered)
  {
    mainLoop.registerKeyObserver(*this);
    m_isRegistered = true;
  }

  return m_world.reset();
}

//------------------------------------------------------------------------------
int SceneGame::tick()
{
  return m_world.tick();
}

//------------------------------------------------------------------------------
int SceneGame::draw(SDL_Window* window)
{
  int width;
  int height;

  SDL_GetWindowSize(window, &width, &height);
  m_world.setCameraSize(width, height);

  m_world.draw();

  return 0;
}

//------------------------------------------------------------------------------
int SceneGame::onHidden(IMainLoop& mainLoop)
{
  // FIXME: Deregister key event handler
  return 0;
}

//------------------------------------------------------------------------------
void SceneGame::onKeyPressed(SDL_Scancode scanCode, SDL_Keycode keyCode,
    Uint16 mode)
{
  switch(scanCode)
  {
  case SDL_SCANCODE_A:
    m_world.getPlayerSpeed() += Vector2D(-100, 0);
    break;
  case SDL_SCANCODE_D:
    m_world.getPlayerSpeed() += Vector2D(100, 0);
    break;
  case SDL_SCANCODE_SPACE:
    if(m_world.getPlayerSpeed().getY() == 0)
      m_world.getPlayerSpeed() += Vector2D(0, 200);
    break;
  default:
    LOG_DB() << "Hello " << scanCode;
    break;
  }


}

//------------------------------------------------------------------------------
void SceneGame::onKeyReleased(SDL_Scancode scanCode, SDL_Keycode keyCode,
    Uint16 mode)
{
  switch(scanCode)
  {
  case SDL_SCANCODE_A:
    m_world.getPlayerSpeed() += Vector2D(100, 0);
    break;
  case SDL_SCANCODE_D:
    m_world.getPlayerSpeed() += Vector2D(-100, 0);
    break;
  default:
    break;
  }
}

}       // namespace
