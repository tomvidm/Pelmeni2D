#include <cstdio>
#include <cassert>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "BlueprintManager.hpp"

namespace p2d { namespace system {
    void BlueprintManager::loadBlueprint(const Blueprint::id& blueprintId) {
        printf("Loading blueprint '%s'\n", blueprintId.c_str());

        if (blueprintMap.contains(blueprintId) > 0) {
            return;
        }

        Blueprint blueprint = createBlueprint(blueprintId, blueprintLookupTable.get(blueprintId));
        assert(blueprint.getId() == blueprintId);

        blueprintMap.insert(std::make_pair(blueprintId, std::make_shared<Blueprint>(blueprint)));
    }
    
    Blueprint::ptr BlueprintManager::get(const Blueprint::id& blueprintId) {
        if (!blueprintMap.contains(blueprintId)) {
            loadBlueprint(blueprintId);
        }
        return blueprintMap.get(blueprintId);
    }

    void BlueprintManager::initializeBlueprintLookupTable() {
        printf("Initializing blueprint lookup table... ");
        rapidjson::Document doc = json::parseJsonFile("../resources/blueprints/blueprint_lookup.json");

        for (auto& entry : doc.GetArray()) {
            const Blueprint::id blueprintId = entry[0].GetString();
            const std::string blueprintPath = entry[1].GetString();
            blueprintLookupTable.insert(std::make_pair(blueprintId, blueprintPath));
        }

        printf("Finished\n");
    }

    Blueprint BlueprintManager::createBlueprint(const Blueprint::id blueprintId, 
                                                   const std::string& blueprintPath) {
            rapidjson::Document doc = json::parseJsonFile("../resources/" + blueprintPath);

            assert(blueprintId == doc["blueprint_id"].GetString());

            const std::string spritePackageId = doc["packages"]["sprite_package_id"].GetString();
            
            Blueprint blueprint(blueprintId, spritePackageId);

            return blueprint;
    }
} // namespace system
} // namespace p2d