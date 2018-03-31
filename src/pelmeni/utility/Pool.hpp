#pragma once

#include <cstdio>
#include <memory>
#include <deque>
#include <array>

namespace p2d { namespace utility {
    enum TState {
        UNUSED,
        FREE,
        ACTIVE
    };

    template <typename T, unsigned N>
    class Pool {
    public:
        Pool();

        typename T::id newObject(T&& obj);

        inline bool empty() const { return activeObjects_ == 0; }
        inline size_t capacity() const { return capacity_; }
        inline size_t size() const { return activeObjects_; }
        inline size_t numFreeIndexes() const { return freeIndexes.size(); }
    private:
        size_t fetchFreeIndex();
        
        void activate(size_t index);
        void deactivate(size_t index);  

        size_t activeObjects_;
        size_t firstUnusedIndex_;
        const size_t capacity_;
        

        std::array<TState, N> stateArray;
        std::array<T, N> objectArray;
        std::deque<size_t> freeIndexes;
    }; // class Pool

    template <typename T, unsigned N>
    Pool<T, N>::Pool() 
    : activeObjects_(0), firstUnusedIndex_(0), capacity_(N) {
        size_t memuse = static_cast<size_t>(N) * (sizeof(T) + sizeof(TState));
        printf("Pool created. Estimated memory usage: %zu bytes\n", memuse);
    }

    template <typename T, unsigned N>
    size_t Pool<T, N>::fetchFreeIndex() {
        if (freeIndexes.empty()) {
            size_t index = firstUnusedIndex_++;
            return index;
        } else {
            size_t index = freeIndexes.front();
            freeIndexes.pop_front();
            return index;
        } // if else
    } // find free index

    template <typename T, unsigned N>
    typename T::id Pool<T, N>::newObject(T&& obj) {
        size_t index = fetchFreeIndex();
        activate(index);
        return static_cast<typename T::id>(index);
    } // activate

    template <typename T, unsigned N>
    void Pool<T, N>::activate(size_t index) {
        stateArray[index] = TState::ACTIVE;
        ++activeObjects_;
    } // activate

    template <typename T, unsigned N>
    void Pool<T, N>::deactivate(size_t index) {
        stateArray[index] = TState::FREE;
        freeIndexes.push_back(index);
        --activeObjects_;
    } // activate
} // namespace utility
} // namespace p2d