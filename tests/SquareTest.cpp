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

//------------------------------------------------------------------------------
TEST_GROUP(Square)
{
  TEST_SETUP()
  {
  }

  TEST_TEARDOWN()
  {
  }
};


//------------------------------------------------------------------------------
TEST(Square, constructor)
{
  Square s(8, 9, 4);

  CHECK_EQUAL(4, s.getPoints().size());
  CHECK(Vector2D(8, 9) == s.getPoints()[0]);
  CHECK(Vector2D(12, 9) == s.getPoints()[1]);
  CHECK(Vector2D(12, 5) == s.getPoints()[2]);
  CHECK(Vector2D(8, 5) == s.getPoints()[3]);
}
