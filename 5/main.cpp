#include "list.h"
int main() {
    List<int> a{1,2,3,4,5};
    std::cout << a.back() << std::endl;
    for (auto iter = a.begin(); iter != a.end(); ++iter) {
        std::cout << "k" << std::endl;
    }

}