/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:32:26 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/29 19:36:57 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "karen.hpp"

void	karen::complain( std::string level )
{
	int i;
	level == "DEBUG" ? i = 0 : level == "INFO" ? i = 1 : level == "WARNING" ? i = 2 : level == "ERROR" ? i = 3 : i = 4;

	//call every function inside a loop using pointers to member functions
	void (karen::*functions[4])(void) = {&karen::_debug, &karen::_info, &karen::_warning, &karen::_error};
	while(i < 4)
	{
		(this->*functions[i])();
		i++;
	}
}

void	karen::_debug( void )
{
	std::cout << "I love to get extra baconc for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}

void	karen::_info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n";
}

void	karen::_warning( void )
{
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n";	
}

void	karen::_error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}