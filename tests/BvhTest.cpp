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
#include "../src/engine/Bvh.hpp"
#include "../src/engine/WorldObject.hpp"

#include <CppUTest/TestHarness.h>

using namespace rgrogue;

//------------------------------------------------------------------------------
TEST_GROUP(Bvh)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};

//------------------------------------------------------------------------------
TEST(Bvh, getObjectsFound)
{
  Vector2D p1(1, 1);
  Vector2D p2(2, 2);
  Vector2D p3(3, 0);
  std::unique_ptr<IShape> p(new Polygon({p1, p2, p3}));
  IWorldObject* addedObject = new WorldObject(p);
  std::unique_ptr<IWorldObject> object(addedObject);
  Rectangle find(0, 10, 10, 10);
  std::list<std::reference_wrapper<IWorldObject> > found;
  Bvh bvh;

  bvh.addObject(object);
  bvh.getObjects(find, found);

  CHECK_EQUAL(1, found.size());
  POINTERS_EQUAL(addedObject, &found.front().get());
}

//------------------------------------------------------------------------------
TEST(Bvh, getObjectsNotFound)
{
  std::unique_ptr<IShape> p(
      new Polygon({Vector2D(1, 1), Vector2D(2, 2), Vector2D(3, 0)}));
  std::unique_ptr<IWorldObject> object(new WorldObject(p));
  Polygon find;
  std::list<std::reference_wrapper<IWorldObject> > found;
  Bvh bvh;

  bvh.addObject(object);
  bvh.getObjects(find, found);

  CHECK(found.empty());
}

//------------------------------------------------------------------------------
TEST(Bvh, getObjectsNotFoundButInputListCleared)
{
  std::unique_ptr<IShape> p(new Polygon());
  WorldObject object(p);
  Polygon find;
  std::list<std::reference_wrapper<IWorldObject> > found;
  Bvh bvh;

  found.push_back(object);

  bvh.getObjects(find, found);

  CHECK(found.empty());
}

//------------------------------------------------------------------------------
TEST(Bvh, addObject)
{
  std::unique_ptr<IShape> p(new Polygon());
  std::unique_ptr<IWorldObject> object(new WorldObject(p));
  Bvh bvh;

  bvh.addObject(object);
}

//------------------------------------------------------------------------------
TEST(Bvh, constructor)
{
  Bvh bvh;
}
