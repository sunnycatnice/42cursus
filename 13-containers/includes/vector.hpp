#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>

namespace ft
{
	//generic template
	template <
	class T,
	class Alloc = std::allocator<T> 
	> class vector
	{
		public:
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer  			const_pointer;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef ft::vector_iterator<pointer>						iterator;
			typedef ft::vector_iterator<const_pointer>					const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		protected :
			pointer			__vector;
			size_t			_size;
			size_t			_capacity;
			allocator_type	_allocator;
		/* ----------------------------------
			** 			MEMBER FUCTIONS
			** ---------------------------------
		*/
		private:
			void	deallocate()
			{
				for (size_t i = 0; i < this->_size; i++)
					this->_allocator.destroy(this->__vector + i);
				this->_allocator.deallocate(this->__vector, this->_capacity);
				this->_capacity = 0;
			}
		public:
			/* @link https://en.cppreference.com/w/cpp/container/vector
			** vector constructor & deconstructor
			*/
			vector()
			{
				this->__vector = this->_allocator.allocate(0);
				this->_size = 0;
				this->_capacity = 0;
			};
			explicit vector( const Allocator& alloc )
			{
				this->__vector = this->_allocator.allocate(0);
				this->_size = 0;
				this->_capacity = 0;
				this->_allocator = alloc;
			};
			explicit vector(	size_type count, 
								const T& value = T(),
								const Allocator& alloc = Allocator()) 
			{
				this->__vector = this->_allocator.allocate(count);
				this->_size = count;
				this->_capacity = count;
				this->_allocator = alloc;
				for (size_t i = 0; i < count; i++)
					this->_allocator.construct(this->__vector + i, value);
			};
			template< class InputIt >
			vector( InputIt first,
					InputIt last,
					const Allocator& alloc = Allocator() )
			{
				this->_size = 0;
				this->_capacity = 0;
				this->_allocator = alloc;
				this->assign(first, last);
			};
			vector( const vector& other )
			{
				this->_size = 0;
				this->_capacity = 0;
				this->_allocator = other._allocator;
				this->assign(other.begin(), other.end());
			};
			vector( const vector& other, const Allocator& alloc )
			{
				this->_size = 0;
				this->_capacity = 0;
				this->_allocator = alloc;
				this->assign(other.begin(), other.end());
			};
			~vector()
			{
				this->deallocate();
			};
			/* @link https://en.cppreference.com/w/cpp/container/vector
			** vector assign
			*/
			vector& operator=( const vector& other )
			{
				this->assign(other.begin(), other.end());
				return (*this);
			};
			template< class InputIt >
			void assign( InputIt first, InputIt last )
			{
				this->deallocate();
				this->_size = 0;
				for (InputIt it = first; it != last; it++)
				{
					this->push_back(*it);
				}
			};
			void assign( size_type count, const T& value )
			{
				this->deallocate();
				this->_size = 0;
				for (size_t i = 0; i < count; i++)
				{
					this->push_back(value);
				}
			};
			/* @link https://en.cppreference.com/w/cpp/container/vector
			** vector iterators
			*/
			iterator begin()
			{
				return (iterator(this->__vector));
			};
			const_iterator begin() const
			{
				return (const_iterator(this->__vector));
			};
			iterator end()
			{
				return (iterator(this->__vector + this->_size));
			};
			const_iterator end() const
			{
				return (const_iterator(this->__vector + this->_size));
			};
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->end()));
			};
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			};
			reverse_iterator rend()
			{
				return (reverse_iterator(this->begin()));
			};
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->begin()));
			};
			/* @link https://en.cppreference.com/w/cpp/container/vector
			** vector capacity
			*/
			bool empty() const
			{
				if (this->_size == 0)
					return (true);
				return (false);
			};
			size_type size() const
			{
				return (this->_size);
			};
			size_type max_size() const
			{
				return (this->_allocator.max_size());
			};
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