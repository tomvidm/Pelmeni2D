#include <cstdio>
#include <cassert>
#include <string>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.cpp"

#include "system/BlueprintLoader.hpp"

namespace p2d { namespace system {
        Blueprint BlueprintLoader::createBlueprint(const Blueprint::id blueprintId, 
                                                   const std::string& blueprintPath) {
            rapidjson::Document doc = json::parseJsonFile("../resources/" + blueprintPath);

            assert(blueprintId == doc["blueprint_id"].GetString());

            const std::string spritePackageId = doc["packages"]["sprite_package_id"].GetString();
            
            Blueprint blueprint(blueprintId, spritePackageId);

            return blueprint;
        }
} // namespace system
} // namespace p2d