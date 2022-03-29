/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedforcpp.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:14:01 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/29 15:43:19 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPPSED_HPP
#define CPPSED_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>

class sedforcpp
{
	public:
		sedforcpp();
		~sedforcpp();
		void			init_string(std::string av1, std::string av2, std::string av3);
		int				verify_argv();
		int				create_new_file();
		void			test();
		std::string 	get_filename();
		std::string 	read_the_file(std::string filename);
		int				replace_string();
		int				check_file_isempty();

	private:
		std::string		_filename;
		std::string		_tofind;
		std::string		_toreplace;
};

#endif
