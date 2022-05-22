#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__
# include <iostream>

class Animal
{
        protected:
                std::string Type;
        public:
                Animal();
                Animal(Animal const & src);
                virtual ~Animal();
                Animal & operator=(Animal const & rhs);
		std::string getType() const;
                virtual void makeSound() const;
};

#endif
