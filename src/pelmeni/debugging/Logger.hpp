#pragma once

#include <string>
#include <fstream>

namespace p2d { namespace debugging {
    enum LogLevel {
        Verbose,
        Debug,
        Warning,
        Error,
        Fatal
    };

    class Logger {
    public:
        static Logger* getInstancePtr();
        void logMessage(const std::string& logString, const LogLevel& logL);
    private:
        void openLogFile();
        void closeLogFile();

        std::string logFileName;
        std::ofstream logFile;

        static Logger* instancePtr;

        Logger();
        ~Logger();
    }; // class Logger
} // namespace debugging
} // namespace p2d