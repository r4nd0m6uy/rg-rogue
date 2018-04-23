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
#include <imgui.h>

#include "../logging/Loggers.hpp"
#include "MainMenu.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
MainMenu::MainMenu():
  m_isVisible(true)
{
}

//------------------------------------------------------------------------------
MainMenu::~MainMenu()
{
}

//------------------------------------------------------------------------------
void MainMenu::setVisible(bool isVisible)
{
  m_isVisible = isVisible;
}

//------------------------------------------------------------------------------
int MainMenu::draw()
{
  ImGui::Begin("Hello Window", nullptr,
      ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);

  if(ImGui::BeginMenuBar())
  {
    if (ImGui::BeginMenu("File"))
    {
      if(ImGui::MenuItem("Open..", "Ctrl+O"))
        LOG_DB() << "Open do stuff";
      if(ImGui::MenuItem("Save", "Ctrl+S"))
        LOG_DB() << "Save do stuff";

      ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
  }

  ImGui::End();

  return 0;
}

}       // namespace
