#pragma once

#include <memory>
#include <string>

namespace p2d { namespace system {
    class Blueprint {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<Blueprint>;
        using file = std::string;

        inline Blueprint::id getId() const { return blueprintId; }
    private:
        Blueprint::id blueprintId;
    }; // class Blueprint
} // namespace system
} // namespace p2d