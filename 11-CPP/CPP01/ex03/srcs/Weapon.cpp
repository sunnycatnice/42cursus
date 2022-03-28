/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:48:13 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/09 02:48:48 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon(void)
{
}

Weapon::Weapon(std::string type) : _type(type)
{
}

//gettype method that returns a const reference to the type of the weapon
const std::string& Weapon::getType(void) const
{
    return this->_type;
}

//setType method to set the type of a weapon calling this function
void Weapon::setType(std::string type)
{
    this->_type = type;
}
