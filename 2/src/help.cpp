#include "help.h"

size_t CharToInt(const char &c) {
    return c == 'A' ? 10 : c - '0';
}

char IntToChar(const int &c) {
    return c == 10 ? 'A' : '0' + c;
}

std::pair<char, char> Adding(const char &a, const char &b) {
    char aI = CharToInt(a), bI = CharToInt(b);
    return aI + bI < 11 ? std::make_pair(IntToChar(aI + bI), '0') : std::make_pair(IntToChar((aI + bI) % 11), '1');
}