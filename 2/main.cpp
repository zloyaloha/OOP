#include <iostream>
#include "eleven.h"

int main(){
    Eleven el1{"123AA236723AA"}, el2{"12311"}, el3{"311"}, el5("111111AA112322645789203633"), el6("111111AA11232140585329879A");
    el2 -= el3;
    std::cout << el2;
    std::cout << el5 - el3;
}
