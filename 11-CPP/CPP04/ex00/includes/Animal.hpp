#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal	&operator=( const Animal &other );
		Animal( const Animal &src );
		~Animal();
		std::string getType() const;
		void		makeSound() const;
};

class Dog : virtual public Animal
{
	public:
		Dog();
		~Dog();
		void makeSound();
		void getType();
};

class Cat : virtual public Animal
{
	public:
		Cat();
		~Cat();
		void makeSound();
		void getType();
};

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