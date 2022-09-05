#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > // generic template
	class vector
	{
		public:
		    typedef T                                        value_type;
			typedef Allocator                                allocator_type;
			typedef typename allocator_type::reference       reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef implementation-defined                   iterator;
			typedef implementation-defined                   const_iterator;
			typedef typename allocator_type::size_type       size_type;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::pointer         pointer;
			typedef typename allocator_type::const_pointer   const_pointer;
			typedef std::reverse_iterator<iterator>          reverse_iterator;
			typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
		private:
			//variabili utili
		public:
			/*
			** vector constructor & deconstructor
			*/
			vector(){};
			explicit vector( const Allocator& alloc ){};
			explicit vector(	size_type count, 
								const T& value = T(),
								const Allocator& alloc = Allocator()) {};
			template< class InputIt >
			vector( InputIt first, InputIt last,
					const Allocator& alloc = Allocator() ){};
			vector( const vector& other ){};
			vector( const vector& other, const Allocator& alloc ){};
			~vector();
	};


}

#endif