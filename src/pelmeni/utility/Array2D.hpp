#pragma once

namespace p2d { namespace utility {
    template <typename T>
    class Array2D {
    public:
        Array2D();
        T& at(const size_t& row, const size_t& col);
    private:
        void resize(const size_t& rows, const size_t& cols);

        std::vector<std::vector<T>> data;
    }; // class Array2D

    template <typename T>
    Array2D<T>::Array2D() {
        ;
    } // constructor

    template <typename T>
    T& Array2D<T>::at(const size_t& row, const size_t& col) {
        return data[row][col];
    } // at

    template <typename T>
    void Array2D<T>::resize(const size_t& rows, const size_t& cols) {
        data.resize(rows);
        for (auto& row : data) {
            row.resize(cols);
        } // allocate columns
    } // allocate rows and columns
 
} // namespace utility
} // namespace p2d