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
#ifndef _RG_ROGUE_IM_GUI_HPP_
#define _RG_ROGUE_IM_GUI_HPP_

#include <SDL.h>
#include <SDL_opengl.h>

#include <imgui.h>

namespace rgrogue {

class ImGuiAdapter
{
public:
  ImGuiAdapter();
  ~ImGuiAdapter();

  int init(SDL_Window *window);
  void cleanup();
  void newFrame(SDL_Window *window);
  int draw();
  void processEvent(SDL_Event* event);
  bool isHandledByImgui(SDL_Event* event);

private:
  SDL_Cursor* m_mouseCursors[ImGuiMouseCursor_COUNT];
  GLuint m_fontTexture;
  Uint64 m_time;
  bool m_mousePressed[3];

  static void setClipboardText(void* ctx, const char* text);
  static const char* getClipboardText(void* ctx);
  void createDeviceObjects();
  void invalidateDeviceObjects();
};

}       // namespace
#endif  // _RG_ROGUE_IM_GUI_HPP_
