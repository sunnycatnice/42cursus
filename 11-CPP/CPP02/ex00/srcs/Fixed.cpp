/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:45:31 by dmangola          #+#    #+#             */
/*   Updated: 2022/04/04 18:40:11 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point_value = cpy.getRawBits();
}

Fixed & Fixed::operator = (const Fixed &op)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->_fixed_point_value = op.getRawBits();
	return (*this);
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

int		Fixed::setRawBits(int const raw)
{
	this->_fixed_point_value = raw;
	return 0;
}