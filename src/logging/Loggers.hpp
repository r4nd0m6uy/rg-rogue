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
#ifndef _RG_ROGUE_LOGGERS_HPP_
#define _RG_ROGUE_LOGGERS_HPP_

#include <unordered_map>
#include <memory>

#include "ILogger.hpp"

namespace rgrogue {

class Loggers
{
public:
  Loggers(Loggers const&) = delete;
  Loggers(Loggers&&) = delete;
  Loggers& operator=(Loggers const&) = delete;
  Loggers& operator=(Loggers &&) = delete;

  static Loggers& getInstance();
  ILogger& getLogger(const std::string& which);
  void setMaxLogLevel(LogLevel level);

private:
  typedef std::unordered_map<std::string, std::unique_ptr<ILogger> > LoggersMap;
  LoggersMap m_loggers;
  std::unique_ptr<ILogger> m_default;

  Loggers();
  ~Loggers();
};

}       // namespace

#define _LOG(cat, loglevel)      rgrogue::Loggers::getInstance().getLogger(cat).getFormater(loglevel).get()

#define LOG_CAT(cat)            _LOG(cat, rgrogue::LogLevel::INFO)
#define LOG_CAT_ER(cat)         _LOG(cat, rgrogue::LogLevel::ERROR)
#define LOG_CAT_WA(cat)         _LOG(cat, rgrogue::LogLevel::WARNING)
#define LOG_CAT_IN(cat)         _LOG(cat, rgrogue::LogLevel::INFO)
#define LOG_CAT_DB(cat)         _LOG(cat, rgrogue::LogLevel::DEBUG)

#define LOG()                   LOG_CAT("")
#define LOG_ER()                LOG_CAT_ER("")
#define LOG_WA()                LOG_CAT_WA("")
#define LOG_IN()                LOG_CAT_IN("")
#define LOG_DB()                LOG_CAT_DB("")

#endif  // _COMET_LIB_LOGGERS_HPP_
