#pragma once

#include <string>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "SFML/Graphics.hpp" 

#include "graphics/TextureManager.hpp"
#include "graphics/SpritePackManager.hpp"
#include "input/InputManager.hpp"
#include "system/BlueprintManager.hpp"
#include "system/EntityManager.hpp"
#include "system/EntityState.hpp"

namespace p2d { namespace system {
    class Scene {
    public:
        using file = std::string;

        Scene() {;}
        Scene(const Scene::file& sceneFile);

        void listResources() const;

        void loadSceneFile(const Scene::file& sceneFile);  
        void renderScene(sf::RenderWindow& winow) const;
        void updateEntities(const sf::Time dt);

        inline const std::vector<Entity>& getEntityList() const { return entityManager.getEntityContainer(); }
        inline std::vector<Entity>& getEntityList() { return entityManager.getEntityContainer(); }
    private:
        void parseSceneFile();
        void prefetchResources();
        void prefetchSceneObjects();

        graphics::TextureManager    textureManager;
        graphics::SpritePackManager spritePackManager;
        input::InputManager         inputManager;
        system::BlueprintManager    blueprintManager;
        system::EntityManager       entityManager;

        rapidjson::Document sceneFileDOM;

        Scene::file sceneFilePath;
    }; // class SceneManager
} // namespace system
} // namespace p2d