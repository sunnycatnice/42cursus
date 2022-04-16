/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:20:09 by dmangola          #+#    #+#             */
/*   Updated: 2022/04/16 13:48:52 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point& copy): _x(copy._x), _y(copy._y)
{
}

Point::~Point(void)
{
}

Point& Point::operator=(const Point& rhs)
{
	(void)rhs;
	std::cout << "Assignment of const variables impossible, values will stay the same as in the default constructor." << std::endl;
	return *this;
}

Fixed const Point::getX(void) const
{
	return this->_x;
}

Fixed const Point::getY(void) const
{
	return this->_y;
}

//Is the point s to the left of or to the right of both the lines AB and AC? If true, it can't be inside.
//If false, it is at least inside the "cones" that satisfy the condition. 
bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
    float as_x = point._x.to_float()-a._x.to_float();
    float as_y = point._y.to_float()-a._y.to_float();

    bool s_ab = (b._x-a._x)*as_y-(b._y-a._y)*as_x >= 0;

    if((c._x-a._x)*as_y-(c._y-a._y)*as_x > 0 == s_ab)
		return false;

    if((c._x-b._x)*(point._y-b._y)-(c._y-b._y)*(point._x-b._x) > 0 != s_ab)
		return false;

    return true;
}