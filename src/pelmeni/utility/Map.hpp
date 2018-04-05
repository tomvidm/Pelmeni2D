    #pragma once

 
#include <stdexcept> 
#include <string>
#include <map>

namespace p2d { namespace utility {
    using Id = std::string;
    
    template <typename K, typename V>
    class Map {
    public:
        Map();
        Map(const Map& rhs);
        void insert(const K& key, const V& value);
        void insert(const std::pair<K, V>& keyValuePair);
        
        bool contains(const K& key) const;
        unsigned size() const;

        V& get(const K& key);
        V get(const K& key) const;
    protected:
        std::map<K, V> stlMap;
    }; // class Map

    template <typename K, typename V>
    Map<K, V>::Map() {
        ;
    }

    template <typename K, typename V>
    Map<K, V>::Map(const Map& rhs)
    : stlMap(rhs.stlMap) {
        ;
    }

    template <typename K, typename V>
    void Map<K, V>::insert(const K& key, const V& value) {
        stlMap.insert(std::make_pair(key, value));
    } // insert

    template <typename K, typename V>
    void Map<K, V>::insert(const std::pair<K, V>& keyValuePair) {
        stlMap.insert(keyValuePair);
    } // insert

    template <typename K, typename V>
    bool Map<K, V>::contains(const K& key) const {
        if (stlMap.count(key)) {
            return true;
        } else {
            return false;
        }
    }

    template <typename K, typename V>
    unsigned Map<K, V>::size() const {
        return stlMap.size();
    }

    template <typename K, typename V>
    V& Map<K, V>::get(const K& key) {
        return stlMap.at(key);
    }

    template <typename K, typename V>
    V Map<K, V>::get(const K& key) const {
        return stlMap.at(key);
    }
    
} // namespace utility
} // namespace p2d