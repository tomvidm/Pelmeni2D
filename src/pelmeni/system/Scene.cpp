#include <cassert>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "system/Scene.hpp"

namespace p2d { namespace system {
        Scene::Scene(const Scene::file& sceneFile) 
        : sceneFilePath(sceneFile) {
            prefetchResources();
        }

        void Scene::prefetchResources() {
            rapidjson::Document doc = json::parseJsonFile("../resources/" + sceneFilePath);
            
            for (rapidjson::Value& entry : doc["prefetched_blueprints"]["blueprint_lists"].GetArray()) {
                Blueprint::file blueprintFile = entry.GetString();
                blueprintManager.loadBlueprintsFromList(blueprintFile);
            }

            for (rapidjson::Value& entry : doc["scene_objects"].GetArray()) {
                Entity::alias alias = entry["alias"].GetString();
                Blueprint::id blueprintId = entry["blueprint"].GetString();
                Entity::id entityId = entityManager.createEntity(blueprintId);
                printf("Creating entity from blueprint %s.\n     Id: %u\n  Alias: %s\n", blueprintId.c_str(), entityId, alias.c_str());
            }
        }
} // namespace system
} // namespace p2d