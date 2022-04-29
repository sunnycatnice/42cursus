#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->hitpoints = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Name FragTrap constructor called, init " << name << std::endl;
	this->name = name;
	this->hitpoints = 100;
	this->energy = 100;
	this->damage = 30;
}

void FragTrap::attack(const std::string& target)
{
	this->damage++;
	std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->damage << " points of damage!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (this->energy)
		std::cout << "FragTrap " << this->name << " asks for a positive high-five" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " can't ask for a positive high five because he's dead";	
}