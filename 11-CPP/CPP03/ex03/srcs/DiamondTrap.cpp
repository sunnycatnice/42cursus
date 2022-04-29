#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->hitpoints = 100;
	this->energy = 100;
	this->damage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name") , FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	std::cout << "Name DiamondTrap constructor called, init " << name << std::endl;
	this->name = name;
	this->hitpoints = this->FragTrap::hitpoints;
	this->energy = this->FragTrap::energy;
	this->damage = this->FragTrap::damage;
}

void DiamondTrap::attack(const std::string& target)
{
	this->damage++;
	std::cout << "DiamondTrap " << this->name << " attacks " << target << " causing " << this->damage << " points of damage!" << std::endl;
}
