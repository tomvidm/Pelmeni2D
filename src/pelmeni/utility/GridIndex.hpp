#pragma once

#include <vector>

#include "math/math.hpp"
#include "utility/Rect.hpp"

namespace p2d { namespace utility {

    template <typename T>
    class Sector {
    public:
        void setBoundingRect(const utility::Rect<float>& brect);
        const utility::Rect<float>& getBoundingRect() const;
    private:
        utility::Rect<float> boundingRect;
        std::vector<T> container;
    }; // class Sector

    template <typename T>
    void Sector<T>::setBoundingRect(const utility::Rect<float>& brect) {
        boundingRect = brect;
    }

    template <typename T>
    const utility::Rect<float>& Sector<T>::getBoundingRect() const {
        return boundingRect;
    }

    template <typename T>
    class GridIndex {
    public:
        void setSectorSize(const math::Vector2f& size);
        void setResolution(const size_t& nrows, const size_t& ncols);
        void rebuildGrid();
        void rebuildBoundingRect();

        const utility::Rect<float>& getBoundingRect() const;
        
        Sector<T>& getSectorByPoint(const math::Vector2f& vec);
        Sector<T>& getSector(const size_t& row, const size_t& col);
        Sector<T>& getSectorByIndex(const size_t& sec);
    private:
        size_t rows;
        size_t cols;
        utility::Rect<float> boundingRect;
        math::Vector2f sectorSize;
        std::vector<Sector<T>>  sectors;
    }; // GridIndex

    template <typename T>
    void GridIndex<T>::setSectorSize(const math::Vector2f& size) {
        sectorSize = size;
    }

    template <typename T>
    void GridIndex<T>::setResolution(const size_t& nrows, const size_t& ncols) {
        rows = nrows;
        cols = ncols;
    }

    template <typename T>
    void GridIndex<T>::rebuildBoundingRect() {
        const utility::Rect<float> rect(
            math::Vector2f(0.f, 0.f),
            math::Vector2f(cols * sectorSize.x, rows * sectorSize.y)
        );
        boundingRect = rect;
    }

    template <typename T>
    void GridIndex<T>::rebuildGrid() {
        sectors.resize(rows * cols);
        const float rowHeight = boundingRect.getSize().y;
        const float colWidth = boundingRect.getSize().x;
        const math::Vector2f sectorSize(colWidth, rowHeight);
        for (size_t r = 0; r < rows; r++) {
            for (size_t c = 0; c < cols; c++) {
                const math::Vector2f sectorTopLeft(c * colWidth, r * rowHeight);
                const utility::Rect<float> sectorBoundingRect(sectorTopLeft, sectorSize);
                sectors[r * cols + c].setBoundingRect(sectorBoundingRect);
            }
        }
    }

    template <typename T>
    const utility::Rect<float>& GridIndex<T>::getBoundingRect() const {
        return boundingRect;
    }

    template <typename T>
    Sector<T>& GridIndex<T>::getSectorByPoint(const math::Vector2f& vec) {
        const size_t x = static_cast<size_t>(floor(vec.x / sectorSize.x));
        const size_t y = static_cast<size_t>(floor(vec.y / sectorSize.y));
        return getSector(y, x);
    }

    template <typename T>
    Sector<T>& GridIndex<T>::getSector(const size_t& row, const size_t& col) {
        return getSectorByIndex(row * cols + col);
    }

    template <typename T>
    Sector<T>& GridIndex<T>::getSectorByIndex(const size_t& sec) {
        return sectors[sec];
    }

} // namespace utility
} // namespace p2d