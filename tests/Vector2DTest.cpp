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
#include "../src/engine/Vector2D.hpp"

#include <CppUTest/TestHarness.h>

using namespace rgrogue;

//--------------------------------------------------------------------------------------------
TEST_GROUP(Vector2DTest)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};

//--------------------------------------------------------------------------------------------
TEST(Vector2DTest, constructorXY)
{
  float x = 3.4;
  float y = 5.6;
  Vector2D v(x, y);

  CHECK_EQUAL(x, v.getX());
  CHECK_EQUAL(y, v.getY());
}

//--------------------------------------------------------------------------------------------
TEST(Vector2DTest, defaultConstructor)
{
  Vector2D v;

  CHECK_EQUAL(0, v.getX());
  CHECK_EQUAL(0, v.getY());
}
