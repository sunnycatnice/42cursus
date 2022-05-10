#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(const Cat &src);
        ~Cat(void);

        // virtual Cat				&operator=(Cat const & rhs);
        // virtual Animal	&operator=(const Animal &othes);
        virtual void	makeSound(void) const;
};


#endif