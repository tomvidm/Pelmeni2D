#pragma once

#include <string>
#include <memory>

#include "Package.hpp"
#include "PackageLoader.hpp"
#include "../utility/Map.hpp"

namespace p2d { namespace graphics {
    class PackageManager {
        using PackageId = std::string;
        using PackagePtrMap = utility::Map<ResourceId, PackagePtr>;
    
    public:
        PackagePtr getPackage(const PackageId& id);
        PackagePtr loadPackage(const PackageId& id);
    private:
        PackagePtrMap packagePtrMap;
        PackageLoader packageLoader;
    }; // class PackageManager
} // namespace graphics
} // namespace p2d