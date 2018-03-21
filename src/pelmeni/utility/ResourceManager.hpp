    #pragma once

#include <iostream>
#include <stdexcept> 
#include <string>
#include <map>

namespace p2d { namespace utility {
    using ResourceId = std::string;

    template <typename T>
    using ResourceMap = typename std::map<ResourceId, T>;

    template <typename T>
    using ResourceMapIter = typename std::map<ResourceId, T>::iterator;
    
    template <typename T>
    using ResourceMapConstIter = typename std::map<ResourceId, T>::const_iterator;

    template <typename T, typename TLoader>
    class ResourceManager {
    public:
        ResourceManager();

        T& get (const ResourceId& id);

        void load(const ResourceId& id);
        void release(const ResourceId& id);
    private:
        std::map<ResourceId, T> resourceMap;
        TLoader resourceLoader;
    }; // class ResourceManager

    template <typename T, typename TLoader>
    T& ResourceManager<T, TLoader>::get (const ResourceId& id) {
        return resourceMap.at(id);
    } // operator []

    template <typename T, typename TLoader>
    void ResourceManager<T, TLoader>::load(const ResourceId& id) {
        resourceMap.insert(std::pair<ResourceId, T>(id, resourceLoader.loadResource(id)));
    }

    template <typename T, typename TLoader>
    void ResourceManager<T, TLoader>::release(const ResourceId& id) {
        resourceMap.erase(id);
    }

    template <typename T, typename TLoader>
    ResourceManager<T, TLoader>::ResourceManager() {
        ;
    }
    
} // namespace utility
} // namespace p2d