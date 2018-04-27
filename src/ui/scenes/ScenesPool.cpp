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
#include "../../logging/Loggers.hpp"
#include "SceneTitle.hpp"
#include "ScenesPool.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
ScenesPool::ScenesPool()
{
}

//------------------------------------------------------------------------------
ScenesPool::~ScenesPool()
{
}

//------------------------------------------------------------------------------
IScene& ScenesPool::getScene(SceneId id)
{
  const auto& foundScene = m_scenes.find(id);

  if(foundScene == m_scenes.end())
  {
    std::unique_ptr<IScene> newScene;

    buildScene(id, newScene);
    m_scenes[id] = std::move(newScene);

    return *m_scenes[id];
  }

  return *foundScene->second;
}


//------------------------------------------------------------------------------
void ScenesPool::buildScene(SceneId id, std::unique_ptr<IScene>& scene)
{
  switch(id)
  {
  case SceneId::MAIN_TITLE:
    scene.reset(new SceneTitle());
    break;
  default:
    LOG_WA() << "Scene ID " << (int)id << " not found, buildling default!";
    scene.reset(new SceneTitle());
  }
}

}       // namespace
