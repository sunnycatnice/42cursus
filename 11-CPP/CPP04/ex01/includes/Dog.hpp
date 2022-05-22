#ifndef __DOG_HPP__
# define __DOG_HPP__
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
        private:
                Brain* brain;
        public:
                Dog();
                Dog(const Dog & src);
                virtual ~Dog();
                Dog & operator=(const Dog & rhs);
                virtual void makeSound() const;
		std::string getIdea(int i) const;
		void setIdea(std::string idea, int i) const;
		Brain & getBrain() const;
		int getSize() const;
};

#endif
