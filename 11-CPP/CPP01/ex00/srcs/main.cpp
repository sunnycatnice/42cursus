/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/07 02:54:54 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main(void)
{
    std::cout << "Created first zombie in the code: Bobby" << std::endl;
    {
        Zombie bobby("Bobby");
        bobby.announce();
    }
    std::cout << "Created second zombie using the function newZombie: mde-gius" << std::endl;
    {
        Zombie *annamaria = newZombie("mde-gius");
        annamaria->announce();
    }
    {
        std::cout << "Created third zombie using the function randomChump: Ametta" << std::endl;
        randomChump("Ametta");
    }
}