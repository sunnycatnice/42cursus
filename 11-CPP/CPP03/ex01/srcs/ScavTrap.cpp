#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->hitpoints = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Name ScavTrap constructor called, init " << name << std::endl;
	this->name = name;
	this->hitpoints = 100;
	this->energy = 50;
	this->damage = 20;
}

void ScavTrap::attack(const std::string& target)
{
	this->damage++;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->damage << " points of damage!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}