#pragma once

#include <string>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "system/Blueprint.hpp"
#include "utility/Map.hpp"

namespace p2d { namespace system {
    class BlueprintManager {
    public:
        using BlueprintMap = std::map<Blueprint::id, Blueprint>;
        using BlueprintLookupTable = utility::Map<Blueprint::id, std::string>;

        void loadBlueprintsFromList(const Blueprint::file blueprintsList);
        void loadBlueprintListing(rapidjson::Value& blueprintListing);
        Blueprint& get(const Blueprint::id& blueprintId);
    private:
        BlueprintMap blueprintMap; 
        BlueprintLookupTable blueprintLookupTable;
    }; // class BlueprintManager
} // namespace system
} // namespace p2d