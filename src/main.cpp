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
#include <getopt.h>

#include <iostream>

#include "logging/Loggers.hpp"
#include "RgRogue.hpp"
#include "version.hpp"

//------------------------------------------------------------------------------
void printHelp(const char* appName)
{
  std::cout << appName << ":" << std::endl;
  std::cout << "-h|--help     Show this help" << std::endl;
  std::cout << "-v|--version  Display version" << std::endl;
}

//------------------------------------------------------------------------------
void printVersion()
{
  std::cout << "rg-rogue 2018 by R4nd0m6uy" << std::endl << std::endl;
  std::cout << "Built on " << rgrogue::VERSION_BUILD_TIME << std::endl;
  std::cout << "Version: " << rgrogue::VERSION_MAJOR << "." <<
      rgrogue::VERSION_MINOR << "." <<
      rgrogue::VERSION_BUGFIX <<
      " (" <<rgrogue::VERSION_GIT << ")" << std::endl;
}

//------------------------------------------------------------------------------
int parseArgse(int argc, char* argv[], int& retCode)
{
  int opt;
  static struct option long_options[] = {
      {"help",      no_argument,        0, 'h'},
      {"version",   required_argument,  0, 'v'},
      {0,           0,                  0, 0}
  };

  while ((opt = getopt_long(argc, argv, "hv", long_options, 0)) != -1) {
    switch (opt)
    {
    case 'h':
      printHelp(argv[0]);
      retCode = 0;
      return -1;
    case 'v':
      printVersion();
      retCode = 0;
      return -1;
    default:
      printHelp(argv[0]);
      retCode = -1;
      return -1;
    }
  }

  return 0;
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  rgrogue::RgRogue rgRogue;
  int rc;

  if(parseArgse(argc, argv, rc))
    return rc;

  if(rgRogue.init())
    return -1;

  rc = rgRogue.runGame();

  LOG_IN() << "Exiting with code " << rc;

  return rc;
}
