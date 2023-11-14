#include "list.h"

int main() {
    List<int> a{1,2,3,4,5};
    std::cout << a;
    List<int> b(a);
    std::cout << b;
}