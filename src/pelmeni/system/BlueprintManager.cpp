#include <cstdio>
#include <cassert>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "BlueprintManager.hpp"

namespace p2d { namespace system {
    void BlueprintManager::loadBlueprint(const Blueprint::id& blueprintId) {
        printf("BlueprintManager: Loading blueprint %s\n", blueprintId.c_str());

        if (blueprintMap.contains(blueprintId) > 0) {
            printf("BlueprintManager: Blueprint %s already loaded\n", blueprintId.c_str());
            return;
        }

        Blueprint blueprint = blueprintLoader.createBlueprint(blueprintId, blueprintLookupTable.get(blueprintId)); // = blueprintLoader.load(args)
        assert(blueprint.getId() == blueprintId);

        blueprintMap.insert(std::make_pair(blueprintId, blueprint));
    }

    void BlueprintManager::initializeBlueprintLookupTable() {
        printf("BlueprintManager: Loading and parsing blueprint lookup table\n");
        rapidjson::Document doc = json::parseJsonFile("../resources/blueprints/blueprint_lookup_table.json");

        for (auto& entry : doc.GetArray()) {
            const Blueprint::id blueprintId = entry[0].GetString();
            const std::string blueprintPath = entry[1].GetString();
            blueprintLookupTable.insert(std::make_pair(blueprintId, blueprintPath));
            printf("-- %s: %s\n", blueprintId.c_str(), blueprintPath.c_str());
        }

        printf("BlueprintManager: Finished loading lookup table\n");
        
    }
} // namespace system
} // namespace p2d