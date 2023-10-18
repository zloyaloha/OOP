#include "figure.h"
#include "point.h"
#include <cmath>
#define PI 3.14159265
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Figure {
    public:
        Triangle();
        Triangle(const Point &refPoint, const Point &_sideLen);
        Triangle(const Triangle &other);
        ~Triangle() = default;
        bool operator==(const Figure &other) const override;
        void print(std::ostream &os) const override;
        void input(std::istream &os) override;
        Figure &operator=(const Figure &other) override;
        Point getThirdVertex() const;
        operator double() const override;
        Point getCenter() const override;
};



#endif