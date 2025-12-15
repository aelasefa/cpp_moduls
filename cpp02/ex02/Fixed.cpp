#include "Fixed.hpp"


const int Fixed::FractionalBits = 8;


Fixed::Fixed() : RawValue(0)
{
	if (DEBUG_MESSAGES)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	if (DEBUG_MESSAGES)
		std::cout << "Int constructor called" << std::endl;
    RawValue = n << FractionalBits;
}

Fixed::Fixed(const float f)
{
	if (DEBUG_MESSAGES)
		std::cout << "Float constructor called" << std::endl;
    RawValue = roundf(f * (1 << FractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	if (DEBUG_MESSAGES)
		std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
	if (DEBUG_MESSAGES)
    std::cout << "Destructor called" << std::endl;
}


Fixed &Fixed::operator=(const Fixed &other)
{
	if (DEBUG_MESSAGES)
		std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        RawValue = other.RawValue;
    return *this;
}


int Fixed::getRawBits(void) const
{
    return RawValue;
}

void Fixed::setRawBits(int const raw)
{
    RawValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)RawValue / (1 << FractionalBits);
}

int Fixed::toInt(void) const
{
    return RawValue >> FractionalBits;
}


bool Fixed::operator>(const Fixed &other) const
{
    return RawValue > other.RawValue;
}

bool Fixed::operator<(const Fixed &other) const
{
    return RawValue < other.RawValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return RawValue >= other.RawValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return RawValue <= other.RawValue;
}

bool Fixed::operator==(const Fixed &other) const
{
    return RawValue == other.RawValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return RawValue != other.RawValue;
}


Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    RawValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    RawValue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    RawValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    RawValue--;
    return temp;
}


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}


std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}
