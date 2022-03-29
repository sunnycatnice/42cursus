/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedforcpp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:35:58 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/29 17:01:04 by dmangola         ###   ########.fr       */
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
	this->_toreplace = av2;
	this->_tofind = av3;
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

std::string sedforcpp::read_the_file(std::string filename)
{
  std::stringstream buffer;

  buffer << std::ifstream(filename).rdbuf();

  return buffer.str();
}

int sedforcpp::replace_string()
{
	std::ofstream newfile;
	newfile.open(this->_filename + ".replace");

	std::ifstream file(this->_filename);
	int i = 0;
	int j = 0;

	std::string file_contents = this->read_the_file(this->_filename);

	if (file.is_open())
	{
		// std::cout << "line2: "<<line2 << std::endl;
		while(file_contents[i])
		{
			if(file_contents.substr(i, this->_toreplace.length()) == this->_toreplace)
			{
				std::cout << "\n--------------------------\n";
				std::cout << "!!! Parte da: " << i << std::endl;
				j = -1;
				while(this->_tofind[++j])
				{
					i++;
					newfile << this->_tofind[j];
					std::cout << this->_tofind[j];
				}
				if (file_contents[i] == ' ')
				{
					std::cout << file_contents[i - 1];
					newfile << " " << i;
				}
				std::cout << std::endl << "!!!Finisce qua: " << i << std::endl;
				std::cout << "TOT: " << j << std::endl;
				std::cout << "--------------------------\n";
			}
			else
			{
				std::cout << file_contents[i];
				newfile << file_contents[i];
				i++;
			}
		}
		file.close();
		newfile.close();
		return (0);
	}
	else
		return (1);
}