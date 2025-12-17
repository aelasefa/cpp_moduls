#include "Point.hpp"

Point::Point():x(0),y(0)
{
	if (DEBUG_MESSAGES)
		std::cout << "Point: Default constructor called" << std::endl;
}

Point::Point(float xValue, float yValue): x(xValue), y(yValue)
{
	if (DEBUG_MESSAGES)
		std::cout << "Point: float constructor called" << std::endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
    if (DEBUG_MESSAGES)
        std::cout << "Point: Copy constructor called" << std::endl;
}

Point::~Point()
{
	if (DEBUG_MESSAGES)
		std::cout << "Point: Destructor constructor called" << std::endl;
}

Point& Point::operator=(const Point& other)
{
	if (DEBUG_MESSAGES)
		std::cout << "Point : Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}
