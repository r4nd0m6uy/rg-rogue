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
#ifndef _RG_ROGUE_MAIN_LOOP_HPP_
#define _RG_ROGUE_MAIN_LOOP_HPP_

#include <list>
#include <functional>

#include "../options/Options.hpp"
#include "../ui/MainWindow.hpp"
#include "IMainLoop.hpp"

namespace rgrogue {

class MainLoop:
    public IMainLoop
{
public:
  MainLoop(Options& options, MainWindow& mainWindow, ImGuiAdapter& imgui);
  ~MainLoop();

  int run();

  // IMainLoop
  virtual int registerKeyObserver(IKeyObserver& observer) override;
  virtual void breakLoop() override;

private:
  Options& m_options;
  MainWindow& m_mainWindow;
  ImGuiAdapter& m_imgui;
  bool m_isRunning;
  std::list<std::reference_wrapper<IKeyObserver>> m_keyObservers;
};

}       // namespace
#endif  // _RG_ROGUE_MAIN_LOOP_HPP_
