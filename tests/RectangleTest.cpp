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
#include "../src/engine/shape/Rectangle.hpp"

#include <CppUTest/TestHarness.h>

using namespace rgrogue;

//------------------------------------------------------------------------------
TEST_GROUP(Rectangle)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};

////------------------------------------------------------------------------------
//TEST(Rectangle, sameOverlaps)
//{
//  Rectangle r(20, -10,  5, 5);
//
//  CHECK(r.overlaps(r));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, TopDesntOverlapBottom)
//{
//  Rectangle rBottom(20, -10,  5, 5);
//  Rectangle rTop(20, 10,  5, 5);
//
//  CHECK_FALSE(rTop.overlaps(rBottom));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, TopOverlapsBottom)
//{
//  Rectangle rBottom(20, -10,  5, 5);
//  Rectangle rTop(20, -9,  5, 5);
//
//  CHECK(rTop.overlaps(rBottom));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, bottomOverlapsTop)
//{
//  Rectangle rBottom(20, -10,  5, 5);
//  Rectangle rTop(20, -9,  5, 5);
//
//  CHECK(rBottom.overlaps(rTop));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, BottomDoesntOverlapsTop)
//{
//  Rectangle rBottom(20, -10,  5, 5);
//  Rectangle rTop(20, 10,  5, 5);
//
//  CHECK_FALSE(rBottom.overlaps(rTop));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, TouchingRightLeftDoesntOverlap)
//{
//  Rectangle rLeft(-10, 10, 5, 5);
//  Rectangle rRight(-5, 10, 5, 5);
//
//  CHECK_FALSE(rRight.overlaps(rLeft));
//  CHECK_FALSE(rLeft.overlaps(rRight));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, RightDoesntOverlapLeft)
//{
//  Rectangle rLeft(-10, 10, 5, 5);
//  Rectangle rRight(10, 10, 5, 5);
//
//  CHECK_FALSE(rRight.overlaps(rLeft));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, leftOverlapsRight)
//{
//  Rectangle rLeft(-10, 10, 5, 5);
//  Rectangle rRight(-9, 10, 5, 5);
//
//  CHECK(rRight.overlaps(rLeft));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, rightOverlapsLeft)
//{
//  Rectangle rLeft(-10, 10, 5, 5);
//  Rectangle rRight(-9, 10, 5, 5);
//
//  CHECK(rLeft.overlaps(rRight));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, leftDoesntOverlapsRight)
//{
//  Rectangle rLeft(-10, 10, 5, 5);
//  Rectangle rRight(10, 10, 5, 5);
//
//  CHECK_FALSE(rLeft.overlaps(rRight));
//}
//
////------------------------------------------------------------------------------
//TEST(Rectangle, constructorXYWH)
//{
//  float x = 3.2;
//  float y = 1.2;
//  float w = 5;
//  float h = 12;
//  Rectangle r(x, y, w, h);
//
//  CHECK_EQUAL(x, r.getX());
//  CHECK_EQUAL(y, r.getY());
//  CHECK_EQUAL(w, r.getWidth());
//  CHECK_EQUAL(h, r.getHeight());
//}

//------------------------------------------------------------------------------
TEST(Rectangle, defaultConstructor)
{
  Rectangle r;

//  CHECK_EQUAL(0, r.getX());
//  CHECK_EQUAL(0, r.getY());
//  CHECK_EQUAL(0, r.getWidth());
//  CHECK_EQUAL(0, r.getHeight());
}
