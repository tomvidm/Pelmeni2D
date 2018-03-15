#include "LogContainer.hpp"

namespace p2d { namespace debugging {
    void LogContainer::addMessage(const LogMessage& logMessage) {
        logMessages.push_back(logMessage);

        if (logMessages.size() > maxMessages) {
            logMessages.pop_front();
        } // ensure number of stored message == maxMessages 
    } // addMessage

    std::string LogContainer::buildStringFromLastNLogmessages(const unsigned& n) const {
        std::string result = "";
        for (auto m = logMessages.cend() - n; m != logMessages.cend(); m++) {
            result = result + (*m).text;
        } // for
        return result;
    }
} // namespace debugging
} // namespace p2d