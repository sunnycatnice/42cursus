/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:20:09 by dmangola          #+#    #+#             */
/*   Updated: 2022/04/16 13:35:05 by dmangola         ###   ########.fr       */
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

float Point::sign(Point p1, Point p2, Point p3)
{
	float p1x;
	float p2x;
	float p3x;
	float p1y;
	float p2y;
	float p3y;

	p1x = p1._x.to_float();
	p2x = p2._x.to_float();
	p3x = p3._x.to_float();
	p1y = p1._y.to_float();
	p2y = p2._y.to_float();
	p3y = p3._x.to_float();

    return (p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y);
}

//d stands for diagonal
//it checks in the most efficient way possible if the point is inside or outside the 3 diagonals
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