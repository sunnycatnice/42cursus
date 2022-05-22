#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__
# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain & src);
		virtual ~Brain();
		Brain & operator=(const Brain & rhs);

		int getSize() const;
		std::string getIdea(int i) const;
		void setIdea(std::string idea, int i);
	private:
		std::string ideas[100];
};

#endif 
