#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int RawValue;
    static const int FractionalBits;

public:
    Fixed();
    Fixed(const int Number);
    Fixed(const float FloatingPointNumber);
    Fixed(const Fixed& obj);
    Fixed &operator=(const Fixed& obj);

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);

    ~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif

