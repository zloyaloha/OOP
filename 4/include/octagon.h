#pragma once
#include "figure.h"

namespace {
    const double OCTAGON_CONST = 1 + pow(2, 0.5);
}

template <typename T>
class Octagon: public Figure<T> {
    friend std::ostream& operator << (std::ostream& os, const Octagon<T> &fig) {
        os << "Octagon\n" << fig._points;
        return os;
    }
    friend std::istream& operator >> (std::istream& is, const Octagon<T> &fig) {
        Array<Point<T>> tmpV;
        Point<T> tmp;
        for (size_t i = 0; i < Figures::Octagon; ++i) {
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
        Octagon();
        Octagon(const std::initializer_list<Point<T>> &list);
        Octagon(const Octagon<Point<T>> &other);
        Octagon(Octagon<Point<T>> &&other) noexcept;
        virtual ~Octagon() noexcept = default;

        Point<T> getCenter() const;
        operator double() const;

        bool operator==(const Figure<T> &other) const;
        Octagon<T> &operator = (Figure<T> &other);
        Octagon<T> &operator = (Figure<T> &&other);

    private:
        bool valid(const Array<Point<T>> &list);
};

template <typename T>
Octagon<T>::Octagon(): Figure<T>() {}

template <typename T>
Octagon<T>::Octagon(const Octagon<Point<T>> &other): Figure<T>(other) {}

template <typename T>
Octagon<T>::Octagon(Octagon<Point<T>> &&other) noexcept: Figure<T>(other) {}

template <typename T>
Octagon<T>::Octagon(const std::initializer_list<Point<T>> &list) {
    const Array<Point<T>> tmp(list);
    if (list.size() != 8) {
        throw std::range_error("invalid number of coordinates");
    } else if (!valid(tmp)){
        throw std::range_error("Error! Octagon Constructor: invalid points");
    } else {
        Array<Point<T>> tmp(list);
        Figure<T>::_points = list;
    }
}

template <typename T>
bool Octagon<T>::valid(const Array<Point<T>> &tmp) {
    for (size_t i = 0; i < Figures::Octagon - 2; ++i) {
        if (fabs(tmp[i].distance(tmp[i+1]) - tmp[i+1].distance(tmp[i+2])) > EPSILON) return false;
    }
    double l = tmp[0].distance(tmp[1]);
    for (size_t i = 0; i < Figures::Octagon - Figures::Octagon / 2; ++i) {
        if (fabs(tmp[i].distance(tmp[i + Figures::Octagon / 2]) - 2 * l * sqrt(OCTAGON_CONST / (OCTAGON_CONST - 1))) > EPSILON) return false;
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

template <typename T>
Octagon<T>::operator double() const{
    if (Figure<T>::_points.size() == 0) {
        throw std::range_error("can't get square of empty");
    }
    return std::pow((Figure<T>::_points[0]).distance((Figure<T>::_points[1])), 2) * 2 * OCTAGON_CONST;
}

template <typename T>
bool Octagon<T>::operator ==(const Figure<T> &other) const{
    const Octagon<T> *ptr = static_cast<const Octagon<T>*>(&other);
    if (ptr) {
        return (Figure<T>::_points[0]).distance((Figure<T>::_points[1])) == (other.getPoints()[0]).distance((other.getPoints()[1]));
    } else {
        return false;
    }
}

template <typename T>
Octagon<T> &Octagon<T>::operator = (Figure<T> &other) {
    Octagon<T> *ptr = static_cast<Octagon<T>*>(&other);
    if (ptr) {
        Figure<T>::_points = other._points;
        return *this;
    } else {
        throw std::logic_error("can't assign different types of figures");
    }
}

template <typename T>
Octagon<T> &Octagon<T>::operator = (Figure<T> &&other) {
    Octagon<T> *ptr = static_cast<Octagon<T>*>(&other);
    if (ptr) {
        Figure<T>::_points = std::swap(other._points);
        return *this;
    } else {
        throw std::logic_error("can't assign different types of figures");
    }
}