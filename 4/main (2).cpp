#include "octagon.h"
#include <ostream>

int main() {
    std::initializer_list<Point<double>> list{Point(-5.0,0.0), Point(9.0,-4.0), Point(21.73, 3.07), Point(25.73, 17.07), Point(18.66, 29.80), Point<double>(4.66, 33.80), Point<double>(-8.07, 26.73), Point(-12.07, 12.73)};
    Octagon<double> oct{list};
    std::cout << oct.getPoints();
    std::cout << double (oct);
    Array<int> arr{1,2,3,4,5};
    Array<int> arr1;
    arr1 = arr;
    std::cout << arr1;
}