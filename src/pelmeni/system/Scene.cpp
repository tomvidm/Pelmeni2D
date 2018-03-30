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
        }
} // namespace system
} // namespace p2d