#pragma once

#include <string>

#include "system/Blueprint.hpp"
#include "utility/Map.hpp"

namespace p2d { namespace system {
    class BlueprintManager {
    public:
        using BlueprintMap = utility::Map<Blueprint::id, Blueprint::ptr>;
        using BlueprintLookupTable = utility::Map<Blueprint::id, std::string>;
        
        BlueprintManager() {
            initializeBlueprintLookupTable();
        }

        void loadBlueprint(const Blueprint::id& blueprintId);
        Blueprint::ptr get(const Blueprint::id& blueprintId);
    private:
        void initializeBlueprintLookupTable();
        Blueprint createBlueprint(const Blueprint::id blueprintId, 
                                  const std::string& blueprintPath);

        BlueprintMap blueprintMap; 
        BlueprintLookupTable blueprintLookupTable;
    }; // class BlueprintManager
} // namespace system
} // namespace p2d