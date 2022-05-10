#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(const Dog &src);
        ~Dog(void);

        // virtual Dog		&operator=(Dog const & rhs);
        // virtual Animal	&operator=(const Animal &other);
        virtual void	makeSound(void) const;
};

#endif