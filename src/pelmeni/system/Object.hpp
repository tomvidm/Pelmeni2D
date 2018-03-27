#pragma once

#include <memory>
#include <string>

namespace p2d { namespace system {
    class Object {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<Object>;

        inline Object::id getId() const { return objectId; }
    private:
        Object::id objectId;
    }; // class Object
} // namespace system
} // namespace p2d