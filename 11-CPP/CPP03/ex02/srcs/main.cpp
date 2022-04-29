#include "FragTrap.hpp"

int main()
{
	FragTrap anna("anna");
	FragTrap maria("maria");

	anna.attack("maria");
	anna.takeDamage(1);
	maria.beRepaired(1);
	anna.highFivesGuys();
}