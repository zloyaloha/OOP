#include "figure.h"
#include "point.h"
#include <cmath>
#define PI 3.14159265
#ifndef HEXAGON_H
#define HEXAGON_H

class Hexagon : public Figure {
    public:
        Hexagon() = default;
        Hexagon(const std::vector<Point> & points);
        Hexagon(const Hexagon & other);
        virtual ~Hexagon() noexcept = default;
        // Figure &operator=(const Figure &other) override;
        operator double() const override;
        Point getCenter() const override;
    private:
        bool isEqual(const Figure &other) const override;
        bool valid(const std::vector<Point> &p) const override;
        void print(std::ostream &os) const override;
        void input(std::istream &os) override;
};

#endif