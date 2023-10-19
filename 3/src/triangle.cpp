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

Triangle::Triangle(const Triangle &other) : _points(other._points) {}


bool Triangle::valid(const std::vector<Point> &p){
    double x = (p[0].getX() - p[1].getX())*std::cos(PI / 3) - (p[0].getY() - p[1].getY())*std::sin(PI / 3) + p[1].getX();
    double y = (p[0].getX() - p[1].getX())*std::sin(PI / 3) + (p[0].getY() - p[1].getY())*std::cos(PI / 3) + p[1].getY();
    Point third(x,y);
    return third == p[2];
}

Triangle::operator double() const {
    return std::pow(this->_points[0].distance(this->_points[1]), 2) * std::pow(3, 0.5) / 4;
}

bool Triangle::isEqual(const Figure &other) const {
    return other.getPoints()[0].distance(other.getPoints()[1]) == _points[0].distance(_points[1]);
}

Point Triangle::getCenter() const {
    Point tmp = getAv(this->_points);
    return tmp;
}

// Figure& Triangle::operator=(const Figure& other) {
//     if (this == &other) {
//         return *this;
//     }
//     const Triangle* triangle = dynamic_cast<const Triangle*>(&other);
//     if (triangle) {
//         this->_refPoint = triangle->_refPoint;
//         this->_vertex = triangle->_vertex;
//     }
//     return *this;
// }

void Triangle::print(std::ostream& os) const{
    for (size_t i = 0; i < 3; i++) {
        os << _points[i];
    }
}
// void Triangle::input(std::istream &is) {
//     is >> this->_refPoint; is >> this->_vertex;
// }