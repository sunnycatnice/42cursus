/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/29 17:17:11 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sedforcpp.hpp"
#include <iostream>

int main (int argc, char **argv)
{
	sedforcpp	sed;

	if (argc != 4)
	{
		std::cout << "Usage: ./sedforlosers <filename.txt> <str_tofind> <str_toreplace>" << std::endl;
		return (0);
	}
	sed.init_string(argv[1], argv[2], argv[3]);
	if (sed.verify_argv())
		return (1);
	else if (sed.check_file_isempty())
	{
		std::cout << "Error: file " << sed.get_filename() << " is empty" << std::endl;
		return (1);
	}
	else if (sed.create_new_file())
	{
		std::cout << "Error: cannot create new file" << std::endl;
		return (1);
	}
	else
	{
		sed.replace_string();
		std::cout << "Success: file " << sed.get_filename() << " has been replaced" << std::endl;
		return (0);
	}
}
