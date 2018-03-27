#include "../system/Blueprint.hpp"
#include "../utility/Map.hpp"

#include <string>

namespace p2d { namespace system {
    class BlueprintManager {
        using BlueprintMap = utility::Map<Blueprint::id, Blueprint>;
        using BlueprintLookupTable = utility::Map<Blueprint::id, std::string>;
        
        Blueprint& get(const Blueprint::id& blueprintId);

    private:
        void initializeBlueprintLookupTable();

        BlueprintLoader blueprintLoader;
        BlueprintMap blueprintMap; 
        BlueprintLookupTable blueprintLookupTable;
    }; // class BlueprintManager
} // namespace system
} // namespace p2d