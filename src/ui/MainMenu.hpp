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
#ifndef _RG_ROGUE_MAIN_MENU_HPP_
#define _RG_ROGUE_MAIN_MENU_HPP_

#include "../options/Options.hpp"
#include "../event-loop/IMainLoop.hpp"
#include "../IRgRogue.hpp"
#include "IMainWindow.hpp"

namespace rgrogue {

class MainMenu:
    public IKeyObserver
{
public:
  MainMenu(Options& options, IMainLoop& mainLoop, IMainWindow& mainWindow,
      IRgRogue& rgRogue);
  ~MainMenu();

  int init();
  void setVisible(bool isVisible);
  int draw();

  // IKeyObserver
  virtual void onKeyPressed(SDL_Scancode scanCode, SDL_Keycode keyCode,
      Uint16 mode) override;
  virtual void onKeyReleased(SDL_Scancode scanCode, SDL_Keycode keyCode,
      Uint16 mode) override;

private:
  Options& m_options;
  IMainLoop& m_mainLoop;
  IMainWindow& m_mainWindow;
  IRgRogue& m_rgRogue;
  bool m_isVisible;

  std::string getHeaderText();
};

}       // namespace
#endif  // _RG_ROGUE_MAIN_MENU_HPP_
