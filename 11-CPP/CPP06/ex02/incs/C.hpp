#ifndef C_HPP
# define C_HPP

# include <iostream>
# include "Base.hpp"

class C: public Base
{

public:

	C( void );
	C( const C &src );
	~C( void );

	C	&operator=( const C &rhs );

private:

};

std::ostream	&operator<<( std::ostream &ostr, const C &instance );

#endif
