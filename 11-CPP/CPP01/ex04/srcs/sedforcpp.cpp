/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedforcpp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:35:58 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/25 18:09:42 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cppsed.hpp"

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

bool sedforcpp::word_replace(std::string& str, const std::string& from, const std::string& to)
{
	int	j = 0;
	int	tocpy_len = 0;

	tocpy_len = to.length();
	
	for(std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (str[i] == from[j])
		{
			str[i] = from[j];
			if (from[i] == '\0')
				break ;
			i++;
		}
	}	
}

std::string	sedforcpp::replace_string()
{
	std::ifstream	file(this->_filename);
	std::ofstream	newfile(this->_filename + ".replace");
	std::string		line;
	std::string		newline;
	std::string		newstr;

	while (std::getline(file, line))
	{
		newstr = line;
		newline = line;
		std::cout << "line   : " << line << std::endl;
		std::cout << "line   : " << newstr << std::endl;
		std::cout << "newline: " << newline << std::endl;
		word_replace(newline, this->_tofind, this->_toreplace);
		std::cout << "newline: " << newline << std::endl << std::endl;
		if (newline != newstr)
			newfile << newline << std::endl;
		else
			newfile << line << std::endl;
	}
	file.close();
	newfile.close();
	return (newstr);
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

void	sedforcpp::test()
{
    std::string sFilename = this->_filename;    

    /******************************************
     *                                        *
     *                WRITING                 *
     *                                        *
     ******************************************/

    std::ofstream fileSink(sFilename); // Creates an output file stream

    if (!fileSink) {
        std::cerr << "Canot open " << sFilename << std::endl;
        exit(-1);
    }

    /* std::endl will automatically append the correct EOL */
    fileSink << "Hello Open Source World!" << std::endl;


    /******************************************
     *                                        *
     *                READING                 *
     *                                        *
     ******************************************/
   
    std::ifstream fileSource(sFilename); // Creates an input file stream

    if (!fileSource) {
        std::cerr << "Canot open " << sFilename << std::endl;
        exit(-1);
    }
    else {
        // Intermediate buffer
        std::string buffer;

        // By default, the >> operator reads word by workd (till whitespace)
        while (fileSource >> buffer)
        {
            std::cout << buffer << std::endl;
        }
    }
}
