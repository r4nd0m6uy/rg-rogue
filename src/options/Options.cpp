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
#include "../logging/Loggers.hpp"
#include "Options.hpp"

namespace rgrogue {

static const bool DEFAULT_IS_FULLSCREEN = false;
static const int DEFAULT_X_RESOLUTION   = 1024;
static const int DEFAULT_Y_RESOLUTION   = 768;
static const unsigned int DEFAULT_FPS   = 60;

//------------------------------------------------------------------------------
Options::Options():
  m_isFullScreen(DEFAULT_IS_FULLSCREEN),
  m_xResolution(DEFAULT_X_RESOLUTION),
  m_yResolution(DEFAULT_Y_RESOLUTION),
  m_fps(DEFAULT_FPS)
{
}

//------------------------------------------------------------------------------
Options::~Options()
{
}

//------------------------------------------------------------------------------
int Options::init()
{
  return readConfig();
}

//------------------------------------------------------------------------------
bool Options::isFullScreen()
{
  return m_isFullScreen;
}

//------------------------------------------------------------------------------
void Options::setFullScreen(bool isFullScreen)
{
  m_isFullScreen = isFullScreen;
}

//------------------------------------------------------------------------------
int Options::getXResolution()
{
  return m_xResolution;
}

//------------------------------------------------------------------------------
void Options::setXResolution(int xResolution)
{
  m_xResolution = xResolution;
}

//------------------------------------------------------------------------------
int Options::getYResolution()
{
  return m_yResolution;
}

//------------------------------------------------------------------------------
void Options::setYResolution(int yResolution)
{
  m_yResolution = yResolution;
}

//------------------------------------------------------------------------------
unsigned int Options::getFps()
{
  return m_fps;
}

//------------------------------------------------------------------------------
void Options::setFps(unsigned int fps)
{
  m_fps = fps;
}

//------------------------------------------------------------------------------
int Options::writeConfig()
{
  // TODO
  LOG_WA() << "Writing configuration not implemented yet";

  return 0;
}

//------------------------------------------------------------------------------
int Options::readConfig()
{
  // TODO
  LOG_WA() << "Reading configuration not implemented yet";

  return 0;
}

}       // namespace
