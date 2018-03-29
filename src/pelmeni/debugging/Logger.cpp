#include <chrono>
#include <iostream>

#include "Logger.hpp"

namespace p2d { namespace debugging {
    Logger* Logger::getInstancePtr() {
        if (instancePtr == nullptr) {
            instancePtr = new Logger;
        }   return instancePtr;
    }

    void Logger::logMessage(const std::string& logString, const LogLevel& logL) {
        logFile << logString.c_str();
        std::cout << logString << std::endl;
    }

    void Logger::openLogFile() {
        if (!logFile.is_open()) {
            logFile.open(logFileName);
        }
    }

    void Logger::closeLogFile() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    Logger::Logger() {
        using namespace std::chrono;
        unsigned long ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        logFileName = "log" + std::to_string(ms);
        openLogFile();
    }

    Logger::~Logger() {
        closeLogFile();
    }

    Logger* Logger::instancePtr = nullptr;
} // namespace debugging
} // namespace p2d