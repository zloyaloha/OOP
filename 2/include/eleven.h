#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <cstring>

class Eleven {
    public:

        Eleven();
        Eleven(const size_t &size, unsigned char t = 0);
        Eleven(const std::initializer_list< unsigned char> &list);
        Eleven(const std::string &str);
        Eleven(const Eleven &other);
        Eleven(Eleven &&other) noexcept;
        virtual ~Eleven() noexcept;

        bool operator <(const Eleven &other) const;
        bool operator <=(const Eleven &other) const;
        bool operator >=(const Eleven &other) const;
        bool operator >(const Eleven &other) const;
        bool operator == (const Eleven& other) const;
        bool operator !=(const Eleven &other) const;

        Eleven operator +(const Eleven &other);
        Eleven operator -(const Eleven &other);
        Eleven &operator +=(const Eleven &other);
        Eleven &operator -=(const Eleven &other);

        Eleven Max(const Eleven &a, const Eleven &b);
        Eleven Min(const Eleven &a, const Eleven &b);
        Eleven& operator=(const Eleven &other);
        void CopyP1();
        void CopyM1();

        friend std::ostream& operator << (std::ostream &os, const Eleven &el);
        friend std::istream& operator >> (std::istream &stream, Eleven &el);

    private: 
        size_t _size;
        unsigned char *_array;
};