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
#ifndef _RG_ROGUE_SCENES_IDS_HPP_
#define _RG_ROGUE_SCENES_IDS_HPP_

#include <cstddef>

namespace rgrogue {

enum class SceneId{
  MAIN_TITLE  = 1,
  GAME        = 2
};

/**
 * Scene ID hash function for GCC prior to 6.1
 * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=60970
 */
struct EnumClassHash
{
  template <typename T>
  std::size_t operator()(T t) const
  {
    return static_cast<std::size_t>(t);
  }
};

}       // namespace
#endif  // _RG_ROGUE_I_SCENE_HPP_
