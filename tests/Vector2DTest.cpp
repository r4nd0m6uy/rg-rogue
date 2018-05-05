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

#include "../src/engine/shape/Vector2D.hpp"

#include <CppUTest/TestHarness.h>

using namespace rgrogue;

//------------------------------------------------------------------------------
TEST_GROUP(Vector2D)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};

//------------------------------------------------------------------------------
TEST(Vector2D, projection)
{
  Vector2D v1(1, 2);
  Vector2D v2(2, 3);
  Vector2D proj = v1.projectionOn(v2);

  DOUBLES_EQUAL(1.2307692, proj.getX(), 0.000001);
  DOUBLES_EQUAL(1.8461538, proj.getY(), 0.000001);
}

//------------------------------------------------------------------------------
TEST(Vector2D, length)
{
  Vector2D v(3, 5);

  DOUBLES_EQUAL(5.8309519, v.length(), 0.000001);
}

//------------------------------------------------------------------------------
TEST(Vector2D, crossProduct)
{
  Vector2D v1(1, 2);
  Vector2D v2(3, 3);

  CHECK_EQUAL(9, v1.crossProduct(v2));
}

//------------------------------------------------------------------------------
TEST(Vector2D, getDistanceFromOtherInQuadrant1)
{
  Vector2D origin(2, 2);
  Vector2D remotePoint(0, 2);

  CHECK_EQUAL(2, origin.distance(remotePoint));
}

//------------------------------------------------------------------------------
TEST(Vector2D, getDistanceFromOriginOnYAxis)
{
  Vector2D origin(0, 0);
  Vector2D remotePoint(0, 5);

  CHECK_EQUAL(5, origin.distance(remotePoint));
}

//------------------------------------------------------------------------------
TEST(Vector2D, getDistanceFromOriginOnXAxis)
{
  Vector2D origin(0, 0);
  Vector2D remotePoint(0, 2);

  CHECK_EQUAL(2, origin.distance(remotePoint));
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorMinusEqualVector)
{
  Vector2D v1(3, 5);
  Vector2D v2(5, 6);

  v1 -= v2;

  CHECK(Vector2D(-2, -1) == v1);
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorMinusVector)
{
  Vector2D v1(3, 5);
  Vector2D v2(5, 6);

  CHECK(Vector2D(-2, -1) == v1 - v2);
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorTimeEqalFloat)
{
  float mul = 4.2;
  float x = 3.4;
  float y = 2.1;
  Vector2D v1(x, y);

  v1 *= mul;

  CHECK_EQUAL(x * mul, v1.getX());
  CHECK_EQUAL(y * mul, v1.getY());
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorTimeFloat)
{
  float mul = 4.2;
  float x = 3.4;
  float y = 2.1;
  Vector2D v1(x, y);
  Vector2D v2 = v1 * mul;

  CHECK_EQUAL(x * mul, v2.getX());
  CHECK_EQUAL(y * mul, v2.getY());
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorEqualEqualNotEqual)
{
  Vector2D v1(3, 5);
  Vector2D v2(6, 7);

  CHECK_FALSE(v1 == v2);
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorNotEqualForEqual)
{
  Vector2D v1(3, 5);
  Vector2D v2 = v1;

  CHECK_FALSE(v1 != v2);
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorEqualEqualForEqual)
{
  Vector2D v1(3, 5);
  Vector2D v2 = v1;

  CHECK(v1 == v2);
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorEqualPlus)
{
  float x1 = 1.2;
  float y1 = 5.6;
  Vector2D v1(x1, y1);
  float x2 = -3.4;
  float y2 = 7.9;
  Vector2D v2(x2, y2);
  Vector2D v3;

  v3 = v1 + v2;

  CHECK_EQUAL(x1 + x2, v3.getX());
  CHECK_EQUAL(y1 + y2, v3.getY());
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorEqual)
{
  float x = 1.2;
  float y = 5.6;
  Vector2D v1(x, y);
  Vector2D v2 = v1;

  CHECK_EQUAL(x, v2.getX());
  CHECK_EQUAL(y, v2.getY());
}

//------------------------------------------------------------------------------
TEST(Vector2D, operatorPlusEqual)
{
  float x1 = 1.2;
  float y1 = 5.6;
  Vector2D v1(x1, y1);
  float x2 = -3.4;
  float y2 = 7.9;
  Vector2D v2(x2, y2);

  v1 += v2;

  CHECK_EQUAL(x1 + x2, v1.getX());
  CHECK_EQUAL(y1 + y2, v1.getY());
}

//------------------------------------------------------------------------------
TEST(Vector2D, constructorXY)
{
  float x = 3.4;
  float y = 5.6;
  Vector2D v(x, y);

  CHECK_EQUAL(x, v.getX());
  CHECK_EQUAL(y, v.getY());
}

//------------------------------------------------------------------------------
TEST(Vector2D, defaultConstructor)
{
  Vector2D v;

  CHECK_EQUAL(0, v.getX());
  CHECK_EQUAL(0, v.getY());
}
