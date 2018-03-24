#include "PackageManager.hpp"

namespace p2d { namespace graphics {
    PackagePtr PackageManager::getPackage(const PackageId& id) {
        std::cout << "PackageManager::getPackage(" << id << ")\n";
        if (!packagePtrMap.contains(id)) {
            return loadPackage(id);
        } else {
            return packagePtrMap.get(id);
        } // if else
    } // loadPackage

    PackagePtr PackageManager::loadPackage(const PackageId& id) {
        std::cout << "PackageManager::loadPackage(" << id << ")\n";
        packagePtrMap.insert(packageLoader.load(id));
        return packagePtrMap.get(id);
    }
} // namespace graphics
} // namespace p2d