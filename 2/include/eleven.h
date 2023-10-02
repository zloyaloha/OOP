#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <algorithm>

class Eleven {
    public:
        Eleven DelNulls();
        Eleven();
        Eleven(const size_t &size, unsigned char t = 0);
        Eleven(const std::initializer_list< unsigned char> &list);
        Eleven(const std::string &str);
        Eleven(const Eleven &other);
        Eleven(Eleven &&other) noexcept;
        bool Less(const Eleven &other) const;
        bool More(const Eleven &other) const;
        bool Equals(const Eleven &other) const;
        Eleven Max(const Eleven &other);
        Eleven Add(const Eleven &other);
        void CopyP1();
        Eleven Assingment(const Eleven &&other);
        std::ostream& print(std::ostream& os);
        virtual ~Eleven() noexcept;
    private: 
        size_t _size;
        unsigned char *_array;
};