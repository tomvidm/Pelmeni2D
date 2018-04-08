#pragma once

#include <array>
#include <list>

/*
    This class stack allocated N objects of type T. When full, it starts to allocate on the heap.
*/

namespace p2d { namespace utility {
    template <typename T, size_t N>
    class ContinuousPool {
        ContinuousPool() : softCapacity(N), last(0) {;}

        size_t push(const T& obj);
        void remove(const size_t& id);

        inline size_t size() const { return last; }
        inline size_t capacity() const { return softCapacity; }
    private:
        size_t softCapacity;
        size_t last;
        std::array<T, N> objectArray;
        //std::vector<T> extensionIndexVector;
        //std::vector<T> extensionVector;
    }; // class ContinuousPool

    template <typename T, size_t N>
    size_t ContinuousPool<T, N>::push(const T& obj) {
        objectArray[last++] = obj;
    }

    template <typename T, size_t N>
    void ContinuousPool<T, N>::remove(const size_t& id) {
        if (id >= last) { return; }
        else {
            if (id == last - 1) {
            --last;
            } else {
                objectArray[id] = std::move(objectArray[--last]);
            }
        }
    }
} // namespace utility
} // namespace p2d