#include "ObjectManager.hpp"

namespace p2d { namespace system {
    ObjectPtr ObjectManager::getObject(const ObjectId& id) {
        std::cout << "ObjectManager::getObject(" << id << ")\n";
        if (!objectPtrMap.contains(id)) {
            return std::make_shared<Object>(Object());
        } else {
            return objectPtrMap.get(id);
        } // if else
    } // getObject

    void ObjectManager::loadObject(const ObjectId& id, const PresetId& presetId) {
        std::cout << "ObjectManager::loadObject(" << id << ", " << presetId << ")\n";
        if (!objectPtrMap.contains(id)) {
            std::pair<ObjectId, ObjectPtr> keyValuePair = objectLoader.load(id, presetId);
            std::cout << "ObjectManager: retrieved Object with address " << keyValuePair.second.get() << "\n";
            objectPtrMap.insert(keyValuePair);
        } // if
    } // loadObject
} // namespace system
} // namespace p2d