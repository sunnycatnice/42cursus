#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Constructor called" << std::endl;
	brain = new Brain();
	this->Type = "Cat";
}

Brain & Cat::getBrain() const
{
	return (*this->brain);
}

Cat::Cat(const Cat & src)
{
	std::cout << "Cat Copy Constructor operator" << std::endl;
	this->Type = src.getType();
	this->brain = new Brain(src.getBrain());
}

Cat & Cat::operator=(const Cat & rhs)
{
	if (this == &rhs)
		return *this;
	delete (this->brain);
	this->brain = new Brain(rhs.getBrain());
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Deconstructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Miao" << std::endl;
}

std::string Cat::getIdea(int i) const
{
	return this->brain->getIdea(i);
}

void Cat::setIdea(std::string idea, int i) const
{
	this->brain->setIdea(idea, i);
}

int Cat::getSize() const
{
	return this->brain->getSize();	
}
