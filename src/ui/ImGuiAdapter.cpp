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
 *
 * A copy of the imgui SDL2 example
 */
#include <imgui.h>

#include "ImGuiAdapter.hpp"

namespace rgrogue {

//------------------------------------------------------------------------------
ImGuiAdapter::ImGuiAdapter():
      m_fontTexture(0)
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

  ImGuiIO& io = ImGui::GetIO();
  io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;

  io.KeyMap[ImGuiKey_Tab] = SDL_SCANCODE_TAB;
  io.KeyMap[ImGuiKey_LeftArrow] = SDL_SCANCODE_LEFT;
  io.KeyMap[ImGuiKey_RightArrow] = SDL_SCANCODE_RIGHT;
  io.KeyMap[ImGuiKey_UpArrow] = SDL_SCANCODE_UP;
  io.KeyMap[ImGuiKey_DownArrow] = SDL_SCANCODE_DOWN;
  io.KeyMap[ImGuiKey_PageUp] = SDL_SCANCODE_PAGEUP;
  io.KeyMap[ImGuiKey_PageDown] = SDL_SCANCODE_PAGEDOWN;
  io.KeyMap[ImGuiKey_Home] = SDL_SCANCODE_HOME;
  io.KeyMap[ImGuiKey_End] = SDL_SCANCODE_END;
  io.KeyMap[ImGuiKey_Insert] = SDL_SCANCODE_INSERT;
  io.KeyMap[ImGuiKey_Delete] = SDL_SCANCODE_DELETE;
  io.KeyMap[ImGuiKey_Backspace] = SDL_SCANCODE_BACKSPACE;
  io.KeyMap[ImGuiKey_Space] = SDL_SCANCODE_SPACE;
  io.KeyMap[ImGuiKey_Enter] = SDL_SCANCODE_RETURN;
  io.KeyMap[ImGuiKey_Escape] = SDL_SCANCODE_ESCAPE;
  io.KeyMap[ImGuiKey_A] = SDL_SCANCODE_A;
  io.KeyMap[ImGuiKey_C] = SDL_SCANCODE_C;
  io.KeyMap[ImGuiKey_V] = SDL_SCANCODE_V;
  io.KeyMap[ImGuiKey_X] = SDL_SCANCODE_X;
  io.KeyMap[ImGuiKey_Y] = SDL_SCANCODE_Y;
  io.KeyMap[ImGuiKey_Z] = SDL_SCANCODE_Z;

  io.SetClipboardTextFn = setClipboardText;
  io.GetClipboardTextFn = getClipboardText;
  io.ClipboardUserData = NULL;

  m_mouseCursors[ImGuiMouseCursor_Arrow] =
      SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
  m_mouseCursors[ImGuiMouseCursor_TextInput] =
      SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
  m_mouseCursors[ImGuiMouseCursor_ResizeAll] =
      SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEALL);
  m_mouseCursors[ImGuiMouseCursor_ResizeNS] =
      SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENS);
  m_mouseCursors[ImGuiMouseCursor_ResizeEW] =
      SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEWE);
  m_mouseCursors[ImGuiMouseCursor_ResizeNESW] =
      SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENESW);
  m_mouseCursors[ImGuiMouseCursor_ResizeNWSE] =
      SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE);

#ifdef _WIN32
  SDL_SysWMinfo wmInfo;
  SDL_VERSION(&wmInfo.version);
  SDL_GetWindowWMInfo(window, &wmInfo);
  io.ImeWindowHandle = wmInfo.info.win.window;
#else
  (void)window;
#endif

  ImGui::StyleColorsDark();

  return 0;
}

//------------------------------------------------------------------------------
void ImGuiAdapter::cleanup()
{
  for (ImGuiMouseCursor cursor_n = 0;
      cursor_n < ImGuiMouseCursor_COUNT;
      ++cursor_n)
    SDL_FreeCursor(m_mouseCursors[cursor_n]);

  invalidateDeviceObjects();

  ImGui::DestroyContext();
}

