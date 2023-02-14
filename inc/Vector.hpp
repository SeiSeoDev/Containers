#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
#define DEBUG_VEC 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <limits>
#include "random_acces_iter.hpp"
#include "utils.hpp"

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{

	public:
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef std::size_t size_type;
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef iterator_traits<T> iterator;	
		typedef iterator_traits <const T> const_iterator;	
		// typedef const std::iterator<std::random_access_iterator_tag, T> const_iterator;
		// typedef std::iterator<std::random_access_iterator_tag, T> iterator;
		/* Construct */
	private:
		pointer _begin;
		size_type _capacity;
		size_type _size;
		allocator_type _alloc;

	public:
		// _____________________________Construct/Destruct_________________________________

		vector (const vector& x);
		explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc)
		{
			_begin = NULL;
			_capacity = 0;
			_size = 0;
		};

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _capacity(n), _size(n), _alloc(alloc)
		{
			_begin = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(&_begin[i], val);
			}
		};

		template <class InputIterator>
		vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()): _alloc(alloc)
		{
			_size = std::distance(first, last);
			_begin = _alloc.allocate(_size);
			_capacity = _size;
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(&_begin[i], &first[i]);
			}
		};
		
		~vector()
		{
			if (_begin)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_begin[i]);
				_alloc.deallocate(_begin, _capacity);
				_size = 0;
				_capacity = 0;
				_begin = NULL;
			}
		}
		// ________________________________________ methods _____________________________

		iterator end()
		{
			return iterator(_begin + _size);
		}

		iterator begin()
		{
			return iterator(_begin);
		}




		// ________________________________________ modifiers _____________________________

		void clear();// TODO (erase + iter)
		iterator insert (iterator position, const value_type& val); // TODO (iter)
		void insert (iterator position, size_type n, const value_type& val);// TODO (iter)
		template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);// TODO (iter)
		iterator erase (iterator position) // TODO CHANGE RETURN VALUE FOR DEFAULT CASE AND NORMAL CASE
		{
			iterator _end = end();
			try 
			{
				if (position == _end)
					return (_end);
				size_type dist = position - begin();
				for (size_type i = dist; i < _size - 1; i++)
						_begin[i] = _begin[i + 1];
					_alloc.destroy(&_begin[--_size]);
					return (begin()); 
			}
			catch (const std::exception& e)
			{
				throw "Error : erase";
			}
			return (end());
		}
		iterator erase (iterator first, iterator last); //TODO (iter)
		
		void swap (vector& x) // TODO
		{
			size_t	tmp_capacity = x._capacity;
			size_t	tmp_size = x._size;
			Alloc	tmp_alloc = x._alloc;
			pointer	tmp_begin = x._begin;

			x._capacity = _capacity;
			x._size = _size;
			x._alloc = _alloc;
			x._begin = _begin;

			_capacity = tmp_capacity;
			_size = tmp_size;
			_alloc = tmp_alloc;
			_begin = tmp_begin;
		}

		size_type max_size()
		{
			return (_alloc.max_size());
		}

		void reserve(size_type st) //TODO
		{
			if (st > max_size())
				throw std::length_error("Vector::reserve");
			else if (st > _capacity)
			{
				size_type tmp_size = _size;
				size_type tmp_capacity = _capacity;
				pointer tmp_begin = _begin;
				_capacity = st;
				if (st > 0)
				{
					_begin = _alloc.allocate(_capacity);
					for (_size = 0; _size < tmp_size; _size++)
						_alloc.construct(&_begin[_size], tmp_begin[_size]);
				}
				for (size_type i = 0; i < tmp_size; i++)
					_alloc.destroy(&tmp_begin[i]);
				_alloc.deallocate(tmp_begin, tmp_capacity);
			} 
		}
		void push_back (const value_type& val) //TODO reserve on HERE
		{
			if (_capacity < _size + 1)
			{
				try {
					reserve(std::max(_size * 2, (size_type)1));
				}
				catch (...)
				{
					std::cerr << "pushback fail" << std::endl;
				}
			}	
			_alloc.construct(&_begin[_size++], val);
		}

		void pop_back() // TO_CHECK
		{
			if (_size <= 0 || _begin == NULL)
				return;
			_alloc.destroy(&_begin[--_size]);
		};
		void print()
		{
			for (size_type i = 0; i < _size; i++)
			{
				std::cout << _begin[i] << std::endl;
			}
		}
		void resize (size_type n, value_type val = value_type()); // TODO 
	};
		template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end())); }

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return (!(x < y) && !(y < x)); };

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return (!(x == y)); }

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return (!(x > y)); }

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return (ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end())); }

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return (!(x < y)); }

}
#endif
