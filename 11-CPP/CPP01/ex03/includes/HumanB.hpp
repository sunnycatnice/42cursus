/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:50:44 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/09 03:15:34 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

//create a class, HumanB , that have a Weapon, a name, and an attack() function that displays:
//NAME attacks with his WEAPON_TYPE
//this class DOES NOT TAKE the weapon in its constructor
//• HumanB may not always have a Weapon, but HumanA will ALWAYS be armed.

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();
        void    attack();
    private:
        std::string _name;
};

#endif