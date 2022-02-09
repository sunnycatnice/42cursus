/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:14:01 by dmangola          #+#    #+#             */
/*   Updated: 2022/02/08 22:54:42 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		std::string		getName(void) const;
		bool			setName(std::string newName);
		void			announce(void) const;

	private:
		std::string name;
		void            prefix(void) const;
};

Zombie					*newZombie(std::string name);
void					randomChump(std::string name);
Zombie					*zombieHorde( int N, std::string name );

#endif