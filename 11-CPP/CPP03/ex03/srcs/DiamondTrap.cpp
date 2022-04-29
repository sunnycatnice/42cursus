#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->hitpoints = 100;
	this->energy = 100;
	this->damage = 30;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "Name DiamondTrap constructor called, init " << name << std::endl;
	this->name = name;
	this->hitpoints = 100;
	this->energy = 100;
	this->damage = 30;
}

void DiamondTrap::attack(const std::string& target)
{
	this->damage++;
	std::cout << "DiamondTrap " << this->name << " attacks " << target << " causing " << this->damage << " points of damage!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap called" << std::endl;
}

void DiamondTrap::highFivesGuys()
{
	if (this->energy)
		std::cout << "DiamondTrap " << this->name << " asks for a positive high-five" << std::endl;
	else
		std::cout << "DiamondTrap " << this->name << " can't ask for a positive high five because he's dead";	
}