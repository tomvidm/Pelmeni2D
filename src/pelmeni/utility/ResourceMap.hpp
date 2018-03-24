    #pragma once

 
#include <stdexcept> 
#include <string>
#include <map>

namespace p2d { namespace utility {
    using ResourceId = std::string;
    
    template <typename T, typename TLoader, typename TLoaderArg>
    class ResourceMap {
    public:
        ResourceMap();

        T& get (const ResourceId& id);

        void load(const TLoaderArg& arg);
        void release(const ResourceId& id);
    private:
        std::map<TLoaderArg, T> resourceMap;
        TLoader resourceLoader;
    }; // class ResourceMap

    template <typename T, typename TLoader, typename TLoaderArg>
    T& ResourceMap<T, TLoader, TLoaderArg>::get (const ResourceId& id) {
        if (!resourceMap.count(id)) {
            load(id);
        } // load if not already loaded
        return resourceMap.at(id);
    } // operator []

    template <typename T, typename TLoader, typename TLoaderArg>
    void ResourceMap<T, TLoader, TLoaderArg>::load(const TLoaderArg& arg) {
        resourceMap.insert(std::pair<ResourceId, T>(resourceLoader.loadResource(arg)));
    }

    template <typename T, typename TLoader, typename TLoaderArg>
    void ResourceMap<T, TLoader, TLoaderArg>::release(const ResourceId& id) {
        resourceMap.erase(id);
    }

    template <typename T, typename TLoader, typename TLoaderArg>
    ResourceMap<T, TLoader, TLoaderArg>::ResourceMap() {
        ;
    }
    
} // namespace utility
} // namespace p2d