#pragma once

#include <deque>
#include <string>

namespace p2d { namespace debugging {
    struct LogMessage {
        unsigned timestamp;
        std::string text;
    }; // struct LogMessage

    class LogContainer {
    public:
        void addMessage(const LogMessage& logMessage);
        std::string buildStringFromLastNLogmessages(const unsigned& n) const;
    private:
        unsigned maxMessages;
        std::deque<LogMessage> logMessages;
    }; // class LogContainer
} // namespace debugging
} // namespace p2d