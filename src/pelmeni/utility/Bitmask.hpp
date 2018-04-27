#pragma once

namespace p2d { namespace utility {
    using uint = unsigned int;

    template <typename E> 
    class Bitmask {
    public:
        Bitmask();
        Bitmask(const uint& initialValue);
        const bool operator [] (const E& bits) const;
        const bool operator [] (const uint integer) const;
        void set(const uint integer);
        uint get() const;
    private:
        uint bitmask;
    }; // class Bitmask

    template <typename E>
    Bitmask<E>::Bitmask()
    : bitmask(0) {
        ;
    }

    template <typename E>
    Bitmask<E>::Bitmask(const uint& initialValue) 
    : bitmask(initialValue) {
        ;
    }

    template <typename E>
    bool Bitmask<E>::operator [] (const E& bits) const {
        const uint integer = static_cast<uint>(bits);
        return integer & bitmask > 0;
    }
    template <typename E>
    bool Bitmask<E>::operator [] (const uint integer) const {
        return ineger & bitmask > 0;
    }

    template <typename E>
    void Bitmask<E>::set(const uint integer) {
        bitmask = integer;
    }

    template <typename E>
    uint Bitmask<E>::get() {
        return bitmask;
    } 
}
}