/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/08 23:13:41 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	ZombieNumber = 5;

	std::cout << "Creating a zombie horde of little Bobby's" << std::endl; 
	{
		Zombie *zombies = zombieHorde(ZombieNumber, "Bobby");
		for (size_t i = 0; i < (size_t)ZombieNumber; i++)
		{
			zombies[i].announce();
		}
		delete [] zombies;
	}

}