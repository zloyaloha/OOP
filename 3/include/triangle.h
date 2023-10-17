#include "figure.h"
#include "point.h"
#include <cmath>
#define PI 3.14159265
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Figure {
        friend std::ostream& operator << (std::ostream &os, const Triangle& tr);
        friend std::istream& operator >> (std::istream &os, Triangle& tr);
    public:
        Triangle();
        Triangle(const Point &refPoint, const Point &_sideLen);
        Triangle(const Triangle &other);
        ~Triangle() = default;
        bool operator==(const Figure &other) const override;
        Figure &operator=(const Figure &other) override;
        Figure &operator = (const Figure &&other) override;
        Point getThirdVertex() const;
        operator double() const override;
        Point getCenter() const override;
};



#endif