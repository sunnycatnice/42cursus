/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:27 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/07 02:55:36 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie (std::string name): name(name)
{
}

Zombie::~Zombie(void)
{
    Zombie::prefix();
    std::cout << " " << Zombie::name << " died" << std::endl;
}

void    Zombie::announce(void) const
{
    Zombie::prefix();
    std::cout << " BraaaaaiiiiiiiiinnnnnzzzzZ......." << std::endl;
}

void    Zombie::prefix(void) const
{
    std::cout << "<" << this->name << ">";
}

std::string Zombie::getName(void) const
{
    return (this->name);
}
