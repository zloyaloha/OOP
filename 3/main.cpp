#include "triangle.h"
#include "hexagon.h"
int main() {
    Triangle t(std::vector<Point> {Point(5.82,9.12), Point(10,8), Point(6.94,4.94001)});
    Triangle t1(std::vector<Point> {Point(10,8), Point(5.82,9.12), Point(8.88, 12.18)});
    Triangle t2(std::move(t1));
    std::cout <<  (double) t << ' ' << (double) t1 << std::endl;
    std::cout << t2;
}