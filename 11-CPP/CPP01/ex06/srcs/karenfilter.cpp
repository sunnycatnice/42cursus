/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karenfilter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:32:26 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/31 19:19:07 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "karenfilter.hpp"

int		karenfilter::getlevelnumber(std::string level)
{
	std::string complaintLevels[4] = {
		"error",
		"warning",
		"info",
		"debug"
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == complaintLevels[i])
			return (i);
	}
	return (-1);
}

void	karenfilter::complain( std::string level )
{
	int i = this->getlevelnumber(level);

	void	(karenfilter::*complaint[])( void ) =
	{
		&karenfilter::_error,
		&karenfilter::_warning,
		&karenfilter::_info,
		&karenfilter::_debug,
		&karenfilter::_exeption
	};
	if (i == -1)
		(this->*complaint[4])();
	else
	{
		while(i >= 0)
		{
			(this->*complaint[i])();
			std::cout << std::endl;
			i--;
		}
	}
}

void	karenfilter::_debug( void )
{
	std::cout << "[ DEBUG ] " << std::endl;
	std::cout << "I love to get extra baconc for my 7XL-double-cheese-triple"
	"-pickle-special-ketchup burger. I just love it!\n";
}

void	karenfilter::_info( void )
{
	std::cout << "[ INFO ] " << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don"
	"’t put enough! If you did I would not have to ask for it!\n";
}

void	karenfilter::_warning( void )
{
	std::cout << "[ WARNING ] " << std::endl;
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve "
	"been coming here for years and you just started working here last month.\n";	
}

void	karenfilter::_error( void )
{
	std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

void	karenfilter::_exeption( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]";
}