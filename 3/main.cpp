#include "triangle.h"

int main() {
    Triangle tr(Point(1,2), Point(3,4));
    Triangle tr1(Point(5,6), Point(1,2));
    Triangle t;
    std::cin >> t;
    std::cout << t;
    // std::cout << (tr == tr1);
    tr = tr1;
    // std::cout << tr1;
    // std::cout << tr.getCenter();
}