#pragma once

namespace p2d { namespace utility {
    template <typename T>
    class Singleton {
    public:
        static T* getInstancePtr();
    protected:
        static T* instancePtr;
    private:
        Singleton();
    }; // class Singleton

    template <typename T>
    T* Singleton<T>::getInstancePtr() {
        if (instancePtr == nullptr) {
            instancePtr = new T;
        } // if an instance has not been made
        return instancePtr;
    } // getInstancePtr

    template <typename T>
    Singleton<T>::Singleton() {
        ;
    }

    template <typename T>
    T* Singleton<T>::instancePtr = nullptr;
} // namespace utility
} // namespace p2d