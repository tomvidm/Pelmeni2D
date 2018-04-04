#pragma once

#include <string>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "system/BlueprintManager.hpp"
#include "system/EntityManager.hpp"
#include "graphics/TextureManager.hpp"

namespace p2d { namespace system {
    class Scene {
    public:
        using file = std::string;

        Scene() = delete;
        Scene(const Scene::file& sceneFile);

    private:
        void prefetchResources();

        system::BlueprintManager blueprintManager;
        system::EntityManager entityManager;
        graphics::TextureManager textureManager;

        rapidjson::Document sceneFileDOM;

        const Scene::file sceneFilePath;
    }; // class SceneManager
} // namespace system
} // namespace p2d