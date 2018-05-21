#pragma once

#include <vector>
#include <memory>
#include "math/Vector.hpp"
#include "utility/Rect.hpp"

namespace p2d { namespace utility {
    // Requirements for T:
    // method getPosition() returning a vector2<float>  
    template <typename T>
    class Subquad {
    public:
        using unique = std::unique_ptr<Subquad>;
    public:
        Subquad(const size_t cap, const utility::Rect<float> boundingRect);
        void push(const T& obj);

        size_t getSubquadIdByVector(const math::Vector2f vec);
        size_t count() const;
        size_t countTotal() const;

        const Subquad<T>& getSubquadById(const size_t id) const;
        const Subquad<T>& getSubquadByVector(const math::Vector2f vec) const;
        bool contains(const math::Vector2f vec) const;
    private:
        bool isSubdivided;
        size_t capacity;
        std::vector<T> content;
        std::array<std::unique_ptr<Subquad<T>>, 4> subquads;
        utility::Rect<float> bounds;
    private:
        void subdivide();
        void distribute();
    };  

    template <typename T>
    Subquad<T>::Subquad(const size_t cap, const utility::Rect<float> boundingRect) 
    : isSubdivided(false),
      capacity(cap),
      bounds(boundingRect) {
        ;
    }

    template <typename T>
    void Subquad<T>::push(const T& obj) {
        content.push_back(obj);
        if (content.size() > capacity) {
            subdivide();
        }
    }

    template <typename T>
    size_t Subquad<T>::getSubquadIdByVector(const math::Vector2f vec) {
        if (bounds.contains(vec)) {
            if (subquads[0]->contains(vec)) {
                return 0;
            } else if (subquads[1]->contains(vec)) {
                return 1;
            } else if (subquads[2]->contains(vec)) {
                return 2;
            } else if (subquads[3]->contains(vec)) {
                return 3;
            }
        }

        return 5;
    }

    template <typename T>
    const Subquad<T>& Subquad<T>::getSubquadById(const size_t id) const {
        return *subquads[id];
    }

    template <typename T>
    const Subquad<T>& Subquad<T>::getSubquadByVector(const math::Vector2f vec) const {
        const size_t id = getSubquadIdByVector(vec);
        return *subquads[id];
    }

    template <typename T>
    bool Subquad<T>::contains(const math::Vector2f vec) const {
        return bounds.contains(vec);
    }

    template <typename T>
    void Subquad<T>::distribute() {
        for (auto& obj : content) {
            const size_t subquadId = getSubquadIdByVector(obj.getPosition());
            subquads[subquadId]->push(obj);
        }
        content.clear();
    }

    template <typename T>
    size_t Subquad<T>::count() const {
        return content.size();
    }

    template <typename T>
    size_t Subquad<T>::countTotal() const {
        if (!isSubdivided) {
            return content.size();
        } else {
            return subquads[0]->count() +
                   subquads[1]->count() +
                   subquads[2]->count() +
                   subquads[3]->count();
        }
    }

    template <typename T>
    void Subquad<T>::subdivide() {
        const utility::Rect<float> subquadBounds = bounds * 0.5f;
        subquads[0] = Subquad<T>::unique(new Subquad<T>(capacity, subquadBounds));
        subquads[1] = Subquad<T>::unique(new Subquad<T>(capacity, subquadBounds + math::projectToX(subquadBounds.size)));
        subquads[2] = Subquad<T>::unique(new Subquad<T>(capacity, subquadBounds + subquadBounds.size));
        subquads[3] = Subquad<T>::unique(new Subquad<T>(capacity, subquadBounds + math::projectToY(subquadBounds.size)));
        isSubdivided = true;
        distribute();
    }
}
}