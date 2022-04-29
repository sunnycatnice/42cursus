#include "ScavTrap.hpp"

int main()
{
	ScavTrap anna("anna");
	ScavTrap maria("maria");

	anna.attack("maria");
	anna.takeDamage(1);
	maria.beRepaired(1);
	anna.guardGate();
}