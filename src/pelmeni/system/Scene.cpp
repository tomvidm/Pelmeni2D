#include <cassert>
#include <iostream>

#include "json/Helpers.hpp"

#include "math/Transform.hpp"
#include "system/EntityFactory.hpp"
#include "system/Scene.hpp"

namespace p2d { namespace system {
        Scene::Scene(const Scene::file& sceneFile) 
        : sceneFilePath(sceneFile) {
            parseSceneFile();
            prefetchResources();
            prefetchSceneObjects();
        }

        void Scene::renderScene(sf::RenderWindow& window) const {
            auto& entities = getEntityList();
            for (auto& entity : entities) {
                window.draw(entity.getSprite());
            }
        }

        void Scene::updateEntities(const sf::Time dt) {
            auto& entities = getEntityList();
            for (auto& entity : entities) {
                entity.update(dt);
            }
        }

        void Scene::listResources() const {
            std::cout << "Listing resources...\n";
            spritePackManager.listResources();
        }

        void Scene::loadSceneFile(const Scene::file& sceneFile) {
            sceneFilePath = sceneFile;
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
                spritePackManager.loadSpritePacksFromList(spritepackList, &textureManager);
            }            
        }

        void Scene::prefetchSceneObjects() {
            printf("Prefetching scene objects\n");
            for (rapidjson::Value& entry : sceneFileDOM["scene_objects"].GetArray()) {
                Entity::alias alias = entry["alias"].GetString();
                Blueprint::id blueprintId = entry["blueprint"].GetString();
                
                // Load initial state
                float xPosition = entry["initial_state"]["transform"]["position"][0].GetFloat();
                float yPosition = entry["initial_state"]["transform"]["position"][1].GetFloat();
                float xScale = entry["initial_state"]["transform"]["scale"][0].GetFloat();
                float yScale = entry["initial_state"]["transform"]["scale"][1].GetFloat();
                float rotation = entry["initial_state"]["transform"]["rotation"].GetFloat();
                EntityState entityState{
                    math::Vector2f(xPosition, yPosition),
                    math::Vector2f(xScale, yScale),
                    math::fromAngle(rotation)
                };
                
                Entity entity = EntityFactory::createEntity(
                    blueprintId,
                    entityState,
                    &blueprintManager,
                    &entityManager,
                    &spritePackManager);
                
                /*
                    1. load the initial state of the entity
                    2. create the components and assign them to the entity
                    3. move the entity into the entity manager
                */
               entityManager.insertEntity(alias, entity);
            }
        }
} // namespace system
} // namespace p2d