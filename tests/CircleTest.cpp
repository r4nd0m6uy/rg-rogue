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
#include "../src/engine/shape/Circle.hpp"

#include <CppUTest/TestHarness.h>

using namespace rgrogue;

//--------------------------------------------------------------------------------------------
TEST_GROUP(Circle)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};

//--------------------------------------------------------------------------------------------
TEST(Circle, getBoundingBox)
{
  std::unique_ptr<IShape> bb;
  Circle c(Vector2D(3, 3), 1);

  c.getBoundingBox(bb);

  CHECK_FALSE(bb.get() == nullptr);
  Polygon& pBb = static_cast<Polygon&>(*bb);
  CHECK_EQUAL(4, pBb.getPoints().size());
  CHECK(Vector2D(4, 2) == pBb.getPoints()[0]);
  CHECK(Vector2D(4, 4) == pBb.getPoints()[1]);
  CHECK(Vector2D(2, 4) == pBb.getPoints()[2]);
  CHECK(Vector2D(2, 2) == pBb.getPoints()[3]);
}

//--------------------------------------------------------------------------------------------
TEST(Circle, getBoundingBoxDefaltConstructor)
{
  std::unique_ptr<IShape> bb;
  Circle c;

  c.getBoundingBox(bb);

  CHECK_FALSE(bb.get() == nullptr);
  Polygon& pBb = static_cast<Polygon&>(*bb);
  CHECK_EQUAL(4, pBb.getPoints().size());
  CHECK(Vector2D(0, 0) == pBb.getPoints()[0]);
  CHECK(Vector2D(0, 0) == pBb.getPoints()[1]);
  CHECK(Vector2D(0, 0) == pBb.getPoints()[2]);
  CHECK(Vector2D(0, 0) == pBb.getPoints()[3]);
}

//--------------------------------------------------------------------------------------------
TEST(Circle, getShapeType)
{
  Circle c;

  CHECK(ShapeType::CIRCLE == c.getShapeType());
}

//--------------------------------------------------------------------------------------------
TEST(Circle, overlapsLineProjectionBiggerThanSegmentNearP2InCircle)
{
  Polygon p({Vector2D(1, 5), Vector2D(3, 5)});
  Circle c(Vector2D(4, 2), 4);

  CHECK(c.overlaps(p));
}

//--------------------------------------------------------------------------------------------
TEST(Circle, overlapsLineCenterColinearP1InCircle)
{
  Polygon p({Vector2D(3, 3), Vector2D(5, 5)});
  Circle c(Vector2D(2, 2), 4);

  CHECK(c.overlaps(p));
}

//--------------------------------------------------------------------------------------------
TEST(Circle, overlapsLine)
{;
  Polygon p({Vector2D(3, 3), Vector2D(5, 5)});
  Circle c(Vector2D(5, 4), 3);

  CHECK(c.overlaps(p));
}

//--------------------------------------------------------------------------------------------
TEST(Circle, overlapsLineDoesnt)
{;
  Polygon p({Vector2D(-5, 0), Vector2D(-2, -2)});
  Circle c(Vector2D(5, 5), 3);

  CHECK_FALSE(c.overlaps(p));
}

//--------------------------------------------------------------------------------------------
TEST(Circle, isInIn)
{;
  Vector2D p(1, 1);
  Circle c(Vector2D(5, 5), 10);

  CHECK(c.isIn(p));
}

//--------------------------------------------------------------------------------------------
TEST(Circle, isInNotIn)
{;
  Vector2D p(1, 1);
  Circle c(Vector2D(5, 5), 1);

  CHECK_FALSE(c.isIn(p));
}

//--------------------------------------------------------------------------------------------
TEST(Circle, constructorCenterRadius)
{
  Vector2D center(5, 6);
  double radius = 432;
  Circle c(center, radius);

  CHECK(center == c.getCenter());
  CHECK_EQUAL(radius, c.getRadius());
}

//--------------------------------------------------------------------------------------------
TEST(Circle, defaultConstructor)
{
  Circle c;

  CHECK(Vector2D(0, 0) == c.getCenter());
  CHECK_EQUAL(0, c.getRadius());
}
