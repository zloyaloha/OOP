#include "eleven.h"
#include "help.h"

Eleven::Eleven()
{
    _size = 1;
    _array = new unsigned char[_size];
    _array[0] = '0';
}

Eleven::Eleven(const size_t &size, unsigned char t)
{
    _array = new unsigned char[size];
    for (size_t i{0}; i < size; ++i)
    {
        if ((t >= '0' && t <= '9') || t == 'A')
        {
            _array[i] = t;
        }
        else
        {
            throw std::range_error("Invalid digit");
        }
    }
    _size = size;
}

Eleven::Eleven(const std::initializer_list<unsigned char> &list)
{
    _array = new unsigned char[list.size()];
    bool flag = false;
    size_t i{list.size() - 1};
    size_t counter{0};
    for (const auto &c : list)
    {
        if (flag == false)
        {
            if (c == '0')
            {
                i--;
                counter++;
                continue;
            }
            else if ((c > '0' && c <= '9') || c == 'A')
            {
                _array[i--] = c;
                flag = true;
            }
            else
            {
                throw std::range_error("Invalid digit");
            }
        }
        else
        {
            if ((c >= '0' && c <= '9') || c == 'A')
            {
                _array[i--] = c;
            }
            else
            {
                throw std::range_error("Invalid digit");
            }
        }
    }
    if (flag == false)
    {
        _size = 1;
        _array[0] = '0';
    }
    else
    {
        _size = list.size() - counter;
    }
}

Eleven::Eleven(const std::string &str)
{
    _size = str.size();
    _array = new unsigned char[_size];
    bool flag = false;
    int counter = 0;
    for (int i = 0; i < str.size(); ++i) 
    {
        if (flag == false) {
            if (str[i] == '0') 
            {
                counter++;
                continue;
            }
            else if ((str[i] >= '0' && str[i] <= '9') || str[i] == 'A') 
            {
                _array[_size - i - 1] = str[i];
                flag = true;
            } 
            else 
            { 
                throw std::range_error("Invalid digit");
            }
        } else {
            if ((str[i] >= '0' && str[i] <= '9') || str[i] == 'A') 
            {
                _array[_size - i - 1] = str[i];
            } 
            else 
            {
                throw std::range_error("Invalid digit");
            }
        }
    }
    if (flag == false) 
    {
        _size = 1;
        _array[0] = '0';
    } 
    else 
    {
        _size = str.size() - counter;
    }
}

Eleven::Eleven(const Eleven &other)
{   
    _size = other._size;
    _array = new unsigned char[_size];
    for (int i = _size - 1; i >= 0; --i)
        _array[i] = other._array[i];
}

Eleven::Eleven(Eleven &&other) noexcept
{   
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}

Eleven::~Eleven() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

Eleven &Eleven::operator=(const Eleven &other)
{
    _size = other._size;
    _array = new unsigned char[_size];
    std::memcpy(_array, other._array, other._size * sizeof(unsigned char));
    return *this;
}

bool Eleven::operator==(const Eleven &other) const
{
    if (other._size != _size)
    {
        return false;
    }
    else
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (_array[i] != other._array[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool Eleven::operator!=(const Eleven &other) const
{
    return !(*this == other);
}

bool Eleven::operator>(const Eleven &other) const
{
    if (_size > other._size)
    {
        return true;
    }
    else if (_size == other._size)
    {
        for (int i = _size - 1; i >= 0; i--) 
        {
            if (_array[i] > other._array[i])
            {
                return true;
            }
            else if (_array[i] < other._array[i])
            {
                return false;
            }
        }
        return false;
    }
    else
    {
        return false;
    }
}

bool Eleven::operator>=(const Eleven &other) const
{
    if (_size > other._size)
    {
        return true;
    }
    else if (_size == other._size)
    {
        for (int i = _size - 1; i >= 0; i--)
        {
            if (_array[i] > other._array[i])
            {
                return true;
            }
            else if (_array[i] < other._array[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Eleven::operator<(const Eleven &other) const
{
    return !((*this) >= other);
}

bool Eleven::operator<=(const Eleven &other) const
{
    return !((*this) > other);
}


void Eleven::ResizeCopy(int n) {
    unsigned char *tmpArr = new unsigned char[n];
    std::memcpy(tmpArr, _array, n * sizeof(unsigned char));
    delete [] this->_array;
    this->_array = tmpArr;
    this->_size = n;
}

Eleven Eleven::operator+(const Eleven &other)
{
    size_t i = 0;
    char mod = '0';
    int size = other._size > _size ? other._size : _size;
    Eleven r(size + 1, '0');
    while (i < other._size && i < _size) {
        r._array[i] = Adding(other._array[i], _array[i], mod).first;
        mod = Adding(other._array[i], _array[i], mod).second;
        i++;
    }
    while (i < _size) {
        r._array[i] = Adding(mod, _array[i], '0').first;
        mod = Adding(mod, _array[i], '0').second;
        i++;
    }
    while (i < other._size) {
        r._array[i] = Adding(mod, other._array[i], '0').first;
        mod = Adding(other._array[i], mod, '0').second;
        i++;
    }
    if (mod == '0') {
        r.ResizeCopy(r._size - 1);
    }
    else {
        r._array[_size] = mod;
    }
    return r;
}

std::ostream &operator<<(std::ostream &os, const Eleven &el)
{
    os << "Num = ";
    for (int i = el._size - 1; i >= 0; --i)
        os << el._array[i];
    os << " | Size: " << el._size << '\n';
    return os;
}

std::istream &operator>>(std::istream &is, Eleven &el)
{
    std::string str;
    is >> str;
    el = Eleven(str);
    return is;
}

Eleven Eleven::operator-(const Eleven &other)
{
    if ((*this) < other) {
        throw std::underflow_error("Result can't be negative");
    } else {
        size_t i = 0;
        Eleven r(_size, '0');
        char mod = '0';
        while (i < other._size) {
            r._array[i] = Substruction(_array[i], other._array[i], mod).first;
            mod = Substruction(_array[i], other._array[i], mod).second;
            i++;
        }
        while (i < _size) {
            r._array[i] = Substruction(_array[i], '0', mod).first;
            mod = Substruction(_array[i], '0', mod).second;
            i++;
        }
        i = r._size - 1;
        int counter0 = 0;
        while (r._array[i--] == '0') {
            counter0++;
        }
        if (counter0 != 0) {
            r.ResizeCopy(r._size - counter0);
        }
        if (r._size == 0) {
            r.ResizeCopy(1);
            r._array[0] = '0';
        }
        return r;
    }
}

Eleven &Eleven::operator-=(const Eleven &other) {
    *this = *this - other;
    return *this;
}

Eleven &Eleven::operator+=(const Eleven &other) {
    *this = *this + other;
    return *this;
}
