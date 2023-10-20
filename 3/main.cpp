#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"
#include "time.h"
std::vector<Point> GenerateFigures(int n) {
    std::vector<Point> res;
    srand(time(NULL));
    Point p1(rand() % 10, rand() % 10), p2(rand() % 10, rand() % 10);
    res.push_back(p1);
    res.push_back(p2);
    for (size_t i = 0; i < n - 2; ++i) {
        double x = (res[i].getX()-res[i+1].getX())*cos(-(n-2) * PI / n)-(res[i].getY()-res[i+1].getY())*sin(-(n-2) * PI / n)+res[i+1].getX();
        double y = (res[i].getX()-res[i+1].getX())*sin(-(n-2) * PI / n)+(res[i].getY()-res[i+1].getY())*cos(-(n-2) * PI / n)+res[i+1].getY();
        res.push_back(Point(x,y));
    }
    return res;
}

int main() {
    // Triangle t(std::vector<Point> {Point(1.19,1.41), Point(1.88,4.92), Point(4.57,2.57)});
    // Triangle t1;
    // // Octagon o(std::vector<Point> {Point(2.09,4.69), Point()});
    // // std::cout << t1;
    // Hexagon h(std::vector<Point> {Point(-8.71,-3.29), Point(-6.61,-2.39), Point(-6.34,-0.12), Point(-8.17,1.25), Point(-10.27,0.35), Point(-10.54,-1.92)});
    // std::cout << h;
    // t1 = t;

    // Point p1(2.09, 4.69), p2(5.03,2.85);
    std::vector<Point> res = GenerateFigures(6);
    Hexagon h1(GenerateFigures(6));
    Octagon o1(GenerateFigures(8));
    Octagon o2(o1);
    std::cout << o2;
}