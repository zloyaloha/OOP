#include <iostream>
#include "brackets_check.h"

int main() {
    std::string input;
    std::cout << "Input line of brackets: ";
    std::cin >> input;
    try {
        std::cout << CheckBrackets(input) << std::endl;
    } catch (std::string error_message) {
        std::cout << error_message << std::endl;
    }
}

