#pragma once
#include "figure.h"

template <typename T>
class Hexagon: public Figure<T> {
    friend std::ostream& operator << (std::ostream& os, const Hexagon<T> &fig) {
        os << "Hexagon\n" << fig._points;
        return os;
    }
    friend std::istream& operator >> (std::istream& is, const Hexagon<T> &fig) {
        Array<Point<T>> tmpV;
        Point<T> tmp;
        for (size_t i = 0; i < Figures::Hexagon; ++i) {
            is >> tmp;
            tmpV.push_back(tmp);
        }
        if (!valid(tmpV)) {
            throw std::range_error("Error! Square Constructor: invalid points");
        } else {
            Figure<T>::_points = tmpV;
        }   
        return is;
    }
    public:
        Hexagon();
        Hexagon(const std::initializer_list<Point<T>> &list);
        virtual ~Hexagon() noexcept = default;

        Point<T> getCenter() const;
        operator double() const;

        bool operator==(const Figure<T> &other) const;
        Hexagon<T> &operator = (Figure<T> &other);
    private:
        bool valid(const std::initializer_list<Point<T>> &list);
};

template <typename T>
Hexagon<T>::Hexagon(): Figure<T>() {}

template <typename T>
Hexagon<T>::Hexagon(const std::initializer_list<Point<T>> &list) {
    if (list.size() != 3) {
        throw std::range_error("invalid number of coordinates");
    } else if (!valid(list)){
        throw std::range_error("Error! Hexagon Constructor: invalid points");
    } else {
        Array<Point<T>> tmp(list);
        Figure<T>::_points = list;
    }
}

template <typename T>
bool Hexagon<T>::valid(const std::initializer_list<Point<T>> &list) {
    for (size_t i = 0; i < Figs::Hexagon - 2; ++i) {
        if (fabs(tmp[i].distance(tmp[i+1]) - tmp[i+1].distance(tmp[i+2])) > EPSILON) return false;
    }
    double l = tmp[0].distance(tmp[1]);
    for (size_t i = 0; i < Figures::Hexagon - Figures::Hexagon / 2; ++i) {
        if (fabs(tmp[i].distance(tmp[i + Figures::Hexagon]) - 2 * l ) > EPSILON) return false;
    }
    if (l < EPSILON) return false;
    return true;
}

template <typename T>
Point<T> Hexagon<T>::getCenter() const {
    if (Figure<T>::_points.size() == 0) {
        throw std::range_error("can't get center of empty");
    }
    Point<T> tmp = getAv(Figure<T>::_points);
    return tmp;
}

template <typename T>
Hexagon<T>::operator double() const {
    if (Figure<T>::_points.size() == 0) {
        throw std::range_error("can't get square of empty");
    }
    return std::pow((Figure<T>::_points[0]).distance((Figure<T>::_points[1])), 2) * 3 * std::pow(3,0.5) / 2;
}

template <typename T>
bool Hexagon<T>::operator ==(const Figure<T> &other) const{
    const Hexagon<T> *ptr = static_cast<const Hexagon<T>*>(&other);
    if (ptr) {
        return (Figure<T>::_points[0]).distance((Figure<T>::_points[1])) == (Figure<T>::other._points[0]).distance((Figure<T>::other._points[1]));
    } else {
        return false;
    }
}

template <typename T>
Hexagon<T> &Hexagon<T>::operator = (Figure<T> &other) {
    Hexagon<T> *ptr = static_cast<const Hexagon<T>*>(&other);
    if (ptr) {
        Figure<T>::_points = other._points;
        return *this;
    } else {
        throw std::logic_error("can't assign different types of figures");
    }
}