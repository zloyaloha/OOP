#include "triangle.h"

Triangle::Triangle() : Figure() {}

Triangle::Triangle(const Point &point1, const Point &point2)
    : Figure(point1, point2) {}

Triangle::Triangle(const Triangle &other)
    : Figure(other) {}


Triangle:: operator double() const {
    return std::pow(this->_refPoint.distance(this->_vertex), 2) * std::pow(3, 0.5) / 4;
}

Point Triangle::getThirdVertex() const{
    double x3 = ((*this)._refPoint.getX() - (*this)._vertex.getX())*std::cos(PI / 3) - ((*this)._refPoint.getY() - (*this)._vertex.getY())*std::sin(PI / 3) + (*this)._vertex.getX();
    double y3 = ((*this)._refPoint.getX() - (*this)._vertex.getX())*std::sin(PI / 3) + ((*this)._refPoint.getY() - (*this)._vertex.getY())*std::cos(PI / 3) + (*this)._vertex.getY();
    return Point(x3,y3);
}

bool Triangle::operator==(const Figure &other) const {
    const Triangle & ptr = dynamic_cast<const Triangle &>(other);
    if (ptr != 0) {
        return this->_refPoint.distance(this->_vertex) == other.getRef().distance(other.getVertex());
    }
    return false;
}

Point Triangle::getCenter() const {
    Point thirdPoint((*this).getThirdVertex());
    Point tmp(((*this).getRef().getX() + (*this).getVertex().getX() + thirdPoint.getX()) / 3, ((*this).getRef().getY() + (*this).getVertex().getY() + thirdPoint.getY()) / 3);
    return tmp;
}

Figure& Triangle::operator=(const Figure& other) {
    if (this == &other) {
        return *this;
    }
    const Triangle* triangle = dynamic_cast<const Triangle*>(&other);
    if (triangle) {
        this->_refPoint = triangle->_refPoint;
        this->_vertex = triangle->_vertex;
    }
    return *this;
}

void Triangle::print(std::ostream& os) const{
    os << "First vertex: " << this->_refPoint << "Second vertex: " << this->_vertex << "Third vertex: " << this->getThirdVertex() << std::endl;
}

void Triangle::input(std::istream &is) {
    is >> this->_refPoint; is >> this->_vertex;
}