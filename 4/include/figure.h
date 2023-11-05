#pragma once
#include "point.h"
#include "array.h"

namespace Figures {
    const size_t Triangle = 3;
    const size_t Hexagon = 6;
    const size_t Octagon = 8;
}
template <typename T>
class Figure {  
    public:
        Figure();
        Figure(const Figure<Point<T>> &other);
        Figure(Figure<Point<T>> &&other) noexcept;
        Figure(const std::initializer_list<Point<T>> &list);
        ~Figure() = default;
        Array<Point<T>> getPoints() const;
    protected:
        Array<Point<T>> _points;
};

template <typename T>
Figure<T>::Figure() {
    Array<Point<T>> _points;
}

template <typename T>
Figure<T>::Figure(const Figure<Point<T>> &other) : _points(other._points) {}

template <typename T>
Figure<T>::Figure(Figure<Point<T>> &&other) noexcept {
    std::swap(this->_points, other._points);
}

template <typename T>
Array<Point<T>> Figure<T>::getPoints() const {
    return _points;
}

template <typename T>
Figure<T>::Figure(const std::initializer_list<Point<T>> &list) : _points(list) {}