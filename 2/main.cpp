#include <iostream>
#include "eleven.h"

int main(){
    // try {
    //     Eleven el1(6, '-');
    // } catch (const std::range_error &err) {
    //     std::cout << err.what() << std::endl;
    // }
    Eleven ds2{"777"};
    Eleven ds1("777");    // ds1.print(std::cout) << std::endl;
    // ds2.print(std::cout) << std::endl;
    ds1.Add(ds2);
}