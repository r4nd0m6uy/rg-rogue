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
#include <sstream>

#include <imgui.h>

#include "../logging/Loggers.hpp"
#include "../version.hpp"
#include "MainMenu.hpp"

namespace rgrogue {

static const std::string STR_GAME_NAME  = "Random Rogue";
static const float WINDOW_WIDTH         = 300;
static const float WINDOW_HEIGHT        = 150;

// FIXME: Translation
static const std::string STR_NEW_GAME   = "New game";
static const std::string STR_OPTIONS    = "Options";
static const std::string STR_VIDEO      = "Video";
static const std::string STR_CLOSE      = "Close";
static const std::string STR_FULLSCREEN = "Fullscreen";
static const std::string STR_APPLY      = "Apply";
static const std::string STR_EXIT       = "Exit";

//------------------------------------------------------------------------------
MainMenu::MainMenu(Options& options, IMainLoop& mainLoop,
    IMainWindow& mainWindow):
  m_options(options),
  m_mainLoop(mainLoop),
  m_mainWindow(mainWindow),
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
int MainMenu::init()
{
  m_mainLoop.registerKeyObserver(*this);

  return 0;
}

//------------------------------------------------------------------------------
int MainMenu::draw()
{
  if(!m_isVisible)
    return 0;

  if(ImGui::Begin(
      "Main menu", nullptr,
      ImGuiWindowFlags_NoMove |
      ImGuiWindowFlags_NoTitleBar |
      ImGuiWindowFlags_NoResize |
      ImGuiWindowFlags_NoSavedSettings))
  {
    ImGui::SetWindowPos(
        ImVec2(
            (m_options.getXResolution() / 2) - (WINDOW_WIDTH / 2),
            (m_options.getYResolution() / 2) - (WINDOW_HEIGHT / 2)),
        ImGuiCond_Once);
    ImGui::SetWindowSize(
        ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT), ImGuiCond_Once);

    // Header text
    std::string currentText = getHeaderText();
    ImVec2 textSize = ImGui::CalcTextSize(currentText.c_str());
    ImGui::SetCursorPos(
        ImVec2((WINDOW_WIDTH / 2) - (textSize.x / 2), ImGui::GetCursorPosY()));
    ImGui::Text("Random Rogue (%i.%i.%i - %s)",
        VERSION_MAJOR, VERSION_MINOR, VERSION_BUGFIX, VERSION_GIT.c_str());

    // New game
    currentText = STR_NEW_GAME;
    textSize = ImGui::CalcTextSize(currentText.c_str());
    ImGui::SetCursorPos(
        ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 20));
    if(ImGui::Button(
        currentText.c_str(), ImVec2(WINDOW_WIDTH, textSize.y + 10)))
      m_isVisible = false;

    // Options
    currentText = STR_OPTIONS;
    textSize = ImGui::CalcTextSize(currentText.c_str());
    if(ImGui::Button(
        currentText.c_str(), ImVec2(WINDOW_WIDTH, textSize.y + 10)))
      ImGui::OpenPopup(STR_OPTIONS.c_str());

    if(ImGui::BeginPopupModal(STR_OPTIONS.c_str()))
    {
      static bool isFullScreen = m_options.isFullScreen();

      ImGui::SetWindowSize(ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT), 0);

      // Video
      if (ImGui::CollapsingHeader(STR_VIDEO.c_str()))
      {
        ImGui::Checkbox(STR_FULLSCREEN.c_str(), &isFullScreen);
        ImGui::Text("TODO: Resolution");
      }

      if(ImGui::Button(STR_APPLY.c_str()))
      {
        Options newConfig = m_options;

        newConfig.setFullScreen(isFullScreen);

        if(!m_mainWindow.applyVideoConfig(newConfig))
        {
          m_options = newConfig;
          m_options.writeConfig();
          ImGui::CloseCurrentPopup();
        }
      }

      ImGui::SameLine();
      if(ImGui::Button(STR_CLOSE.c_str()))
      {
        isFullScreen = m_options.isFullScreen();
        ImGui::CloseCurrentPopup();
      }
      ImGui::EndPopup();
    }

    // Exit
    currentText = STR_EXIT;
    textSize = ImGui::CalcTextSize(currentText.c_str());
    if(ImGui::Button(
        currentText.c_str(), ImVec2(WINDOW_WIDTH, textSize.y + 10)))
      // TODO: Are you sure?
      m_mainLoop.breakLoop();
  }

  ImGui::End();

  return 0;
}

//------------------------------------------------------------------------------
void MainMenu::onKeyPressed(SDL_Scancode scanCode, SDL_Keycode keyCode,
    Uint16 mode)
{
  if(keyCode == SDLK_ESCAPE)
    m_isVisible = true;
}

//------------------------------------------------------------------------------
void MainMenu::onKeyReleased(SDL_Scancode scanCode, SDL_Keycode keyCode,
    Uint16 mode)
{
  // Nothing to do
}

//------------------------------------------------------------------------------
std::string MainMenu::getHeaderText()
{
  std::stringstream ss;

  ss << STR_GAME_NAME << " (" <<
      VERSION_MAJOR << "." <<
      VERSION_MINOR << "." <<
      VERSION_BUGFIX << " - " <<
      VERSION_GIT << ")";

  return ss.str();
}

}       // namespace
