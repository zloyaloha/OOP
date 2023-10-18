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
        Point getRef() const;
        Point getVertex() const;
        virtual void print(std::ostream &os) const = 0;
        virtual void input(std::istream &os) = 0;
        virtual operator double () const = 0;
        virtual bool operator==(const Figure &lhs) const = 0;
        virtual Point getCenter() const = 0;
        virtual Figure &operator = (const Figure &other);
        friend std::ostream &operator << (std::ostream& os, const Figure& f);
        friend std::istream &operator >> (std::istream& is, Figure& f);
    protected:
        Point _refPoint;
        Point _vertex;
};

#endif 