/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:21:17 by dmangola          #+#    #+#             */
/*   Updated: 2022/04/16 13:48:57 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed3.hpp"
#define ABS(n) ((n > 0) ? n : -n)

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		//constructors
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);
		Point &operator=(const Point &cpy);
		~Point();
		//methods
		bool			bsp(Point pt, Point v1, Point v2, Point v3);
		Fixed const 	getX(void) const;
		Fixed const		getY(void) const;
		
};

#endif