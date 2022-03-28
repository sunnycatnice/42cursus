/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:49:58 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/09 02:52:06 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr)
{
}

HumanB::~HumanB(void)
{
}

void    HumanB::attack(void)
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " is unarmed" << std::endl;
}

bool    HumanB::setWeapon(Weapon &weapon)
{
    if (weapon.getType() == "")
    {
        std::cout << "Weapon type is empty" << std::endl;
        return (false);
    }
    std::cout << "HumanB " << this->_name << " is now using a " << weapon.getType() << std::endl;
    this->_weapon = &weapon;
    return true;
}