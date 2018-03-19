    #pragma once

#include <iostream>
#include <stdexcept> 
#include <string>
#include <map>

namespace p2d { namespace utility {
    using ResourceId = std::string;

    template <typename ResourceType, typename ResourceLoader>
    class ResourceManager {
    public:
        ResourceManager();

        T& get (const ResourceId& id);

        void load(const ResourceId& id);
        void release(const ResourceId& id);
    private:
        std::map<ResourceId, T> resourceMap;
        ResourceLoader resourceLoader;
    }; // class ResourceManager

    template <typename ResourceType, typename ResourceLoader>
    T& ResourceManager<T>::get (const ResourceId& id) {
        return resourceMap.at(id);
    } // operator []

    template <typename ResourceType, typename ResourceLoader>
    void ResourceManager<T>::load(const ResourceId& id) {
        resourceMap.insert(std::pair<ResourceId, T>(id, resourceLoader.loadResource(id)));
    }

    template <typename ResourceType, typename ResourceLoader>
    void ResourceManager<T>::release(const ResourceId& id) {
        resourceMap.erase(id);
    }

    template <typename ResourceType, typename ResourceLoader>
    ResourceManager<T>::ResourceManager() {
        ;
    }
    
} // namespace utility
} // namespace p2d