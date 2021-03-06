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
#ifndef _RG_ROGUE_MAIN_WINDOW_HPP_
#define _RG_ROGUE_MAIN_WINDOW_HPP_

#include <SDL.h>
#include <SDL_opengl.h>

#include "../options/Options.hpp"
#include "MainMenu.hpp"
#include "ImGuiAdapter.hpp"
#include "scenes/IScene.hpp"
#include "IMainWindow.hpp"

namespace rgrogue {

class MainWindow:
    public IMainWindow
{
public:
  MainWindow(Options& options, IMainLoop& mainLoop, ImGuiAdapter& imgui,
      IScene& scene, IRgRogue& rgRogue);
  ~MainWindow();

  int init();
  int draw();
  void setScene(IScene& scene);

  // IMainWindow
  int applyVideoConfig(Options& options) override;

private:
  Options& m_options;
  MainMenu m_mainMenu;
  ImGuiAdapter& m_imgui;
  std::reference_wrapper<IScene> m_scene;
  SDL_Window* m_sdlWindow;
  SDL_GLContext m_sdlGlContext;
};

}       // namespace
#endif  // _RG_ROGUE_MAIN_WINDOW_HPP_
