#include "eleven.h"

Eleven::Eleven(): _size(0), _eleven{nullptr} {
    std::cout << "default constr" << std::endl;
}

Eleven::Eleven(const size_t &size, unsigned char t) {
    _eleven = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        _eleven[i] = 0;
    }
    _size = size;
}

void Eleven::print()
{
    for (size_t i = 0; i < _size; ++i)
        std::cout << _eleven[i];
}