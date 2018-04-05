#include <cassert>

#include "json/Helpers.hpp"

#include "system/Scene.hpp"

namespace p2d { namespace system {
        Scene::Scene(const Scene::file& sceneFile) 
        : sceneFilePath(sceneFile) {
            parseSceneFile();
            prefetchResources();
            prefetchSceneObjects();
        }

        void Scene::parseSceneFile() {
            printf("Parsing scene file %s\n", sceneFilePath.c_str());
            sceneFileDOM = json::parseJsonFile("../resources/" + sceneFilePath);
        }

        void Scene::prefetchResources() {
            // prefetch blueprints
            for (rapidjson::Value& entry : sceneFileDOM["resource_lists"]["blueprint_lists"].GetArray()) {
                Blueprint::file blueprintFile = entry.GetString();
                blueprintManager.loadBlueprintsFromList(blueprintFile);
            }

            // prefetch textures
            for (rapidjson::Value& entry : sceneFileDOM["resource_lists"]["texture_lists"].GetArray()) {
                std::string textureList = entry.GetString();
                textureManager.loadTexturesFromList(textureList);
            }

            // prefetch sprite packs
            for (rapidjson::Value& entry : sceneFileDOM["resource_lists"]["spritepack_lists"].GetArray()) {
                std::string spritepackList = entry.GetString();
                spritePackManager.loadSpritePacksFromList(spritepackList);
            }

            
        }

        void Scene::prefetchSceneObjects() {
            printf("Prefetching scene objects\n");
            for (rapidjson::Value& entry : sceneFileDOM["scene_objects"].GetArray()) {
                Entity::alias alias = entry["alias"].GetString();
                Blueprint::id blueprintId = entry["blueprint"].GetString();
                Entity::id entityId = entityManager.createEntity(blueprintManager.get(blueprintId));
                printf("Creating entity from blueprint %s.\n         Id: %u\n      Alias: %s\n", blueprintId.c_str(), entityId, alias.c_str());
            }
        }
} // namespace system
} // namespace p2d