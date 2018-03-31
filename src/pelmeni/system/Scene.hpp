#pragma once

#include <string>

#include "system/BlueprintManager.hpp"
#include "system/EntityManager.hpp"

namespace p2d { namespace system {
    class Scene {
    public:
        using file = std::string;

        Scene() = delete;
        Scene(const Scene::file& sceneFile);

        void createEntity();
    private:
        void prefetchResources();

        system::BlueprintManager blueprintManager;
        system::EntityManager entityManager;

        const Scene::file sceneFilePath;
    }; // class SceneManager
} // namespace system
} // namespace p2d