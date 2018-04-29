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
#include "../src/engine/shape/Square.hpp"

#include <CppUTest/TestHarness.h>

using namespace rgrogue;

//--------------------------------------------------------------------------------------------
TEST_GROUP(SquareTest)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};

//--------------------------------------------------------------------------------------------
TEST(SquareTest, operatorPlusEqualVector)
{
  float speedX = 3.4;
  float speedY = 4.3;
  Vector2D translation(speedX, speedY);
  float x = 3.2;
  float y = 1.2;
  float w = 5;
  Square s(x, y, w);

  s += translation;

  CHECK_EQUAL(x + speedX, s.getPosition().getX());
  CHECK_EQUAL(y + speedY, s.getPosition().getY());
}

//--------------------------------------------------------------------------------------------
TEST(SquareTest, operatorEqualPlusVector)
{
  float speedX = 3.4;
  float speedY = 4.3;
  Vector2D translation(speedX, speedY);
  float x = 3.2;
  float y = 1.2;
  float w = 5;
  Square s1(x, y, w);
  Square s2 = s1 + translation;

  CHECK_EQUAL(x + speedX, s2.getPosition().getX());
  CHECK_EQUAL(y + speedY, s2.getPosition().getY());
}

//--------------------------------------------------------------------------------------------
TEST(SquareTest, constructorXYW)
{
  float x = 3.2;
  float y = 1.2;
  float w = 5;
  Square s(x, y, w);

  CHECK_EQUAL(x, s.getPosition().getX());
  CHECK_EQUAL(y, s.getPosition().getY());
  CHECK_EQUAL(w, s.getWidth());
}

//--------------------------------------------------------------------------------------------
TEST(SquareTest, defaultConstructor)
{
  Square s;

  CHECK_EQUAL(0, s.getPosition().getX());
  CHECK_EQUAL(0, s.getPosition().getY());
  CHECK_EQUAL(0, s.getWidth());
}
