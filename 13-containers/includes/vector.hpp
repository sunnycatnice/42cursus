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
			/* ----------------------------------
			** 			MEMBER FUCTIONS
			** ---------------------------------
			** @link https://en.cppreference.com/w/cpp/container/vector
			** vector constructor & deconstructor
			*/
			vector();
			explicit vector( const Allocator& alloc );
			explicit vector(	size_type count, 
								const T& value = T(),
								const Allocator& alloc = Allocator()) ;
			template< class InputIt >
			vector( InputIt first,
					InputIt last,
					const Allocator& alloc = Allocator() );
			vector( const vector& other );
			vector( const vector& other, const Allocator& alloc );
			~vector();
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/operator%3D
			** operator =
			*/
			vector& operator=( const vector& other );
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/assign
			** assign
			*/
			void assign( size_type count, const T& value );
			template< class InputIt >;
			void assign( InputIt first, InputIt last );
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/get_allocator
			** get_allocator
			*/
			allocator_type get_allocator() const;

			/* --------------------------------
			** 			ELEMENT ACCESS
			** --------------------------------
			** @link https://en.cppreference.com/w/cpp/container/vector/at
			** at
			*/
			reference at( size_type pos );
			const_reference at( size_type pos ) const;
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/operator_at
			** operator []
			*/
			reference operator[]( size_type pos );
			const_reference operator[]( size_type pos ) const;
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/front
			** front
			*/
			reference front();
			const_reference front() const;
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/back
			** back
			*/
			reference back();
			const_reference back() const;
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/data
			** data
			*/
			T* data();
			const T* data() const;
			/* ----------------------------------
			** 				ITERATORS
			** ----------------------------------
			** @link https://en.cppreference.com/w/cpp/container/vector/begin
			** begin cbegin
			*/
			iterator begin();
			const_iterator begin() const;
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/end
			** end cend
			*/
			iterator end();
			const_iterator end() const;
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/rbegin
			** rbegin
			*/
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			/* ----------------------------------
			** 				CAPACITY
			** ----------------------------------
			** @link https://en.cppreference.com/w/cpp/container/vector/empty
			** empty
			*/
			bool empty() const;
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/size
			** size
			*/
			size_type size() const;
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/max_size
			** max_size
			*/
			size_type max_size() const;
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/reserve
			** reserve
			*/
			void reserve( size_type new_cap );
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/capacity
			** capacity
			*/
			size_type capacity() const;
			/* ----------------------------------
			** 				MODIFIERS
			** ----------------------------------
			** @link https://en.cppreference.com/w/cpp/container/vector/clear
			** clear
			*/
			void clear();
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/insert
			** insert
			*/
			iterator insert( iterator pos, const T& value );
			void insert( iterator pos, size_type count, const T& value );
			template< class InputIt >
				void insert( iterator pos, InputIt first, InputIt last );
			/*
			** @link https://en.cppreference.com/w/cpp/container/vector/erase
			** erase
			*/
			iterator erase( iterator pos );
			iterator erase( iterator first, iterator last );
	};
	/* ----------------------------------
	** 				Non-member functions
	** ----------------------------------
	/*
	** @link https://en.cppreference.com/w/cpp/container/vector/operator_cmp
	** operators
	*/
	template< class T, class Alloc >
	bool operator==( const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs );
	template< class T, class Alloc >
	bool operator!=( const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs );
	template< class T, class Alloc >
	bool operator<( const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs );
	template< class T, class Alloc >
	bool operator<=( const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs );
	template< class T, class Alloc >
	bool operator>( const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs );
	template< class T, class Alloc >
	bool operator>=( const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs );
	template< class T, class Alloc >
	/*
	** @link https://en.cppreference.com/w/cpp/container/vector/swap2
	** swap
	*/
	void swap( std::vector<T,Alloc>& lhs,
			std::vector<T,Alloc>& rhs );
}

#endif