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
#include <SDL_image.h>

#include "../logging/Loggers.hpp"

#include "Player.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Player::Player():
  m_baseSpeed(100),
  m_strength(0.1),
  m_speed(0.1),
  m_hitBox(0, 0, 64, 128),
  m_hitBoxPainter(0, 1, 0, 0),
  m_playerTexture(nullptr)
{
  // FIXME: init TexturePool
//  int Mode = GL_RGB;
  m_playerTexture = IMG_Load("../data/out/test.png");
  if(m_playerTexture == nullptr)
  {
    LOG_ER() << "Cannot load player texture";
    return;
  }

//  if(m_playerTexture->format->BytesPerPixel == 4) {
//      Mode = GL_RGBA;
//  }

  glGenTextures(1, &m_texturedId);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, // target
    0, // level, 0 = base, no minimap,
    GL_RGBA, // internalformat
    m_playerTexture->w, // width
    m_playerTexture->h, // height
    0, // border, always 0 in OpenGL ES
    GL_RGBA, // format
    GL_UNSIGNED_BYTE, // type
    m_playerTexture->pixels);
//  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//  SDL_FreeSurface(res_texture);

  GLenum err = glGetError();
  if(err != GL_NO_ERROR)
  {
    LOG_ER() << "Error initializing texture " << err;
    SDL_FreeSurface(m_playerTexture);
    m_playerTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
Player::~Player()
{
  if(m_playerTexture != nullptr)
  {
    SDL_FreeSurface(m_playerTexture);
    glDeleteTextures(1, &m_texturedId);
  }
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
int Player::draw() const
{
  /*
   * GLuint TextureID = 0;

// You should probably use CSurface::OnLoad ... ;)
//-- and make sure the Surface pointer is good!
SDL_Surface* Surface = IMG_Load("someimage.jpg");

glGenTextures(1, &TextureID);
glBindTexture(GL_TEXTURE_2D, TextureID);

int Mode = GL_RGB;

if(Surface->format->BytesPerPixel == 4) {
    Mode = GL_RGBA;
}

glTexImage2D(GL_TEXTURE_2D, 0, Mode, Surface->w, Surface->h, 0, Mode, GL_UNSIGNED_BYTE, Surface->pixels);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   */
//  int Mode = GL_RGB;

  if(m_playerTexture == nullptr)
  {
    LOG_WA() << " NO TEXTURE";
    return m_hitBoxPainter.draw(m_hitBox);
  }

  glBindTexture(GL_TEXTURE_2D,m_texturedId);

//  glActiveTexture(GL_TEXTURE0);
//  glBindTexture(GL_TEXTURE_2D, m_texturedId);

//  glColor3f(0, 0, 1);
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);
  glVertex2f(
      m_hitBox.getX(),
      m_hitBox.getY());
  glTexCoord2f(1.0f,0.0f);
  glVertex2f(
      m_hitBox.getX() + m_hitBox.getWidth(),
      m_hitBox.getY());
  glTexCoord2f(0.0f,1.0f);
  glVertex2f(
      m_hitBox.getX() + m_hitBox.getWidth(),
      m_hitBox.getY() - m_hitBox.getHeight());
  glTexCoord2f(1.0f,1.0f);
  glVertex2f(
      m_hitBox.getX(),
      m_hitBox.getY() - m_hitBox.getHeight());

  glEnd();
  glDisable(GL_TEXTURE_2D);

  return 0;
}

//------------------------------------------------------------------------------
bool Player::isOnFloor()
{
  // FIXME: Collision with object above
  return getY() <= m_hitBox.getHeight();
}

//------------------------------------------------------------------------------
Vector2D& Player::getVelocity()
{
  return m_velocity;
}

//------------------------------------------------------------------------------
float Player::getStrength()
{
  return m_strength;
}

//------------------------------------------------------------------------------
float Player::getBaseSpeed()
{
  return m_baseSpeed;
}

//------------------------------------------------------------------------------
float Player::getSpeed()
{
  return m_speed;
}

//------------------------------------------------------------------------------
void Player::setVelocity(float x, float y)
{
  m_velocity = Vector2D(x, y);
}

}       // namespace
