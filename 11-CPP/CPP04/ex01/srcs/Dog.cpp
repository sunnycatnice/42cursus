#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Constructor called" << std::endl;
	this->Type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog & src)
{
	std::cout << "Dog Constructor operator" << std::endl;
	Animal::operator=(src);
	Dog::operator=(src);
}

Dog & Dog::operator=(const Dog & rhs)
{
	if (this == &rhs)
		return *this;
	this->brain = new Brain(rhs.getBrain());
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Deconstructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woff-Woff" << std::endl;
}

std::string Dog::getIdea(int i) const
{
	return this->brain->getIdea(i);
}

void Dog::setIdea(std::string idea, int i) const
{
	this->brain->setIdea(idea, i);
}

int Dog::getSize() const
{
	return this->brain->getSize();	
}

Brain & Dog::getBrain() const
{
	return *this->brain;
}
