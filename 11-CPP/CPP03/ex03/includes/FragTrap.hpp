#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap 
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		void attack(const std::string& target);
		void highFivesGuys();
};

#endif