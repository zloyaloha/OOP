#include "triangle.h"

Triangle::Triangle() : Figure() {}

Triangle::Triangle(const Point &point1, const Point &point2)
    : Figure(point1, point2) {}

Triangle::Triangle(const Triangle &other)
    : Figure(other) {}


Triangle:: operator double() const {
    return std::pow(this->_refPoint.distance(this->_vertex), 2) * std::pow(3, 0.5) / 4;
}


std::istream& operator >> (std::istream& is, Triangle& triag) {
    is >> triag._refPoint; is >> triag._vertex;
    return is;
}

Point Triangle::getThirdVertex() const{
    double x3 = ((*this)._refPoint.getX() - (*this)._vertex.getX())*std::cos(PI / 3) - ((*this)._refPoint.getY() - (*this)._vertex.getY())*std::sin(PI / 3) + (*this)._vertex.getX();
    double y3 = ((*this)._refPoint.getX() - (*this)._vertex.getX())*std::sin(PI / 3) + ((*this)._refPoint.getY() - (*this)._vertex.getY())*std::cos(PI / 3) + (*this)._vertex.getY();
    return Point(x3,y3);
}

std::ostream& operator << (std::ostream &os, const Triangle& tr) {
    os << "First vertex: " << tr._refPoint << "Second vertex: " << tr._vertex << "Third vertex: " << tr.getThirdVertex() << std::endl;
    return os;
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

Figure &Triangle::operator=(const Figure &other) {
    const Triangle &ptr = dynamic_cast<const Triangle &>(other);
    _vertex = ptr.getVertex();
    _refPoint = ptr.getRef();
    return *this;
}

Figure &Triangle::operator=(const Figure &&other) {
    _refPoint = other.getRef();
    _vertex = other.getVertex();
    delete &other;
    return (*this);
}