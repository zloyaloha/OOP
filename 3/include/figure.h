#include <iostream>
#include <vector>
#include <string_view>
#include <algorithm>
#include <utility>
#include <ostream>
#include <cmath>
#include "point.h"
#ifndef FIGURE_H
#define FIGURE_H


class Figure {
    public :
        Figure();
        Figure(std::vector<Point> &p);
        Figure(const Figure &other);
        ~Figure() = default;
        virtual void print(std::ostream &os) const = 0;
        // virtual void input(std::istream &os) = 0;
        std::vector<Point> getPoints() const;
        virtual operator double () const = 0;
        friend bool operator==(const Figure &lhs, const Figure &rhs);
        virtual bool isEqual(const Figure &other) const = 0;
        virtual Point getCenter() const = 0;
        // virtual Figure &operator = (const Figure &other);
        friend std::ostream &operator << (std::ostream& os, const Figure& f);
        // friend std::istream &operator >> (std::istream& is, Figure& f);
    protected:
        std::vector<Point> _points;
};

#endif 