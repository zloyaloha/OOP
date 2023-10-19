// #include "figure.h"
// #include "point.h"
// #include <cmath>
// #define PI 3.14159265
// #ifndef HEXAGON_H
// #define HEXAGON_H

// class Hexagon : public Figure {
//     public:
//         Hexagon();
//         Hexagon(const Point &refPoint, const Point &_sideLen);
//         Hexagon(const Hexagon &other);
//         ~Hexagon() = default;
//         std::vector<Point> getVertexes() const;
//         operator double() const override;
//         bool isEqual(const Figure &other) const override;
//         Figure &operator=(const Figure &other) override;
//         Point getCenter() const override;
//     private: 
//         void print(std::ostream &os) const override;
//         void input(std::istream &os) override;
// };

// #endif