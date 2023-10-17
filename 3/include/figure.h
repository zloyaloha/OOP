#include <iostream>
#include <vector>
#include "point.h"
#ifndef FIGURE_H
#define FIGURE_H

class Figure {
    public :
        Figure();
        Figure(const Point &first, const Point &second);
        Figure(const Figure &other);
        ~Figure();
        virtual operator double () const = 0;
        Point getRef() const;
        Point getVertex() const;
        virtual bool operator==(const Figure &lhs) const = 0;
        virtual Point getCenter() const = 0;
        virtual Figure &operator = (const Figure &other) = 0;
        virtual Figure &operator = (const Figure &&other) = 0;
    protected:
        Point _refPoint;
        Point _vertex;
};

#endif 