#include "list.h"
int main() {
    List<int> a{1,2,3,4,5};
    List<int> b;
    b = std::move(a);
    std::cout << b;
}