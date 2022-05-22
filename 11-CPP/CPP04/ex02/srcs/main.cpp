#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " say ";
		j->makeSound();

		std::cout << i->getType() << " say ";
		i->makeSound();

		delete j;
		delete i;
	}
	return 0;
}
