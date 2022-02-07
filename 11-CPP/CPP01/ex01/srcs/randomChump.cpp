/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:20 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/07 02:54:15 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

void randomChump(std::string name)
{
	Zombie randomChump = Zombie(name);

	randomChump.announce();
}
