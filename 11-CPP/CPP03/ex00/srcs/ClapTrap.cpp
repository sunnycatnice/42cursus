#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Default";
	std::cout << this->name << " constructor called" << std::endl;
	this->hitpoints = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = "Name";
	std::cout << this->name << " constructor called, init " << name << std::endl;
	this->name = name;
	this->hitpoints = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	this->damage++;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	//if it istantly kills
	if (this->energy <= amount)
	{
		std::cout << this->name << " is dead, 0 energy remaining";
		this->energy = 0;
	}
	else
	{
		this->energy -= amount;
		this->damage = amount;
		std::cout << "ClapTrap " << this->name << " take " << this->damage << " hp of damage." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int ammount)
{
	this->energy += ammount;
	//if it's dead, it revives
	if (this->energy == 0)
		std::cout << "ClapTrap " << this->name << " has been repaired by " << ammount << " hp and it's no longer dead.";
	else
		std::cout << "ClapTrap " << this->name <<  " has been repaired by " << ammount << " hp" << std::endl;
}