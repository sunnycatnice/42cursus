#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define NUM 5

int main()
{
	{
		Animal* arca[NUM];

		for(int i = 0; i < NUM/2; i++)
			arca[i] = new Dog();

		for(int i = NUM/2; i < NUM; i++)
			arca[i] = new Cat();

		for(int i = 0; i < NUM; i++)
			delete arca[i];
	}
	{
		Cat kitty1;
		Cat kitty2;

		kitty1.setIdea("I'm the first idea", 0);
		kitty1.setIdea("And i'm the second one", 1);
		kitty1.setIdea("third here", 2);
		kitty1.setIdea("Why third is not capitalised", 3);
		kitty1.setIdea("SHUT UP FUCKING MIND", 4);

		// Dog kitty2(kitty1);
		kitty2 = kitty1;
		std::cout << "Check on the Cat copy deep" << std::endl;
		std::cout << "first  cat address: " << &kitty1 << " -- second cat address: " << &kitty2 << std::endl;
		std::cout << "first  cat brain address: " << &(kitty1.getBrain());
		std::cout << " -- second cat brain address: " << &(kitty2.getBrain()) << std::endl;
		for (int i = 0; i < kitty1.getSize(); i++)
			std::cout << "first  cat idea " << i << ": " << kitty1.getIdea(i) << std::endl;
		for (int i = 0; i < kitty2.getSize(); i++)
			std::cout << "second cat idea " << i << ": " << kitty2.getIdea(i) << std::endl;
	}
	return 0;
}
