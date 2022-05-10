#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	std::cout << "Default constructor for Dog called" << std::endl;
	return;
}
Dog::Dog( Dog const & src )
{
	std::cout << "Copy constructor for Dog called" << std::endl;
	*this = src;
	return;
}
Dog::~Dog( void )
{
	std::cout << "Destructor for Dog called" << std::endl;
	return;
}
void	Dog::makeSound( void ) const
{
	std::cout << "Wouf!" << std::endl;
}
