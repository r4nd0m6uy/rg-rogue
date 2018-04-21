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
#ifndef _RG_ROGUE_OPTIONS_HPP_
#define _RG_ROGUE_OPTIONS_HPP_

namespace rgrogue {

class Options
{
public:
  Options();
  ~Options();

  int init();
  bool isFullScreen();
  void setFullScreen(bool isFullScreen);
  int getXResolution();
  void setXResolution(int xResolution);
  int getYResolution();
  void setYResolution(int yResolution);
  unsigned int getFps();
  void setFps(unsigned int fps);

private:
  bool m_isFullScreen;
  int m_xResolution;
  int m_yResolution;
  unsigned int m_fps;

  int readConfig();
  int writeConfig();
};

}       // namespace
#endif  // _RG_ROGUE_OPTIONS_HPP_
