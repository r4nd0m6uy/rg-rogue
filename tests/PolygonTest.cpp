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

//------------------------------------------------------------------------------
TEST_GROUP(Polygon)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};

//------------------------------------------------------------------------------
TEST(Polygon, getBoundingBoxLine)
{
  std::unique_ptr<IShape> bb;
  Polygon p({Vector2D(1, 2), Vector2D(3, 4)});

  p.getBoundingBox(bb);

  CHECK_FALSE(bb.get() == nullptr);
  Polygon& pBb = static_cast<Polygon&>(*bb);
  CHECK_EQUAL(4, pBb.getPoints().size());
  CHECK(Vector2D(1, 4) == pBb.getPoints()[0]);
  CHECK(Vector2D(3, 4) == pBb.getPoints()[1]);
  CHECK(Vector2D(3, 2) == pBb.getPoints()[2]);
  CHECK(Vector2D(1, 2) == pBb.getPoints()[3]);
}

//------------------------------------------------------------------------------
TEST(Polygon, getBoundingBoxDefaultConstructor)
{
  std::unique_ptr<IShape> bb;
  Polygon p;

  p.getBoundingBox(bb);

  CHECK_FALSE(bb.get() == nullptr);
  Polygon& pBb = static_cast<Polygon&>(*bb);
  CHECK_EQUAL(4, pBb.getPoints().size());
  CHECK(Vector2D(0, 0) == pBb.getPoints()[0]);
  CHECK(Vector2D(0, 0) == pBb.getPoints()[1]);
  CHECK(Vector2D(0, 0) == pBb.getPoints()[2]);
  CHECK(Vector2D(0, 0) == pBb.getPoints()[3]);
}

//------------------------------------------------------------------------------
TEST(Polygon, overlapsTwoTrianglesOverlap)
{
  Vector2D t1p1(0, 0);
  Vector2D t1p2(3, 5);
  Vector2D t1p3(5, 0);
  Polygon t1({t1p1, t1p2, t1p3});
  Vector2D t2p1(3, 1);
  Vector2D t2p2(5, 6);
  Vector2D t2p3(8, 1);
  Polygon t2({t2p1, t2p2, t2p3});

  CHECK(t1.overlaps(t2));
}

//------------------------------------------------------------------------------
TEST(Polygon, overlapsTwoTrianglesAreNotIn)
{
  Vector2D t1p1(0, 0);
  Vector2D t1p2(3, 5);
  Vector2D t1p3(5, 0);
  Polygon t1({t1p1, t1p2, t1p3});
  Vector2D t2p1(100, 0);
  Vector2D t2p2(110, 10);
  Vector2D t2p3(120, 0);
  Polygon t2({t2p1, t2p2, t2p3});

  CHECK_FALSE(t1.overlaps(t2));
}

//------------------------------------------------------------------------------
TEST(Polygon, isInPointInTriangle)
{
  Vector2D p1(0, 0);
  Vector2D p2(3, 5);
  Vector2D p3(5, 0);
  Vector2D point(3, 2);
  Polygon triangle({p1, p2, p3});

  CHECK(triangle.isIn(point));
}

//------------------------------------------------------------------------------
TEST(Polygon, isInPointNotInTriangle)
{
  Vector2D p1(0, 0);
  Vector2D p2(10, 10);
  Vector2D p3(20, 0);
  Vector2D point(-5, -5);
  Polygon triangle({p1, p2, p3});

  CHECK_FALSE(triangle.isIn(point));
}

//------------------------------------------------------------------------------
TEST(Polygon, getSegmentsFromTriangle)
{
  Vector2D p1(0, 0);
  Vector2D p2(3, 5);
  Vector2D p3(1, 1);
  Polygon p({p1, p2, p3});
  std::vector<Segment> s = p.getSegments();

  CHECK_EQUAL(3, s.size());
  CHECK(p1 == s[0].getP1());
  CHECK(p2 == s[0].getP2());
  CHECK(p2 == s[1].getP1());
  CHECK(p3 == s[1].getP2());
  CHECK(p3 == s[2].getP1());
  CHECK(p1 == s[2].getP2());
}

//------------------------------------------------------------------------------
TEST(Polygon, getSegmentsFromLine)
{
  Vector2D p1(4, 5);
  Vector2D p2(6, 7);
  Polygon p({p1, p2});
  std::vector<Segment> s = p.getSegments();

  CHECK_EQUAL(1, s.size());
  CHECK(p1 == s[0].getP1());
  CHECK(p2 == s[0].getP2());
}

//------------------------------------------------------------------------------
TEST(Polygon, getSegmentsWithOnePoint)
{
  Vector2D p1(4, 5);
  Polygon p({p1});
  std::vector<Segment> s = p.getSegments();

  CHECK_EQUAL(1, s.size());
  CHECK(p1 == s[0].getP1());
  CHECK(p1 == s[0].getP2());
}

//------------------------------------------------------------------------------
TEST(Polygon, getSegmentsDefaultConstructor)
{
  Polygon p;
  std::vector<Segment> s = p.getSegments();

  CHECK_EQUAL(1, s.size());
  CHECK(Vector2D(0, 0) == s[0].getP1());
  CHECK(Vector2D(0, 0) == s[0].getP2());
}

//------------------------------------------------------------------------------
TEST(Polygon, constructorWithPoints)
{
  Vector2D p1(1, 1);
  Vector2D p2(3, 3);
  Polygon p({p1, p2});

  CHECK_FALSE(p.getPoints().empty());
  CHECK(p1 == p.getPoints()[0]);
  CHECK(p2 == p.getPoints()[1]);
}

//------------------------------------------------------------------------------
TEST(Polygon, defaultConstructorHasOneOrigin)
{
  Polygon p;

  CHECK_FALSE(p.getPoints().empty());
  CHECK(Vector2D(0, 0) == p.getPoints()[0]);
}

//------------------------------------------------------------------------------
TEST(Polygon, defaultConstructor)
{
  Polygon p;
}
