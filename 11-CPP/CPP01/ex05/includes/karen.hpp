/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:14:01 by dmangola          #+#    #+#             */
/*   Updated: 2022/03/29 18:33:26 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

# include <iostream>

class karen
{
	public:
		void complain( std::string level );

	private:
		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );
};

#endif
