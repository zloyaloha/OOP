#include "list.h"

int main() {
    List<int> a{1,2,3,4,5};
    List<int> b(a);
    std::cout << a << b;
    std::cout << (a == b);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    // std::cout << a;
    a.remove();
    a.pop();
    // std::cout << (a == b);

}