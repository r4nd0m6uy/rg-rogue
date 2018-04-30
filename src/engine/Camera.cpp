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

#include "Camera.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
Camera::Camera():
  m_zoom(1)
{
}

//------------------------------------------------------------------------------
Camera::Camera(float x, float y, float width, float height):
  m_shape(x, y, width, height),
  m_zoom(1)
{
}

//------------------------------------------------------------------------------
Camera::~Camera()
{
}

//------------------------------------------------------------------------------
float Camera::getZoom() const
{
  return m_zoom;
}

//------------------------------------------------------------------------------
void Camera::setZoom(float zoom)
{
  m_zoom = zoom;
}

//------------------------------------------------------------------------------
void Camera::increaseZoom(float step)
{
  m_zoom += step;
}

//------------------------------------------------------------------------------
void Camera::decreaseZoom(float step)
{
  m_zoom -= step;

  if(m_zoom < 0)
    m_zoom = 0;
}

////------------------------------------------------------------------------------
//float Camera::getScaledWidth() const
//
//{
//  return m_shape.getWidth() * m_zoom;
//}
//
////------------------------------------------------------------------------------
//float Camera::getScaledHeight() const
//{
//  return m_shape.getHeight() * m_zoom;
//}
//
////------------------------------------------------------------------------------
//const Vector2D& Camera::getPosition() const
//{
//  return m_shape.getPosition();
//}
//
////------------------------------------------------------------------------------
//float Camera::getX() const
//{
//  return m_shape.getX();
//}
//
////------------------------------------------------------------------------------
//float Camera::getY() const
//{
//  return m_shape.getY();
//}
//
////------------------------------------------------------------------------------
//void Camera::setPosition(float x, float y)
//{
//  m_shape.setPosition(x, y);
//}
//
////------------------------------------------------------------------------------
//void Camera::setPosition(const Vector2D& pos)
//{
//  m_shape.setPosition(pos);
//}
//
////------------------------------------------------------------------------------
//float Camera::getWidth() const
//{
//  return m_shape.getWidth();
//}
//
////------------------------------------------------------------------------------
//float Camera::getHeight() const
//{
//  return m_shape.getHeight();
//}
//
////------------------------------------------------------------------------------
//void Camera::setSize(float width, float height)
//{
//  m_shape.setSize(width, height);
//}
//
////------------------------------------------------------------------------------
//void Camera::setSize(const Vector2D& size)
//{
//  m_shape.setSize(size);
//}


}       // namespace