//------------------------------------------------------------------------------
void ImGuiAdapter::newFrame(SDL_Window *window)
{
  int w;
  int h;
  int display_w;
  int display_h;

  if (!m_fontTexture)
    createDeviceObjects();

  ImGuiIO& io = ImGui::GetIO();

  SDL_GetWindowSize(window, &w, &h);
  SDL_GL_GetDrawableSize(window, &display_w, &display_h);
  io.DisplaySize = ImVec2((float)w, (float)h);
  io.DisplayFramebufferScale = ImVec2(
      w > 0 ? ((float)display_w / w) : 0, h > 0 ? ((float)display_h / h) : 0);

  static Uint64 frequency = SDL_GetPerformanceFrequency();
  Uint64 current_time = SDL_GetPerformanceCounter();
  io.DeltaTime = m_time > 0 ? (float)((double)(current_time - m_time) / frequency) : (float)(1.0f / 60.0f);
  m_time = current_time;

  int mx, my;
  Uint32 mouse_buttons = SDL_GetMouseState(&mx, &my);
  io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
  io.MouseDown[0] =
      m_mousePressed[0] || (mouse_buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
  io.MouseDown[1] =
      m_mousePressed[1] || (mouse_buttons & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0;
  io.MouseDown[2] =
      m_mousePressed[2] || (mouse_buttons & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0;
  m_mousePressed[0] =
      m_mousePressed[1] = m_mousePressed[2] = false;

#if (SDL_MAJOR_VERSION >= 2) && (SDL_MINOR_VERSION >= 0) && (SDL_PATCHLEVEL >= 4)
  if((SDL_GetWindowFlags(window) &
      (SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_MOUSE_CAPTURE)) != 0)
    io.MousePos = ImVec2((float)mx, (float)my);
  bool any_mouse_button_down = false;
  for(int n = 0; n < IM_ARRAYSIZE(io.MouseDown); n++)
    any_mouse_button_down |= io.MouseDown[n];
  if(any_mouse_button_down &&
      (SDL_GetWindowFlags(window) & SDL_WINDOW_MOUSE_CAPTURE) == 0)
    SDL_CaptureMouse(SDL_TRUE);
  if(!any_mouse_button_down &&
      (SDL_GetWindowFlags(window) & SDL_WINDOW_MOUSE_CAPTURE) != 0)
    SDL_CaptureMouse(SDL_FALSE);
#else
  if((SDL_GetWindowFlags(window) & SDL_WINDOW_INPUT_FOCUS) != 0)
    io.MousePos = ImVec2((float)mx, (float)my);
#endif

  if((io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange) == 0)
  {
    ImGuiMouseCursor cursor = ImGui::GetMouseCursor();
    if(io.MouseDrawCursor || cursor == ImGuiMouseCursor_None)
      SDL_ShowCursor(0);
    else
    {
      SDL_SetCursor(
          m_mouseCursors[cursor] ?
              m_mouseCursors[cursor] : m_mouseCursors[ImGuiMouseCursor_Arrow]);
      SDL_ShowCursor(1);
    }
  }

  ImGui::NewFrame();
}

//------------------------------------------------------------------------------
int ImGuiAdapter::draw()
{
  ImDrawData* draw_data;
  int fb_width;
  int fb_height;

  ImGui::Render();

  ImGuiIO& io = ImGui::GetIO();
  fb_width = (int)(io.DisplaySize.x * io.DisplayFramebufferScale.x);
  fb_height = (int)(io.DisplaySize.y * io.DisplayFramebufferScale.y);
  if (fb_width == 0 || fb_height == 0)
    return 0;

  draw_data = ImGui::GetDrawData();
  draw_data->ScaleClipRects(io.DisplayFramebufferScale);

  GLint last_texture; glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
  GLint last_polygon_mode[2]; glGetIntegerv(GL_POLYGON_MODE, last_polygon_mode);
  GLint last_viewport[4]; glGetIntegerv(GL_VIEWPORT, last_viewport);
  GLint last_scissor_box[4]; glGetIntegerv(GL_SCISSOR_BOX, last_scissor_box);
  glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_TRANSFORM_BIT);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDisable(GL_CULL_FACE);
  glDisable(GL_DEPTH_TEST);
  glEnable(GL_SCISSOR_TEST);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnable(GL_TEXTURE_2D);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glViewport(0, 0, (GLsizei)fb_width, (GLsizei)fb_height);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0.0f, io.DisplaySize.x, io.DisplaySize.y, 0.0f, -1.0f, +1.0f);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  for(int n = 0; n < draw_data->CmdListsCount; n++)
  {
    const ImDrawList* cmd_list = draw_data->CmdLists[n];
    const ImDrawVert* vtx_buffer = cmd_list->VtxBuffer.Data;
    const ImDrawIdx* idx_buffer = cmd_list->IdxBuffer.Data;
    glVertexPointer(2, GL_FLOAT, sizeof(ImDrawVert),
        (const GLvoid*)(
            (const char*)vtx_buffer + IM_OFFSETOF(ImDrawVert, pos)));
    glTexCoordPointer(2, GL_FLOAT, sizeof(ImDrawVert), (
        const GLvoid*)(
            (const char*)vtx_buffer + IM_OFFSETOF(ImDrawVert, uv)));
    glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(ImDrawVert),
        (const GLvoid*)(
            (const char*)vtx_buffer + IM_OFFSETOF(ImDrawVert, col)));

    for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
    {
      const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
      if (pcmd->UserCallback)
      {
        pcmd->UserCallback(cmd_list, pcmd);
      }
      else
      {
        glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
        glScissor((int)pcmd->ClipRect.x, (int)(fb_height - pcmd->ClipRect.w),
            (int)(pcmd->ClipRect.z - pcmd->ClipRect.x),
            (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));
        glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount,
            sizeof(ImDrawIdx) == 2 ?
                GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, idx_buffer);
      }

      idx_buffer += pcmd->ElemCount;
    }
  }

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  glBindTexture(GL_TEXTURE_2D, (GLuint)last_texture);
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glPopAttrib();
  glPolygonMode(GL_FRONT, (GLenum)last_polygon_mode[0]);
  glPolygonMode(GL_BACK, (GLenum)last_polygon_mode[1]);
  glViewport(last_viewport[0], last_viewport[1], (GLsizei)last_viewport[2],
      (GLsizei)last_viewport[3]);
  glScissor(last_scissor_box[0], last_scissor_box[1],
      (GLsizei)last_scissor_box[2], (GLsizei)last_scissor_box[3]);

  return 0;
}

