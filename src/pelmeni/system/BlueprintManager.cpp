#include <cstdio>
#include <cassert>

#include "json/Helpers.hpp"

#include "system/BlueprintManager.hpp"

namespace p2d { namespace system {
    Blueprint& BlueprintManager::get(const Blueprint::id& blueprintId) {
        return blueprintMap.at(blueprintId);
    }

    void BlueprintManager::loadBlueprintsFromList(const Blueprint::file blueprintsList)
    {
        printf("Fetching blueprints from %s...\n", blueprintsList.c_str());
        rapidjson::Document doc = json::parseJsonFile("../resources/" + blueprintsList);

        for (auto& entry : doc.GetArray()) {
            loadBlueprintListing(entry);
        }
    }

    void BlueprintManager::loadBlueprintListing(rapidjson::Value& blueprintListing) {
        system::Blueprint::id blueprintId = blueprintListing["blueprint_id"].GetString();
        printf("  Processing blueprint %s\n", blueprintId.c_str());
        
        system::Blueprint blueprint;
        blueprintMap.insert(std::make_pair(blueprintId, std::move(blueprint)));

    }
} // namespace system
} // namespace p2d