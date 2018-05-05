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
#include <SDL_opengl.h>

#include "../logging/Loggers.hpp"

#include "World.hpp"

namespace rgrogue {

static Vector2D GRAVITY = Vector2D(0, -8.9);

//------------------------------------------------------------------------------
World::World()
{
}

//------------------------------------------------------------------------------
World::~World()
{
}

//------------------------------------------------------------------------------
//int World::reset()
//{
//  return 0;
//}

//------------------------------------------------------------------------------
//int World::tick()
//{
//  // FIXME: Always 60 fps, get actual tick in ms
//  float deltaMs = 1000 / 60;
//
//  // Apply gravity (each moving objects)
//  m_player.getVelocity() += GRAVITY;
//
//  m_player.move(deltaMs);
//
//  // Quick and dirty collision
//  // FIXME: Use prediction can pass through wall, any other size!
////  if(m_player.getHitBox().overlaps(m_floor))
////  {
////    m_player.setPosition(
////        m_player.getX(), m_floor.getY() + m_player.getHeight());
////    m_player.setVelocity(m_player.getVelocity().getX(), 0);
////  }
////
////  if(m_player.getHitBox().overlaps(m_platform))
////  {
////    m_player.setPosition(
////        m_player.getX(), m_platform.getY() + m_player.getHeight());
////    m_player.setVelocity(m_player.getVelocity().getX(), 0);
////  }
//
//  // Center camera to player
////  Vector2D playerCenter(
////      m_player.getX() + (m_player.getWidth() / 2),
////      m_player.getY() - (m_player.getHeight() / 2));
//
////  m_camera.setPosition(
////      playerCenter.getX() - (m_camera.getScaledWidth() / 2),
////      playerCenter.getY() + (m_camera.getScaledHeight() / 2));
//
//  return 0;
//}

}       // namespace
