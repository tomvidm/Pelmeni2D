#include <cassert>

#include "json/Helpers.hpp"

#include "system/Scene.hpp"

namespace p2d { namespace system {
        Scene::Scene(const Scene::file& sceneFile) 
        : sceneFilePath(sceneFile) {
            prefetchResources();
        }

        void Scene::prefetchResources() {
            sceneFileDOM = json::parseJsonFile("../resources/" + sceneFilePath);
            
            for (rapidjson::Value& entry : sceneFileDOM["resource_lists"]["blueprint_lists"].GetArray()) {
                Blueprint::file blueprintFile = entry.GetString();
                blueprintManager.loadBlueprintsFromList(blueprintFile);
            }

            for (rapidjson::Value& entry : sceneFileDOM["resource_lists"]["texture_lists"].GetArray()) {
                std::string textureList = entry.GetString();
                textureManager.loadTexturesFromList(textureList);
            }

            for (rapidjson::Value& entry : sceneFileDOM["scene_objects"].GetArray()) {
                Entity::alias alias = entry["alias"].GetString();
                Blueprint::id blueprintId = entry["blueprint"].GetString();
                Entity::id entityId = entityManager.createEntity(blueprintManager.get(blueprintId));
                printf("Creating entity from blueprint %s.\n         Id: %u\n      Alias: %s\n", blueprintId.c_str(), entityId, alias.c_str());
            }
        }
} // namespace system
} // namespace p2d