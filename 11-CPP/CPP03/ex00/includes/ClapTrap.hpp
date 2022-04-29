#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string name;
		int hitpoints;
		unsigned int energy;
		int damage;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &cpy);
		ClapTrap(std::string name);
		ClapTrap &operator = (const ClapTrap &op);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif