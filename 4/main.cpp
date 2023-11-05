#include "octagon.h"
#include "triangle.h"
#include "hexagon.h"
#include "figure-array.h"
#include <ostream>

int main() {
    std::initializer_list<Point<double>> list{Point(-5.0,0.0), Point(9.0,-4.0), Point(21.73, 3.07), Point(25.73, 17.07), Point(18.66, 29.80), Point<double>(4.66, 33.80), Point<double>(-8.07, 26.73), Point(-12.07, 12.73)};
    std::initializer_list<Point<double>> listT{Point(0.79, 1.1), Point(3.37, 1.98), Point(1.32, 3.77)};
    Triangle<double> triag(listT);
    Octagon<double> oct{list};
    Array<Figure<double>*> arr1({&triag, &oct});
    getAreas(arr1);
    // getCenteres(arr1);
    // getCoords(arr1);
}