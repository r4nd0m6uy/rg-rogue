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
#ifndef _RG_ROGUE_CAMERA_HPP_
#define _RG_ROGUE_CAMERA_HPP_

#include "Rectangle.hpp"

namespace rgrogue {

class Camera:
    public IShape
{
public:
  Camera();
  Camera(float x, float y, float width, float height);
  virtual ~Camera();

  void increaseZoom(float step);
  void decreaseZoom(float step);
  float getScaledWidth() const;
  float getScaledHeight() const;
  float getZoom() const;

  // IShape
  virtual const Vector2D& getPosition() const override;
  virtual float getX() const override;
  virtual float getY() const override;
  virtual void setPosition(float x, float y) override;
  virtual void setPosition(const Vector2D& pos) override;
  virtual float getWidth() const override;
  virtual float getHeight() const override;
  virtual void setSize(float width, float height) override;
  virtual void setSize(const Vector2D& size) override;
  // FIXME: Remove me "Drawable"
  virtual int draw() const override;

private:
  Rectangle m_shape;
  float m_zoom;
};

}       // namespace
#endif  // _RG_ROGUE_CAMERA_HPP_
