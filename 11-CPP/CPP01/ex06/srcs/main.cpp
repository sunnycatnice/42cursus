/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/31 19:20:57 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "karenfilter.hpp"

int main (int ac, char **av)
{
	karenfilter	k;

	if (ac == 2)
		k.complain(av[1]);
	else
	{
		std::cout << "Usage ./karenFilter complain" << std::endl;
		std::cout << "Karen complains: INVALID ARGV :/";
	}
}
