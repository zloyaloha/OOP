#include "figure.h"
#include "point.h"
#include <cmath>
#define PI 3.14159265
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Figure {
    public:
        Triangle() = default;
        Triangle(const std::vector<Point> & points);
        Triangle(const Triangle & other);
        virtual ~Triangle() noexcept = default;
        operator double() const override;
        Point getCenter() const override;
    private:
        bool isEqual(const Figure &other) const override;
        bool valid(const std::vector<Point> &p) const override;
        void print(std::ostream &os) const override;
        void input(std::istream &os) override;
};



#endif