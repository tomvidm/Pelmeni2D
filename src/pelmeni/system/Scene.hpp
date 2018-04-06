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
        using DisplayList = std::vector<graphics::Sprite::shared>;
        using file = std::string;

        Scene() {;}
        Scene(const Scene::file& sceneFile);

        void loadSceneFile(const Scene::file& sceneFile);  
        inline DisplayList& getDisplayList() { return displayList; }
    private:
        void parseSceneFile();
        void prefetchResources();
        void prefetchSceneObjects();

        system::BlueprintManager blueprintManager;
        system::EntityManager entityManager;
        graphics::TextureManager textureManager;
        graphics::SpritePackManager spritePackManager;

        DisplayList displayList;

        rapidjson::Document sceneFileDOM;

        Scene::file sceneFilePath;
    }; // class SceneManager
} // namespace system
} // namespace p2d