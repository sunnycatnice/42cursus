#include "WrongAnimal.hpp"

/*
** WRONGANIMAL CLASS
*/

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << this->type << " destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << this->type << " sound" << std::endl;
}

/*
** WRONGCAT CLASS
*/

WrongCat::WrongCat()
{
	this->WrongCat::type = "WrongCat";
	std::cout << this->WrongCat::type << " constructor called"  << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->WrongCat::type << " Destructor called" << std::endl;
}