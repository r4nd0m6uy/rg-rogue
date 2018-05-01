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
#include "../src/engine/shape/Segment.hpp"

#include <CppUTest/TestHarness.h>

using namespace rgrogue;

//--------------------------------------------------------------------------------------------
TEST_GROUP(Segment)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};

//--------------------------------------------------------------------------------------------
TEST(Segment, twoSegementsColinearHIntersect2)
{
  Segment s1(Vector2D(3, 3), Vector2D(10, 3));
  Segment s2(Vector2D(1, 3), Vector2D(5, 3));

  CHECK(s1.intesects(s2));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, twoSegementsColinearHIntersect1)
{
  Segment s1(Vector2D(3, 3), Vector2D(10, 3));
  Segment s2(Vector2D(5, 3), Vector2D(15, 3));

  CHECK(s1.intesects(s2));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, twoSegementsIntesect)
{
  Segment s1(Vector2D(3, 3), Vector2D(3, 10));
  Segment s2(Vector2D(2, 5), Vector2D(10, 5));

  CHECK(s1.intesects(s2));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, twoSegementsDontIntesect)
{
  Segment s1(Vector2D(2, 2), Vector2D(2, 7));
  Segment s2(Vector2D(4, 2), Vector2D(4, 7));

  CHECK_FALSE(s1.intesects(s2));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, orientationCounterClockwise)
{
  Segment s1(Vector2D(1, 1), Vector2D(2, 2));
  Vector2D p(1, 2);

  CHECK_EQUAL(-1, s1.orientation(p));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, orientationClockwise)
{
  Segment s1(Vector2D(1, 1), Vector2D(2, 2));
  Vector2D p(2, 1);

  CHECK_EQUAL(1, s1.orientation(p));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, orientationColinear)
{
  Segment s1(Vector2D(1, 1), Vector2D(2, 2));
  Vector2D p(3, 3);

  CHECK_EQUAL(0, s1.orientation(p));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, isOnPointIsOn)
{
  Vector2D p1(0, 5);
  Vector2D p2(0, 10);
  Vector2D p(0, 7);
  Segment s(p1, p2);

  CHECK(s.isOn(p));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, isOnPointIsOnP2)
{
  Vector2D p1(0, 5);
  Vector2D p2(0, 10);
  Vector2D p = p2;
  Segment s(p1, p2);

  CHECK(s.isOn(p));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, isOnPointIsOnP1)
{
  Vector2D p1(0, 5);
  Vector2D p2(0, 10);
  Vector2D p = p1;
  Segment s(p1, p2);

  CHECK(s.isOn(p));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, isOnPointIsNotOn)
{
  Vector2D p1(0, 5);
  Vector2D p2(0, 10);
  Vector2D p(20, 20);
  Segment s(p1, p2);

  CHECK_FALSE(s.isOn(p));
}

//--------------------------------------------------------------------------------------------
TEST(Segment, constructorWithPoint)
{
  Vector2D p1(4, 5);
  Vector2D p2(6, 7);
  Segment s(p1, p2);

  CHECK(p1 == s.getP1());
  CHECK(p2 == s.getP2());
}


//--------------------------------------------------------------------------------------------
TEST(Segment, defaultConstructor)
{
  Segment s;

  CHECK(Vector2D(0, 0) == s.getP1());
  CHECK(Vector2D(0, 0) == s.getP2());
}
