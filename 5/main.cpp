#include <map>
#include "list.h"

int fact(int dig) {
    int res = 1;
    
    for (int i = 1; i <= dig; ++i) {
        res *= i; 
    }

    return res;
}

int main() {
    List<int> l;
    l.emplace(1);
    std::cout << l.front() << ' ' << l.back() << std::endl;
    l.emplace(3);
    std::cout << l.front() << ' ' << l.back() << std::endl;
    l.emplace(2);
    std::cout << l.front() << ' ' << l.back() << std::endl;
    l.emplace(0);
    std::cout << l.front() << ' ' << l.back() << std::endl;
    l.emplace(-9);
    std::cout << l.front() << ' ' << l.back() << std::endl;
}