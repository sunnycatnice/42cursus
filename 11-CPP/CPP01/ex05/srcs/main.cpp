/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/29 19:35:07 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "karen.hpp"

int main ()
{
	karen	k;

	std::cout << "--- TEST 1 ---" << std::endl;
	std::cout << "level = CIAO" << std::endl;
	k.complain("CIAO");
	std::cout << std::endl << std::endl;

	std::cout << "--- TEST 2 ---" << std::endl;
	std::cout << "level = DEBUG" << std::endl;
	k.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "--- TEST 3 ---" << std::endl;
	std::cout << "level = INFO" << std::endl;
	k.complain("INFO");
	std::cout << std::endl;

	std::cout << "--- TEST 4 ---" << std::endl;
	std::cout << "level = WARNING" << std::endl;
	k.complain("WARNING");
	std::cout << std::endl;

	std::cout << "--- TEST 5 ---" << std::endl;
	std::cout << "level = ERROR" << std::endl;
	k.complain("ERROR");
	std::cout << std::endl;

}
