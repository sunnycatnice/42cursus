/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:50:47 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/09 03:15:21 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

//create a class, HumanA , that have a Weapon, a name, and an attack() function that displays:
//NAME attacks with his WEAPON_TYPE
//this class takes the weapon in its constructor
//HumanA will ALWAYS be armed

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void    attack();
    private:
        std::string _name;
        Weapon      &_weapon;
};




#endif