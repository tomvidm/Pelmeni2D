#include "ObjectManager.hpp"

namespace p2d { namespace system {
    ObjectPtr ObjectManager::getObject(const ObjectId& id) {
         
        if (!objectPtrMap.contains(id)) {
            return std::make_shared<Object>(Object());
        } else {
            return objectPtrMap.get(id);
        } // if else
    } // getObject

    void ObjectManager::loadObject(const ObjectId& id, const PresetId& presetId) {
         
        if (!objectPtrMap.contains(id)) {
            std::pair<ObjectId, ObjectPtr> keyValuePair = objectLoader.load(id, presetId);
             
            objectPtrMap.insert(keyValuePair);
        } // if
    } // loadObject
} // namespace system
} // namespace p2d