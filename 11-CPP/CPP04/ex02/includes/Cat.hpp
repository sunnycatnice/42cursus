#ifndef __CAT_HPP__
# define __CAT_HPP__
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
        public:
                Cat();
                Cat(const Cat & src);
                virtual ~Cat();
                Cat & operator=(const Cat & rhs);
                virtual void makeSound() const;
};

#endif
