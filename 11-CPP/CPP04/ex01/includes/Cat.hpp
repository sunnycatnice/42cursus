#ifndef __CAT_HPP__
# define __CAT_HPP__
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
        private:
                Brain* brain;
        public:
                Cat();
                Cat(const Cat & src);
                virtual ~Cat();
                Cat & operator=(const Cat & rhs);
                virtual void makeSound() const;
		std::string getIdea(int i) const;
		void setIdea(std::string idea, int i) const;
		Brain & getBrain() const;
		int getSize() const;
};

#endif
