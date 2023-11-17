#include "list.h"

int main() {
    List<int> a{1,2,3,4,5};
    auto iter = a.begin();
    a.erase(iter);
    std::cout << a << std::endl;
}