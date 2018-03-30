#pragma once

#include <string>

#include "system/BlueprintManager.hpp"

namespace p2d { namespace system {
    class Scene {
    public:
        using file = std::string;

        Scene() = delete;
        Scene(const Scene::file& sceneFile);
    private:
        void prefetchResources();

        system::BlueprintManager blueprintManager;

        const Scene::file sceneFilePath;
    }; // class SceneManager
} // namespace system
} // namespace p2d