#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;


Fixed::Fixed() : RawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int Number)
{
    std::cout << "Int constructor called" << std::endl;
    RawValue = Number << FractionalBits;
}

Fixed::Fixed(const float FloatingPointNumber)
{
    std::cout << "Float constructor called" << std::endl;
    RawValue = roundf(FloatingPointNumber * (1 << FractionalBits));
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}


Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        RawValue = obj.getRawBits();
    return *this;
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (float)RawValue / (1 << FractionalBits);
}

int Fixed::toInt(void) const
{
    return RawValue >> FractionalBits;
}

int Fixed::getRawBits(void) const
{
    return RawValue;
}

void Fixed::setRawBits(int const raw)
{
    RawValue = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}

