/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:14:01 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/09 03:06:17 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

/*
** Make a Weapon class, that has a type string, and a getType method that returns a
** const reference to this string. It also has a setType, of course!
*/

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string	&getType() const;
		void 				setType(std::string type);
	private:
		std::string _type;
};

#endif