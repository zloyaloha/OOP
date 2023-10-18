#include "figure.h"

Figure::~Figure() {}

Figure::Figure() : _refPoint(0,0), _vertex(0, 0) {}

Figure::Figure(const Point &first, const Point &second) : _refPoint(first), _vertex(second) {}

Figure::Figure(const Figure &other) : _refPoint(other.getRef()), _vertex(other.getVertex()) {}

Point Figure::getRef() const{
    return _refPoint;
}

Point Figure::getVertex() const{
    return _vertex;
}

Figure& Figure::operator=(const Figure& other) {
    if (this == &other) {
        return *this;
    }
    _refPoint = other._refPoint;
    _vertex = other._vertex;
    return *this;
}

std::ostream& operator << (std::ostream& os, const Figure& p) {
    p.print(os);
    return os;
}

std::istream& operator >> (std::istream& is, Figure& f) {
    f.input(is);
    return is;
}



