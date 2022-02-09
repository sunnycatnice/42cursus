/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/09 01:21:36 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "str using strPTR: " << &(*strPTR) << std::endl;
	std::cout << "str using strREF: " << &strREF << std::endl << std::endl;

	std::cout << "str: " << str << std::endl;
	std::cout << "strPTR value: " << strPTR << std::endl;
	std::cout << "strREF value: " << strREF << std::endl;
}