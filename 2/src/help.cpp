#include "help.h"

size_t CharToInt(const char &c) {
    return c == 'A' ? 10 : c - '0';
}

char IntToChar(const int &c) {
    return c == 10 ? 'A' : '0' + c;
}

std::pair<char, char> Adding(const char &a, const char &b, const char &c) {
    unsigned char aI = CharToInt(a), bI = CharToInt(b), cI = CharToInt(c);
    return aI + bI + cI < 11 ? std::make_pair(IntToChar(aI + bI + cI), '0') : std::make_pair(IntToChar((aI + bI + cI) % 11), '1');
}

std::pair<char, char> Substruction(const char &fwhat, const char &what, const char &mod) {
    unsigned char fwhatI = CharToInt(fwhat), whatI = CharToInt(what), modI = CharToInt(mod);
    return fwhatI - whatI - modI >= 0 ? std::make_pair(IntToChar(fwhatI - whatI - modI), '0') : std::make_pair(IntToChar(11 + fwhatI - whatI - modI), '1');
}
