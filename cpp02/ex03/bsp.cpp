#include "Point.hpp"

static Fixed Area(Point const &a, Point const &b, Point const &c)
{
	Fixed area =
		a.getX() * (b.getY() - c.getY()) +
		b.getX() * (c.getY() - a.getY()) +
		c.getX() * (a.getY() - b.getY());

	if (area < Fixed(0))
		area = area * Fixed(-1);

	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = Area(a, b, c);
    Fixed areaPAB = Area(point, a, b);
    Fixed areaPBC = Area(point, b, c);
    Fixed areaPCA = Area(point, c, a);
    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
        return false;
    return (areaABC == areaPAB + areaPBC + areaPCA);
}
