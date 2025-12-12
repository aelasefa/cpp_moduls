#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->Integer;
}
void Fixed::setRawBits( int const raw )
{
	this->Integer = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
} 
