#include "hexagon.h"

Hexagon::Hexagon() : Figure() {}

Hexagon::Hexagon(const Point &point1, const Point &point2)
    : Figure(point1, point2) {}

Hexagon::Hexagon(const Hexagon &other)
    : Figure(other) {}


Hexagon:: operator double() const {
    return std::pow(this->_refPoint.distance(this->_vertex), 2) * std::pow(3, 0.5)  * 3 / 4;
}

bool Hexagon::operator==(const Figure &other) const {
    const Hexagon & ptr = dynamic_cast<const Hexagon &>(other);
    if (ptr != 0) {
        return this->_refPoint.distance(this->_vertex) == other.getRef().distance(other.getVertex());
    }
    return false;
}

std::vector<Point> Hexagon::getVertexes() const{
    Point center(this->getCenter());
    std::vector<Point> points;
    double x, y;
    for (size_t i = 0; i < 4; i++) {
        x = ((*this)._vertex.getX() - center.getX())*std::cos((i+2)*PI / 3) - ((*this)._vertex.getY() - center.getY())*std::sin((i+2)*PI / 3) + center.getX();
        y = ((*this)._vertex.getX() - center.getX())*std::sin((i+2)*PI / 3) + ((*this)._vertex.getY() - center.getY())*std::cos((i+2)*PI / 3) + center.getY();
        points.push_back(Point(x, y));
    }
    return points;
}

void Hexagon::print(std::ostream& os) const{
    std::vector<Point> p = this->getVertexes();
    os << "1st vertex: " << this->_refPoint << "2nd vertex: " << this->_vertex << "3rd vertex: " << p[0];
    for (size_t i = 1; i < 4; ++i) {
        os << std::to_string(i+3) + "th vertex: " << p[i];
    }
}

void Hexagon::input(std::istream &is) {
    is >> this->_refPoint; is >> this->_vertex;
}

Point Hexagon::getCenter() const {
    double x1 = ((*this)._refPoint.getX() - (*this)._vertex.getX())*std::cos(PI / 3) - ((*this)._refPoint.getY() - (*this)._vertex.getY())*std::sin(PI / 3) + (*this)._vertex.getX();
    double y1 = ((*this)._refPoint.getX() - (*this)._vertex.getX())*std::sin(PI / 3) + ((*this)._refPoint.getY() - (*this)._vertex.getY())*std::cos(PI / 3) + (*this)._vertex.getY();
    return Point(x1,y1);
}

Figure& Hexagon::operator=(const Figure& other) {
    if (this == &other) {
        return *this;
    }
    const Hexagon* triangle = dynamic_cast<const Hexagon*>(&other);
    if (triangle) {
        this->_refPoint = triangle->_refPoint;
        this->_vertex = triangle->_vertex;
    }
    return *this;
}