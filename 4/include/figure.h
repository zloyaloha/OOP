#pragma once
#include "point.h"
#include "array.h"

template <typename T>
class Figure {
    public:
        Figure();
        Figure(const Figure &other);
        Figure(const std::initializer_list<Point<T>> &list);
        ~Figure() = default;
        Array<Point<T>> getPoints();
    protected:
        Array<Point<T>> _points;
};

template <typename T>
Figure<T>::Figure() {
    Array<Point<T>> _points;
}

template <typename T>
Figure<T>::Figure(const Figure &other) : _points(other._points) {}

template <typename T>
Array<Point<T>> Figure<T>::getPoints() {
    return _points;
}

template <typename T>
Figure<T>::Figure(const std::initializer_list<Point<T>> &list) : _points(list) {}