//------------------------------------------------------------------------------
void ImGuiAdapter::processEvent(SDL_Event* event)
{
  ImGuiIO& io = ImGui::GetIO();

  switch (event->type)
  {
  case SDL_MOUSEWHEEL:
    if(event->wheel.x > 0)
      io.MouseWheelH += 1;
    if(event->wheel.x < 0)
      io.MouseWheelH -= 1;
    if(event->wheel.y > 0)
      io.MouseWheel += 1;
    if(event->wheel.y < 0)
      io.MouseWheel -= 1;

    break;
  case SDL_MOUSEBUTTONDOWN:
    if(event->button.button == SDL_BUTTON_LEFT)
      m_mousePressed[0] = true;
    if(event->button.button == SDL_BUTTON_RIGHT)
      m_mousePressed[1] = true;
    if(event->button.button == SDL_BUTTON_MIDDLE)
      m_mousePressed[2] = true;
    break;
  case SDL_TEXTINPUT:
    io.AddInputCharactersUTF8(event->text.text);
    break;
  case SDL_KEYDOWN:
  case SDL_KEYUP:
    int key = event->key.keysym.scancode;
    IM_ASSERT(key >= 0 && key < IM_ARRAYSIZE(io.KeysDown));
    io.KeysDown[key] = (event->type == SDL_KEYDOWN);
    io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
    io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
    io.KeyAlt = ((SDL_GetModState() & KMOD_ALT) != 0);
    io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
    break;
  }
}

//------------------------------------------------------------------------------
void ImGuiAdapter::setClipboardText(void* ctx, const char* text)
{
  SDL_SetClipboardText(text);
}

//------------------------------------------------------------------------------
const char* ImGuiAdapter::getClipboardText(void* ctx)
{
  return SDL_GetClipboardText();
}

//------------------------------------------------------------------------------
void ImGuiAdapter::createDeviceObjects()
{
  ImGuiIO& io = ImGui::GetIO();
  unsigned char* pixels;
  int width, height;
  io.Fonts->GetTexDataAsAlpha8(&pixels, &width, &height);

  GLint last_texture;
  glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
  glGenTextures(1, &m_fontTexture);
  glBindTexture(GL_TEXTURE_2D, m_fontTexture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height, 0, GL_ALPHA,
      GL_UNSIGNED_BYTE, pixels);

  io.Fonts->TexID = (void *)(intptr_t)m_fontTexture;

  glBindTexture(GL_TEXTURE_2D, last_texture);
}

//------------------------------------------------------------------------------
void ImGuiAdapter::invalidateDeviceObjects()
{
  if(m_fontTexture)
  {
    glDeleteTextures(1, &m_fontTexture);
    ImGui::GetIO().Fonts->TexID = 0;
    m_fontTexture = 0;
  }
}

}       // namespace
