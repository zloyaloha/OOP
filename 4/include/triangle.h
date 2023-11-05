#pragma once
#include "figure.h"

template <typename T>
class Triangle: public Figure<T> {
    friend std::ostream& operator << (std::ostream& os, const Triangle<T> &fig) {
        os << "Triangle\n" << fig._points;
        return os;
    }
    friend std::istream& operator >> (std::istream& is, const Triangle<T> &fig) {
        Array<Point<T>> tmpV;
        Point<T> tmp;
        for (size_t i = 0; i < Figures::Triangle; ++i) {
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
        Triangle();
        Triangle(const std::initializer_list<Point<T>> &list);
        Triangle(const Triangle<Point<T>> &other);
        Triangle(Triangle<Point<T>> &&other) noexcept;
        virtual ~Triangle() noexcept = default;

        Point<T> getCenter() const;
        operator double() const;

        bool operator==(const Figure<T> &other) const;
        Triangle<T> &operator = (Figure<T> &other);
    private:
        bool valid(const std::initializer_list<Point<T>> &list);
};

template <typename T>
Triangle<T>::Triangle(): Figure<T>() {}

template <typename T>
Triangle<T>::Triangle(const Triangle<Point<T>> &other): Figure<T>(other) {}

template <typename T>
Triangle<T>::Triangle(Triangle<Point<T>> &&other) noexcept: Figure<T>(other) {}

template <typename T>
Triangle<T>::Triangle(const std::initializer_list<Point<T>> &list) {
    if (list.size() != 3) {
        throw std::range_error("invalid number of coordinates");
    } else if (!valid(list)){
        throw std::range_error("Error! Triangle Constructor: invalid points");
    } else {
        Array<Point<T>> tmp(list);
        Figure<T>::_points = list;
    }
}

template <typename T>
bool Triangle<T>::valid(const std::initializer_list<Point<T>> &list) {
    Array<Point<T>> tmp(list);
    double l1 = tmp[0].distance(tmp[1]), l2 = tmp[0].distance(tmp[2]), l3 = tmp[0].distance(tmp[2]);
    return fabs(l1 - l2) < EPSILON && fabs(l2 - l3) < EPSILON && fabs(l1 - l3) < EPSILON;
}

template <typename T>
Point<T> Triangle<T>::getCenter() const {
    if (Figure<T>::_points.size() == 0) {
        throw std::range_error("can't get center of empty");
    }
    Point<T> tmp = getAv(Figure<T>::_points);
    return tmp;
}

template <typename T>
Triangle<T>::operator double() const {
    if (Figure<T>::_points.size() == 0) {
        throw std::range_error("can't get square of empty");
    }
    return std::pow((Figure<T>::_points[0]).distance((Figure<T>::_points[1])), 2) * std::pow(3,0.5) / 4;
}

template <typename T>
bool Triangle<T>::operator ==(const Figure<T> &other) const{
    const Triangle<T> *ptr = static_cast<const Triangle<T>*>(&other);
    if (ptr) {
        return (Figure<T>::_points[0]).distance((Figure<T>::_points[1])) == (Figure<T>::other._points[0]).distance((Figure<T>::other._points[1]));
    } else {
        return false;
    }
}

template <typename T>
Triangle<T> &Triangle<T>::operator = (Figure<T> &other) {
    Triangle<T> *ptr = static_cast<const Triangle<T>*>(&other);
    if (ptr) {
        Figure<T>::_points = other._points;
        return *this;
    } else {
        throw std::logic_error("can't assign different types of figures");
    }
}