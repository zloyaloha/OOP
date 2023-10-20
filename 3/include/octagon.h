#include "figure.h"
#include "point.h"
#include <cmath>
#define PI 3.14159265
#ifndef OCTAGON_H
#define OCTAGON_H

class Octagon : public Figure {
    public:
        Octagon() = default;
        Octagon(const std::vector<Point> & points);
        Octagon(const Octagon & other);
        Octagon(const Octagon &&other);
        virtual ~Octagon() noexcept = default;
        operator double() const override;
        Point getCenter() const override;
    private:
        bool isEqual(const Figure &other) const override;
        bool valid(const std::vector<Point> &p) const override;
        void print(std::ostream &os) const override;
        void input(std::istream &os) override;
};

#endif