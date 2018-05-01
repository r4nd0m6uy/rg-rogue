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
#include "../src/engine/shape/Polygon.hpp"

#include <CppUTest/TestHarness.h>

using namespace rgrogue;

//--------------------------------------------------------------------------------------------
TEST_GROUP(Polygon)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};

////--------------------------------------------------------------------------------------------
//TEST(Polygon, isInTwoLinesCross)
//{
//  Vector2D l1p1(2, 5);
//  Vector2D l1p2(10, 5);
//  Vector2D l2p1(6, 1);
//  Vector2D l2p2(6, 10);
//  Polygon line1({l1p1, l1p2});
//  Polygon line2({l2p1, l2p2});
//
//  CHECK(line2.isIn(line1));
//}
//
////--------------------------------------------------------------------------------------------
//TEST(Polygon, isInTwoLinesDontCross)
//{
//  Vector2D l1p1(0, 0);
//  Vector2D l1p2(2, 2);
//  Vector2D l2p1(5, 5);
//  Vector2D l2p2(7, 7);
//  Polygon line1({l1p1, l1p2});
//  Polygon line2({l2p1, l2p2});
//
//  CHECK_FALSE(line1.isIn(line2));
//}
//
////--------------------------------------------------------------------------------------------
//TEST(Polygon, isInPointIsInTriangle)
//{
//  Vector2D p1(0, 0);
//  Vector2D p2(10, 10);
//  Vector2D p3(20, 0);
//  Vector2D point(10, 1);
//  Polygon triangle({p1, p2, p3});
//
//  CHECK(triangle.isIn(point));
//}
//
////--------------------------------------------------------------------------------------------
//TEST(Polygon, isInPointIsNotInTriangle)
//{
//  Vector2D p1(0, 0);
//  Vector2D p2(10, 10);
//  Vector2D p3(20, 0);
//  Vector2D point(-5, -5);
//  Polygon triangle({p1, p2, p3});
//
//  CHECK_FALSE(triangle.isIn(point));
//}
//
////--------------------------------------------------------------------------------------------
//TEST(Polygon, mostLeftFromLine)
//{
//  Vector2D p1(2, 2);
//  Vector2D p2(-4, 3);
//  Polygon pol({p1, p2});
//
//  CHECK(p2 == pol.getMostLeftPoint());
//}
//
////--------------------------------------------------------------------------------------------
//TEST(Polygon, mostLeftSingPoint)
//{
//  Vector2D point(2, 2);
//  Polygon pol({point});
//
//  CHECK(point == pol.getMostLeftPoint());
//}
//
////--------------------------------------------------------------------------------------------
//TEST(Polygon, isInpointIsOnALine)
//{
//  Vector2D start(0, 0);
//  Vector2D end(3, 3);
//  Vector2D point(2, 2);
//  Polygon line({start, end});
//
//  CHECK(line.isIn(point));
//}
//
//--------------------------------------------------------------------------------------------
//TEST(Polygon, isInsamePointsAreIn)
//{
//  Vector2D p1(1, 1);
//  Polygon po({p1});
//
//  CHECK(po.isIn(p1));
//}
//
////--------------------------------------------------------------------------------------------
//TEST(Polygon, isIntwoDifferentPointsAreNotIn)
//{
//  Vector2D p1(1, 1);
//  Vector2D p2(3, 3);
//  Polygon po({p2});
//
//  CHECK_FALSE(po.isIn(p1));
//}

//--------------------------------------------------------------------------------------------
TEST(Polygon, constructorWithPoints)
{
  Vector2D p1(1, 1);
  Vector2D p2(3, 3);
  Polygon p({p1, p2});

  CHECK_FALSE(p.getPoints().empty());
  CHECK(p1 == p.getPoints()[0]);
  CHECK(p2 == p.getPoints()[1]);
}

//--------------------------------------------------------------------------------------------
TEST(Polygon, defaultConstructorHasOneOrigin)
{
  Polygon p;

  CHECK_FALSE(p.getPoints().empty());
  CHECK(Vector2D(0, 0) == p.getPoints()[0]);
}

//--------------------------------------------------------------------------------------------
TEST(Polygon, defaultConstructor)
{
  Polygon p;
}
