#include "hexagon.h"

Hexagon::Hexagon(const std::vector<Point> & points) {
    if (points.size() != 6) {
        throw std::range_error("invalid number of coordinates");
    } else if (!valid(points)){
        throw std::range_error("Error! Square Constructor: invalid points");
    } else {
        _points = points;
    }
}

Hexagon::Hexagon(const Hexagon &other) {
    _points = other._points;
}

bool Hexagon::valid(const std::vector<Point> &p) const{

    for (size_t i = 0; i < 6 - 2; ++i) {
        if (fabs(p[i].distance(p[i+1]) - p[i+1].distance(p[i+2])) > EPSILON)  return false;
    }
    double l = p[0].distance(p[1]);
    if (l < EPSILON) return false;
    if (fabs(p[0].distance(p[5]) -  l) > EPSILON) return false;
    for (size_t i = 0; i < 6 - 3; ++i) {
        if (fabs(p[i].distance(p[i+3]) - 2 * l) > EPSILON) return false;
    }
    return true;
}

Hexagon::operator double() const {
    return std::pow(this->_points[0].distance(this->_points[1]), 2) * 3 * std::pow(3, 0.5) / 2;
}

bool Hexagon::isEqual(const Figure &other) const {
    return other.getPoints()[0].distance(other.getPoints()[1]) - _points[0].distance(_points[1]) < EPSILON;
}

Point Hexagon::getCenter() const {
    Point tmp = getAv(this->_points);
    return tmp;
}

void Hexagon::print(std::ostream& os) const{
    if (_points.size() == 0) {
        throw std::logic_error("can't print empty figure");
    }
    for (size_t i = 0; i < 6; i++) {
        os << _points[i];
    }
}

void Hexagon::input(std::istream &is) {
    std::vector<Point> tmpV;
    Point tmp;
    for (size_t i = 0; i < 8; ++i) {
        is >> tmp;
        tmpV.push_back(tmp);
    }
    if (!valid(tmpV)) {
        throw std::range_error("Error! Square Constructor: invalid points");
    } else {
        _points = tmpV;
    }
}