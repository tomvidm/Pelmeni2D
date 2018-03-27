#include <string>

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

#include "../system/Blueprint.hpp"

namespace p2d { namespace system {
    class BlueprintLoader {
    public:
        Blueprint createBlueprint(const std::string& blueprintPath);
    }; // class BlueprintLoader
} // namespace system
} // namespace p2d