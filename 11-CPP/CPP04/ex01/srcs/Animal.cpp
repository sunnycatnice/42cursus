#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Constructor called" << std::endl;
	this->Type = "none";
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal Copy Constructor operator" << std::endl;
	Animal::operator=(src);
}

Animal & Animal::operator=(Animal const & rhs)
{
	if (this == &rhs)
		return *this;
	this->Type = rhs.getType();
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Deconstructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Undefined Sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->Type;
}
