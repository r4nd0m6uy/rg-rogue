/*
 * (c) 2017 Comet AG
 */
#include <iostream>

#include "LoggerConsole.hpp"
#include "Loggers.hpp"

namespace rgrogue {

//--------------------------------------------------------------------------------------------
Loggers::Loggers():
    m_default(new LoggerConsole())
{
}

//--------------------------------------------------------------------------------------------
Loggers::~Loggers()
{
}

//--------------------------------------------------------------------------------------------
Loggers& Loggers::getInstance()
{
  static Loggers loggers;
  return loggers;
}

//--------------------------------------------------------------------------------------------
ILogger& Loggers::getLogger(const std::string& which)
{
  LoggersMap::iterator it;

  it = m_loggers.find(which);

  if(it == m_loggers.end())
  {
    m_loggers[which] = std::unique_ptr<ILogger>(m_default->clone(which));
    return *m_loggers[which];
  }
  else
    return *it->second;
}

//--------------------------------------------------------------------------------------------
void Loggers::setMaxLogLevel(LogLevel level)
{
  for(auto& logger : m_loggers)
    logger.second->setMaxLogLevel(level);

  m_default->setMaxLogLevel(level);
}

}       // namespace
