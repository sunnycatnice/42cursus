/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:26:54 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/19 01:05:31 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    //print_ascii_art();
	PhoneBook pb;
	int i = 0;
	bool over = false;
	
	while (true)
	{
		std::cout << "> ";
		std::string command;
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
		{
			pb.user[i++] = pb.add();
			std::cout << "\nYou successfully added contact number " << i << "!\n" << std::endl;
			if (i >= 8)
			{
				over = true;
				i = i % 8;
			}
		}
		else if (!command.compare("SEARCH"))
		{
			// std::cout << "SEARCH" << std::endl;
			// std::cout << pb.user[0].getName() << std::endl;
			if (over == true)
				pb.search(8);
			else
				pb.search(i);
		}
		else if (!command.compare("EXIT") || std::cin.eof())
			break ;
		else
			std::cout << "Unknown command" << std::endl;
	}
}