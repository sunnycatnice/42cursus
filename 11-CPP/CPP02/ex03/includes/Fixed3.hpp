/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:14:01 by dmangola          #+#    #+#             */
/*   Updated: 2022/04/02 22:44:13 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED3_HPP
#define FIXED3_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixed_point_value;
		static const int	_number_of_fractional_bits = 8;

	public:
		Fixed(); //default constructor
		Fixed(const Fixed &cpy); //copy constructor
		Fixed(const int int_to_conv);
		Fixed(const float float_to_conv);
		Fixed	&operator = (const Fixed &op); //assignment operator 
		virtual ~Fixed();
		
		bool		operator<(const Fixed &rhs) const;
		bool		operator<=(const Fixed &rhs) const;
		bool		operator>(const Fixed &rhs) const;
		bool		operator>=(const Fixed &rhs) const;
		bool		operator==(const Fixed &rhs) const;
		bool		operator!=(const Fixed &rhs) const;
		Fixed		operator+(const Fixed &rhs) const;
		Fixed		operator-(const Fixed &rhs) const;
		Fixed		operator*(const Fixed &rhs) const;
		Fixed		operator/(const Fixed &rhs) const;
		Fixed		operator++(void);
		Fixed		operator++(int);
		Fixed		operator--(void);
		Fixed		&max(Fixed &lhs, Fixed &rhs);
		const Fixed	&max(const Fixed &lhs, const Fixed &rhs);
		Fixed		&min(Fixed &lhs, Fixed &rhs);
		const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		int			to_int(void) const;
		float		to_float(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixe);

#endif