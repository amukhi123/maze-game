#pragma once

#include <iostream>

#include "engine/types.h"

#define LOG_D(message) Logger::GetInstance()->Log(message, LogLevel::Debug);
#define LOG_E(message) Logger::GetInstance()->Log(message, LogLevel::Error);
#define LOG_W(message) Logger::GetInstance()->Log(message, LogLevel::Warning);

enum class LogLevel : uint8
{
    Info = 0,
    Debug,
    Warning,
    Error, 
};

class Logger
{
public:
    static UniquePtr<Logger>& GetInstance()
    {
        if (!m_Instance)
        {
            m_Instance.reset(new Logger);
        }

        return m_Instance;
    }

    void Log(const String& Message, const LogLevel LogLevel = LogLevel::Debug)
    {
        if (m_LogLevel >= LogLevel)
        {
            std::cout << "[Engine][" << LogLevelToStr(LogLevel) << "]: " << Message << std::endl;
        }
    }

    void SetLogLevel(const LogLevel LogLevelToSet)
    {
        m_LogLevel = LogLevelToSet;
    }
private:
    static UniquePtr<Logger> m_Instance;

    LogLevel m_LogLevel;

    Logger() : m_LogLevel {LogLevel::Info}
    {
    }

    Logger(const Logger& Logger) = delete;
    Logger& operator=(const Logger& Logger) = delete;
    Logger(const Logger&& Logger) = delete;
    Logger& operator=(const Logger&& Logger) = delete;

    String LogLevelToStr(const LogLevel LogLevel) const
    {
        switch (LogLevel)
        {
            case LogLevel::Error:
                return "ERROR";
            case LogLevel::Warning:
                return "WARNING";
            case LogLevel::Debug:
                return "DEBUG";
            case LogLevel::Info:
            default:
                return "INFO";
        }
    }
};
