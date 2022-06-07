#include "B.hpp"

B::B( void )
{
	if (Base::verbose)
		std::cout << "Default constructor for B called" << std::endl;
	return;
}

B::B( B const & src )
{
	if (Base::verbose)
		std::cout << "Copy constructor for B called" << std::endl;
	*this = src;
	return;
}

B::~B( void )
{
	return;
}

B &	B::operator=( B const & rhs )
{
	(void)rhs;
	if (Base::verbose)
		std::cout << "Bssignement operator for B called" << std::endl;
	return *this;
}

std::ostream &	operator<<( std::ostream & ostr, B const & instance)
{
	(void)instance;
	ostr << "No value for B" << std::endl;
	return ostr;
}
