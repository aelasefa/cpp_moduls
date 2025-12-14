#ifndef  FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed {
private:
	int Integer;
	static const int  FractionalBits;
public:
	Fixed():Integer(0) {
		std::cout << "Default constructor called" << std::endl;
	}
	Fixed(const Fixed& obj){
		std::cout << "Copy constructor called" << std::endl;
		*this = obj;
	}
	Fixed &operator=(const Fixed& obj)
	{
		std ::cout << "Copy assignment operator called" << std::endl;
		if (this != &obj){
			this->Integer = obj.getRawBits();
		}
		return (*this);
	}
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	~Fixed();
};
#endif 
