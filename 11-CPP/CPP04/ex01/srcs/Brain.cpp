#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain & src)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	for (int i = 0; i < src.getSize(); i++)
		this->ideas[i] = src.getIdea(i);
}

Brain & Brain::operator=(const Brain & rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < rhs.getSize(); i++)
		this->ideas[i] = rhs.getIdea(i);
	return *this;
}

int Brain::getSize() const
{
	int i = 0;
	while (i < 100 && ideas[i] != "")
		i++;
	return i;
}

std::string Brain::getIdea(int i) const
{
	return this->ideas[i];
}

void Brain::setIdea(std::string idea, int i)
{
	this->ideas[i] = idea;
}

Brain::~Brain()
{
	std::cout << "Brain Deconstructor Called" << std::endl;
}

