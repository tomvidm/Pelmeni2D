#include "PackageManager.hpp"

namespace p2d { namespace graphics {
    PackagePtr PackageManager::getPackage(const PackageId& id) {
         
        if (!packagePtrMap.contains(id)) {
            return loadPackage(id);
        } else {
            return packagePtrMap.get(id);
        } // if else
    } // loadPackage

    PackagePtr PackageManager::loadPackage(const PackageId& id) {
         
        std::pair<PackageId, PackagePtr> keyValuePair = packageLoader.load(id);
        packagePtrMap.insert(keyValuePair);
        return packagePtrMap.get(id);
    }
} // namespace graphics
} // namespace p2d