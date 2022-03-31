/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karenfilter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:14:01 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/31 19:14:39 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KARENFILTER_HPP
#define KARENFILTER_HPP

# include <iostream>

class karenfilter
{
	public:
		void complain( std::string level );
		int	 getlevelnumber( std::string level );

	private:
		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );
		void _exeption( void );
};

#endif
