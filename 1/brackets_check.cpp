#include "brackets_check.h"

bool CheckBrackets(std::string line){
    int counter {0};
    for (char symb: line) {
        switch (symb) {
            case '(': {
                counter++;
            } break;
            case ')': {
                counter--;
            } break;
            default: {
                throw std::string{"Unexpectable input"};
            }
        }
        if (counter < 0) {
            return false;
        }
    }
    if (counter == 0) {
        return true;
    } else {
        return false;
    }
}