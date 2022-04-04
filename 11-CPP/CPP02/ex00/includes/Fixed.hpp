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

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					_fixed_point_value;
		static const int	_number_of_fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &cpy);
		Fixed & operator = (const Fixed &op);
		~Fixed();

		int		getRawBits(void) const;
		int		setRawBits(int const raw);
};

#endif