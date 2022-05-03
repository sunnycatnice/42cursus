#include "Animal.hpp"

/*
** ANIMAL CLASS
*/

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

/*
** CAT CLASS
*/

Cat::Cat()
{
	this->Animal::type = "Cat";
	std::cout << this->Animal::type << " constructor called"  << std::endl;
}

Cat::~Cat()
{
	std::cout << this->Animal::type << " Destructor called" << std::endl;
}

/*
** DOG CLASS
*/

Dog::Dog()
{
	this->Animal::type = "Dog";
	std::cout << this->Animal::type << " constructor called"  << std::endl;
}

Dog::~Dog()
{
	std::cout <<  this->Animal::type << " Destructor called" << std::endl;
}

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