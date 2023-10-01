#include <iostream>
#include <string>

class Eleven {
    public:
        Eleven();
        Eleven(const size_t &size, unsigned char t = 0);
        // Eleven(const std::initializer_list< unsigned char> &t);
        // Eleven(const std::string &t);
        // Eleven(const Eleven& other);
        // Eleven(Eleven&& other) noexcept;
        // virtual ~Eleven() noexcept;

        void print();

    private:
        size_t _size;
        unsigned char *_eleven;  
};
