/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed3.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:45:31 by dmangola          #+#    #+#             */
/*   Updated: 2022/04/13 10:09:22 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed3.hpp"

/*
**	CANONYCAL FORM /////////////////////////////////////
*/
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
	std::cout << "Assignment operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->_fixed_point_value = op.getRawBits();
	return (*this);
}

/*
**	OTHERS FIXED CONSTRUCTORS ///////////////////////////
*/

Fixed::Fixed(const int int_to_conv)
{
	std::cout << "Int constructor called" << std::endl;
	std::cout << typeid(this->_fixed_point_value).name();
	this->_fixed_point_value = int_to_conv << this->_number_of_fractional_bits;
}

Fixed::Fixed(const float float_to_conv)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = (int) (roundf(float_to_conv * (1 << this->_number_of_fractional_bits)));
}

/*
**	GETTING - SETTER /////////////////////////////////////
*/

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_value = raw;
}

int	Fixed::to_int(void) const
{
	return ((int) (this->_fixed_point_value >> this->_number_of_fractional_bits));
}

float	Fixed::to_float(void) const
{
	return ((float) (this->_fixed_point_value / (float)(1 << this->_number_of_fractional_bits)));
}

/*
**	OPERATORS /////////////////////////////////////////
*/

bool	Fixed::operator>(const Fixed &rhs) const
{
	return(this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (!(*this < rhs));
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return(rhs > *this);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (!(*this > rhs));
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (rhs.getRawBits() == this->getRawBits());
}

bool	Fixed::operator!=(const	Fixed &rhs) const
{
	return(!(rhs == *this));
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + rhs.getRawBits());
	return(res);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() - rhs.getRawBits());
	return(res);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed res(this->to_float() * rhs.to_float());

	return(res);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	res(this->to_float() / rhs.to_float());

	return (res);
}

Fixed	Fixed::operator++(void)
{
	this->_fixed_point_value++;

	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	++(*this);
	return(old);
}

Fixed	Fixed::operator--(void)
{
	this->_fixed_point_value--;

	return(*this);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

/*
**	OVERLOADED MEMBER FUNCTIONS ////////////////////////
*/

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
    out << fixe.to_float();
    return (out);
}
