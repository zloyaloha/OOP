#include <iostream>
#include <vector>
#include <cmath>
#include <array.h>
#define EPSILON 0.01
#define PI 3.141592653

template <typename T>
class Point {
    friend std::ostream& operator << (std::ostream& os, const Point<T> &point) {
        return os << "x = " << point._x << ", y = " << point._y << std::endl;
    }
    friend Point<T> getAv(const Array<Point<T>> &p) {
        T sumX=0, sumY=0;
        for (size_t i = 0; i < p.size(); i++) {
            sumX += p[i].getX();
            sumY += p[i].getY();
        }
        return Point(sumX / p.size(), sumY / p.size());
    }
    public :
        Point();
        Point(const T &newX, const T &newY);
        Point(const Point &other);
        virtual ~Point() noexcept;
        bool operator == (const Point<T> &other) const;
        bool operator != (const Point<T> &other) const;
        Point<T> &operator=(const Point<T> &other);
        T getX() const;
        T getY() const;
        double distance(const Point &other) const;
    private:
        T _x;
        T _y;
};

template <typename T>
Point<T>::Point() : _x(), _y() {}

template <typename T>
Point<T>::Point(const T &newX, const T &newY) : _x(newX), _y(newY) {}

template <typename T>
Point<T>::Point(const Point<T> &other) : _x(other._x), _y(other._y) {}

template <typename T>
Point<T>::~Point() noexcept{}

template <typename T>
bool Point<T>::operator == (const Point<T> &other) const {
    return this->distance(other) < EPSILON ? true : false;
}

template <typename T>
bool Point<T>::operator != (const Point<T> &other) const {
    return !(*this == other);
}

template <typename T>
T Point<T>::getX() const {
    return _x;
}

template <typename T>
T Point<T>::getY() const {
    return _y;
}

template <typename T>
double Point<T>::distance(const Point &other) const {
    return pow((pow(_x - other._x, 2) + pow(_y - other._y, 2)), 0.5);
}

template <typename T>
Point<T> &Point<T>::operator=(const Point<T> &other) {
    _y = other._y;
    _x = other._x;
    return *this;
}