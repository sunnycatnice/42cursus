/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/07 03:05:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main(void)
{
    std::cout << "Creating a zombie horde of little Bobby's" << std::endl; 
    {
        Zombie *firstZombieHorde = zombieHorde(5, "Bobby");
        
    }

}