/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedforcpp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:35:58 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/29 17:42:18 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sedforcpp.hpp"

//init constructor and destructor
sedforcpp::sedforcpp()
{
}

sedforcpp::~sedforcpp()
{
}

std::string sedforcpp::get_filename()
{
	return (_filename);
}

void	sedforcpp::init_string(std::string av1, std::string av2, std::string av3)
{
	this->_filename = av1;
	this->_tofind = av2;
	this->_toreplace= av3;
}

//'this' may only be used inside a nonstatic member function
//it means that you are not inside a class.
int	sedforcpp::verify_argv()
{
	if (this->_filename.empty() == 1 || this->_toreplace.empty() == 1 || this->_tofind.empty() == 1)
	{
		std::cout << "Usage: ./replace <filename.txt> <str_tofind> <str_toreplace>" << std::endl;
		std::cout << "Missing argoument." << std::endl;
		return (1);
	}
	std::ifstream	file(this->_filename);
	//test if file exist
	if (!file.is_open())
	{
		std::cout << "Error: file " << this->_filename << " does not exist" << std::endl;
		return (1);
	}
	return (0);
}

int	sedforcpp::create_new_file()
{
	std::ofstream	file(this->_filename + ".replace");
	if(file.is_open())
	{
		file.close();
		return (0);
	}
	else
		return (1);
}

int	sedforcpp::check_file_isempty()
{
	std::ifstream	file(this->_filename);
	std::string		line;
	std::string		line2;

	if (file.is_open())
	{
		std::getline(file, line);
		if (line.empty())
			return (1);
		else
			return (0);
	}
	else
		return (1);
}


int sedforcpp::replace_string()
{
	std::string outfile = this->_filename;
	outfile += ".replace";
	
	std::ifstream file(this->_filename, std::ifstream::in);
	std::ofstream newfile(outfile, std::ofstream::out);

	std::size_t n = 0;
	std::string str;

	std::getline(file, str, '\0');

	file.close();
	while((n = str.find(this->_tofind)) != std::string::npos)
	{
		str.erase(n, this->_tofind.size());
		str.insert(n, this->_toreplace);
	}
	newfile << str;
	return 0;
}