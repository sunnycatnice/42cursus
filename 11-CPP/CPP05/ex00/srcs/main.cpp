/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:36 by ysoroko           #+#    #+#             */
/*   Updated: 2022/05/29 22:59:09 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "CONSTRUCTING WITH GRADE -49:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		Bureaucrat bill("Bill", -49);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "CONSTRUCTING WITH GRADE 256:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		Bureaucrat bill("Bill", 256);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "IN/DECREMENT + \"<<\" overload:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Bureaucrat bob("Bob", 1);
	try
	{
		bob.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}

	// "<<" operator overload used
	std::cout << bob << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}

	// "<<" operator overload used
	std::cout << bob;
	std::cout << std::endl << std::endl;
	//-------------------------------------------------------

	// Increment 1 exception
	std::cout << std::endl;
	std::cout << "INCREMENT GRADE 1:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;
	//-------------------------------------------------------

	// Decrement 150 exception
	std::cout << std::endl;
	std::cout << "DECREMENT GRADE 150:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	bob.setGrade(150);
	try
	{
		bob.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;

	//-------------------------------------------------------
	std::cout << std::endl;
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	return (0);
}