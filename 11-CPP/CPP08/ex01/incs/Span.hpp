#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{

public:

	Span( void );
	Span( unsigned int storedSize );
	Span( const Span &src );
	~Span( void );

	Span	&operator=( const Span &rhs );

	void			addNumber( int number );
	void			randomFill( void );
	void			addByIteratorRange( std::vector<int>::iterator begin,
			std::vector<int>::iterator end);
	int				shortestSpan( void ) const;
	int				longestSpan( void ) const;
	unsigned int	size( void ) const;
	unsigned int	maxSize( void ) const;
	unsigned int	spaceLeft( void ) const;

	static bool	verbose;

private:

	unsigned int		_storedSize;
	std::vector<int>	_storage;

};

std::ostream	&operator<<( std::ostream &ostr, const Span &instance );

#endif
