#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

/*
** 	"Wrong" part
*/

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		std::string getType() const;
		void		makeSound() const;
};

class WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		void makeSound();
		void getType();
};

#endif