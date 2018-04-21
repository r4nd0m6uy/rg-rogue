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
#ifndef _RG_ROGUE_LOG_FORMATTER_HPP_
#define _RG_ROGUE_LOG_FORMATTER_HPP_

#include <sstream>

#include "ILogSink.hpp"

namespace rgrogue {

class LogFormatter:
    public std::ostream
{
public:
  LogFormatter(LogLevel logLevel, ILogSink& logSink);
  LogFormatter(ILogSink& logSink);
  LogFormatter(const LogFormatter& rhs);
  ~LogFormatter();

  std::ostream& get();

private:
  LogLevel m_logLevel;
  ILogSink& m_logSink;
  bool m_isEnabled;
  std::stringstream m_ss;
};

}       // namespace
#endif  //_RG_ROGUE_LOG_FORMATTER_HPP_
