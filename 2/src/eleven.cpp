#include "eleven.h"
#include "help.h"

Eleven::Eleven() {
    _size = 1;
    _array = new unsigned char[_size];
    _array[0] = '0';
}

Eleven::Eleven(const size_t &size, unsigned char t){
    _array = new unsigned char[size];
    for (size_t i {0}; i < size; ++i) {
        if ((t >= '0' && t <= '9') || t == 'A') {
            _array[i] = t;
        } else {
            throw std::range_error("Invalid digit");
        }
    }
    _size = size;
}

Eleven::Eleven(const std::initializer_list<unsigned char> &list) {
    _array = new unsigned char[list.size()];
    bool flag = false;
    size_t i{list.size() - 1};
    size_t counter{0};
    for (const auto &c: list) {
        if (flag == false) {
            if (c == '0') {
                i--;
                counter++;
                continue;
            } else if ((c > '0' && c <= '9') || c == 'A') {
                _array[i--] = c;
                flag = true;
            } else {
                throw std::range_error("Invalid digit");
            }
        } else {
            if ((c >= '0' && c <= '9') || c == 'A') {
                _array[i--] = c;
            } else {
                throw std::range_error("Invalid digit");
            }
        }
    }
    if (flag == false) {
        _size = 1;
        _array[0] = '0';
    } else {
        _size = list.size() - counter;
    }
}

Eleven::Eleven(const std::string &str) {
    _size  = str.size();
    _array = new unsigned char[_size];
    bool flag = false;
    int counter = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (flag == false) {
            if (str[i] == '0') {
                counter++;
                continue;
            } else if ((str[i] >= '0' && str[i] <= '9') || str[i] == 'A') {
                _array[_size - i - 1] = str[i];
                flag = true;
            } else {
                throw std::range_error("Invalid digit");
            }
        } else {
            if ((str[i] >= '0' && str[i] <= '9') || str[i] == 'A') {
                _array[_size - i - 1] = str[i];
            } else {
                throw std::range_error("Invalid digit");
            }
        }
    }
    if (flag == false) {
        _size = 1;
        _array[0] = '0';
    } else {
        _size = str.size() - counter;
    }
}

Eleven::Eleven(const Eleven &other)
{
    _size  = other._size;
    _array = new unsigned char[_size];
    for (int i = _size - 1; i >= 0; --i) _array[i] = other._array[i];
}

Eleven::Eleven(Eleven &&other) noexcept
{
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}

std::ostream &Eleven::print(std::ostream &os)
{   
    os << "Size: " << _size << '\n';
    os << "Num: ";
    for (int i = _size - 1; i >= 0; --i)
        os << _array[i];
    os << '\n';
    return os;
}

Eleven Eleven::DelNulls() {
    int i = _size - 1;
    while (_array[i] == '0' && i >= 0) {
        i--;
    }
    if (i == -1) {
        _size = 1;
    } else {
        _size = _size - i - 1;
    }
    return *this;
}

Eleven::~Eleven() noexcept {   
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

bool Eleven::Equals(const Eleven &other) const {
    if (other._size != _size) {
        return false;
    } else {
        for (size_t i = 0; i < _size; ++i) {
            if (_array[i] != other._array[i]) {
                return false;
            }
        }
    }
    return true;
}

bool Eleven::More(const Eleven &other) const {
    if (_size > other._size) {
        return true;
    } else if (_size == other._size) {
        for (int i = _size - 1; i >= 0; i--) {
            if (_array[i] > other._array[i]) {
                return true;
            } else if (_array[i] < other._array[i]) {
                return false;
            }
        }
        return false;
    } else {
        return false;
    }
}

bool Eleven::Less(const Eleven &other) const {
    if (_size > other._size) {
        return false;
    } else if (_size == other._size) {
        for (int i = _size - 1; i >= 0; i--) {
            if (_array[i] > other._array[i]) {
                return false;
            } else if (_array[i] < other._array[i]) {
                return true;
            }
        }
        return false;
    } else {
        return true;
    }
}

Eleven Eleven::Max(const Eleven &other) {
    return (*this).More(other) ? *this : other;
}

void Eleven::CopyP1() {
    unsigned char *tmpArray = new unsigned char[_size + 1];
    tmpArray[_size] = '0';
    for (size_t i = 0; i < _size; ++i) {
        tmpArray[i] = _array[i];
    }
    _array = tmpArray;
    _size++;
}

Eleven Eleven::Add(const Eleven &other) {
    size_t i = 0;
    char mod = '0';
    Eleven r;
    while (i < other._size && i < _size) {
        r._array[i] = Adding(Adding(other._array[i], _array[i]).first, mod).first;
        if (Adding(other._array[i], _array[i]).first == 'A' && mod == '1') {
            mod = '1';
        } else {
            mod = Adding(other._array[i], _array[i]).second;
        }
        i++;
        r.CopyP1();
    }
    r._array[_size] = mod;
    while (i < _size) {
        r._array[i] = Adding(mod, _array[i]).first;
        mod = Adding(mod, _array[i]).second;
        i++;
        r.CopyP1();
    }
   while (i < other._size) {
        r._array[i] = Adding(mod, other._array[i]).first;
        mod = Adding(other._array[i], mod).second;
        i++;
        r.CopyP1();
    }
    if (mod == '0') {
        r._size--;
    } else {
        r._array[_size] = mod;
    }
    return r;
}