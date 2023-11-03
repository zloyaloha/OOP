#pragma once
#include "figure.h"

namespace {
    const double OCTAGON_CONST = 1 + pow(2, 0.5);
}

template <typename T>
class Octagon: public Figure<T> {
    public:
        Octagon();
        Octagon(const std::initializer_list<Point<T>> &list);
        virtual ~Octagon() noexcept = default;

        Point<T> getCenter() const;
        double 
    private:
        bool valid(const std::initializer_list<Point<T>> &list);
};

template <typename T>
Octagon<T>::Octagon(): Figure<T>() {}

template <typename T>
Octagon<T>::Octagon(const std::initializer_list<Point<T>> &list) {
    if (list.size() != 8) {
        throw std::range_error("invalid number of coordinates");
    } else if (!valid(list)){
        throw std::range_error("Error! Octagon Constructor: invalid points");
    } else {
        Array<Point<T>> tmp(list);
        Figure<T>::_points = list;
    }
}

template <typename T>
bool Octagon<T>::valid(const std::initializer_list<Point<T>> &list) {
    Array<Point<T>> tmp;
    for (Point<T> t: list) {
        tmp.push_back(t);
    }
    for (size_t i = 0; i < 8 - 2; ++i) {
        if (fabs(tmp[i].distance(tmp[i+1]) - tmp[i+1].distance(tmp[i+2])) > EPSILON) return false;
    }
    double l = tmp[0].distance(tmp[1]);
    for (size_t i = 0; i < 8 - 4; ++i) {
        if (fabs(tmp[i].distance(tmp[i+4]) - 2 * l * sqrt(OCTAGON_CONST / (OCTAGON_CONST - 1))) > EPSILON) return false;
    }
    if (l < EPSILON) return false;
    return true;
}

template <typename T>
Point<T> Octagon<T>::getCenter() const{
    if (Figure<T>::_points.size() == 0) {
        throw std::range_error("can't get center of empty");
    }
    Point<T> tmp = getAv(Figure<T>::_points);
    return tmp;
}