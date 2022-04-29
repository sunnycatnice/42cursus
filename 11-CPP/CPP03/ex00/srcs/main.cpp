#include "ClapTrap.hpp"

int main()
{
	ClapTrap anna("anna");
	ClapTrap maria("maria");

	anna.attack("maria");
	anna.takeDamage(1);
	maria.beRepaired(1);
}