#include <map>
#include <vector>
#include "list.h"

int fact(int dig) {
    int res = 1;
    
    for (int i = 1; i <= dig; ++i) {
        res *= i; 
    }

    return res;
}

int main() {
    List<int> l1{1,2,3,4,5};
    List<int> l2{1,2,3,4};
    l1.erase(l1.end());
}