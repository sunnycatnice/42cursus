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

#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__
#include <iostream>
#include <string>
#include "Weapon.hpp"

//this class has a weapon, a name and an attach function
class HumanA
{
    public:
        ~HumanA();
        HumanA(std::string name, Weapon &weapon);
        void attack();
    private:
        std::string _name;
        Weapon &_weapon;
};


#endif
