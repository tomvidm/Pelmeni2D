#pragma once

#include <string>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "system/BlueprintManager.hpp"
#include "system/EntityManager.hpp"
#include "graphics/TextureManager.hpp"
#include "graphics/SpritePackManager.hpp"

namespace p2d { namespace system {
    class Scene {
    public:
        using file = std::string;

        Scene() {;}
        Scene(const Scene::file& sceneFile);

        void loadSceneFile(const Scene::file& sceneFile);  
        inline std::vector<Entity>& getEntityList() { return entityManager.getEntityContainer(); }
    private:
        void parseSceneFile();
        void prefetchResources();
        void prefetchSceneObjects();

        system::BlueprintManager blueprintManager;
        system::EntityManager entityManager;
        graphics::TextureManager textureManager;
        graphics::SpritePackManager spritePackManager;

        rapidjson::Document sceneFileDOM;

        Scene::file sceneFilePath;
    }; // class SceneManager
} // namespace system
} // namespace p2d