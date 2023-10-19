#include <iostream>
#include "../include/point.h"
#define PI 3.14159265

Point getThird(Point &p1, Point &p2) {
    double x = (p1.getX() - p2.getX())*std::cos(PI / 3) - (p1.getY() - p2.getY())*std::sin(PI / 3) + p2.getX();
    double y = (p1.getX() - p2.getX())*std::sin(PI / 3) + (p1.getY() - p2.getY())*std::cos(PI / 3) + p2.getY();
    Point third(x,y);
    return third;
}
int main() {
    Point p1(1.0, 1.0);
    Point p2(1.0, 3.0);
    Point p3(2.0, 2.0);
    Point p4(2.0, 4.0);
    std::cout << getThird(p1, p2);
    std::cout << getThird(p3, p4);
}