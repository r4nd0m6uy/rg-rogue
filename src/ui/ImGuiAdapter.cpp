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
#include "ImGuiAdapter.hpp"

#include <imgui.h>
#include <imgui_impl_sdl_gl2.h>


namespace rgrogue {

//------------------------------------------------------------------------------
ImGuiAdapter::ImGuiAdapter()
{
}

//------------------------------------------------------------------------------
ImGuiAdapter::~ImGuiAdapter()
{
}

//------------------------------------------------------------------------------
int ImGuiAdapter::init(SDL_Window *window)
{
  ImGui::CreateContext();
  ImGui_ImplSdlGL2_Init(window);
  ImGui::StyleColorsDark();

  return 0;
}

//------------------------------------------------------------------------------
void ImGuiAdapter::cleanup()
{
  ImGui_ImplSdlGL2_Shutdown();
  ImGui::DestroyContext();
}

//------------------------------------------------------------------------------
void ImGuiAdapter::newFrame(SDL_Window *window)
{
  ::ImGui_ImplSdlGL2_NewFrame(window);
}

//------------------------------------------------------------------------------
int ImGuiAdapter::draw()
{
  ImGui::Render();
  ImGui_ImplSdlGL2_RenderDrawData(ImGui::GetDrawData());

  return 0;
}

}       // namespace
