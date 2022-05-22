#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Constructor called" << std::endl;
	this->Type = "Cat";
}

Cat::Cat(const Cat & src)
{
	std::cout << "Cat Copy Constructor operator" << std::endl;
	Animal::operator=(src);
	Cat::operator=(src);
}

Cat & Cat::operator=(const Cat & rhs)
{
	if (this == &rhs)
		return *this;
	this->Type = rhs.getType();
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Deconstructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miao" << std::endl;
}
