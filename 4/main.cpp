#include "point.h"
#include "array.h"
#include <ostream>

template <typename T>
std::ostream &operator << (std::ostream& os, const Array<T> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        os << arr[i] << ' ';
    }
    os << '\n';
    return os;
}

int main() {
    Point<double> a(1.2,2);
    Array<Point<double>> arrP({a});
    Array<int> arrN({1,2,3,4});
    Array<int> arrN1(arrN);
    std::cout << arrN.size() << ' ' << arrN1.size() << std::endl;
    std::cout << arrN1;
}