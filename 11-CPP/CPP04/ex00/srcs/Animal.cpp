#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << this->type << " constructor called" << std::endl;
}

Animal &	Animal::operator=( Animal const & rhs )
{
	std::cout << "Assignement operator for Animal called" << std::endl;
	this->type = rhs.getType();
	return *this;
}

Animal::Animal( Animal const & src )
{
	std::cout << "Copy constructor for Animal called" << std::endl;
	*this = src;
	return;
}

Animal::~Animal()
{
	std::cout << this->type << " destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << this->type << " sound" << std::endl;
}