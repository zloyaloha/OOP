#include "triangle.h"

Triangle::Triangle(const std::vector<Point> & points) {
    if (points.size() != 3) {
        throw std::range_error("invalid number of coordinates");
    } else if (!valid(points)){
        throw std::range_error("Error! Square Constructor: invalid points");
    } else {
        _points = points;
    }
}

Triangle::Triangle(const Triangle &other) {
    _points = other._points;
}


bool Triangle::valid(const std::vector<Point> &p) const{
    double l1 = p[0].distance(p[1]), l2 = p[0].distance(p[2]), l3 = p[0].distance(p[2]);
    return l1 > EPSILON && fabs(l2 - l1) < EPSILON && fabs(pow(l3, 2) - pow(l2, 2) + pow(l1, 2) - 2 * l1 * l2 * cos(PI / 3)) < EPSILON;
}

Triangle::operator double() const {
    return std::pow(this->_points[0].distance(this->_points[1]), 2) * std::pow(3, 0.5) / 4;
}

bool Triangle::isEqual(const Figure &other) const {
    return other.getPoints()[0].distance(other.getPoints()[1]) - _points[0].distance(_points[1]) < EPSILON;
}

Point Triangle::getCenter() const {
    Point tmp = getAv(this->_points);
    return tmp;
}

void Triangle::print(std::ostream& os) const{
    if (_points.size() == 0) {
        throw std::logic_error("can't print empty figure");
    }
    for (size_t i = 0; i < 3; i++) {
        os << _points[i];
    }
}

void Triangle::input(std::istream &is) {
    std::vector<Point> tmpV;
    Point tmp;
    for (size_t i = 0; i < 3; ++i) {
        is >> tmp;
        tmpV.push_back(tmp);
    }
    if (!valid(tmpV)) {
        throw std::range_error("Error! Square Constructor: invalid points");
    } else {
        _points = tmpV;
    }
}