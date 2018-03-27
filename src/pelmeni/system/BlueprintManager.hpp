#pragma once

#include <string>

#include "system/Blueprint.hpp"
#include "system/BlueprintLoader.hpp"
#include "utility/Map.hpp"

namespace p2d { namespace system {
    class BlueprintManager {
    public:
        using BlueprintMap = utility::Map<Blueprint::id, Blueprint>;
        using BlueprintLookupTable = utility::Map<Blueprint::id, std::string>;
        
        BlueprintManager() {
            initializeBlueprintLookupTable();
        }

        void loadBlueprint(const Blueprint::id& blueprintId);

    private:
        void initializeBlueprintLookupTable();

        BlueprintLoader blueprintLoader;
        BlueprintMap blueprintMap; 
        BlueprintLookupTable blueprintLookupTable;
    }; // class BlueprintManager
} // namespace system
} // namespace p2d