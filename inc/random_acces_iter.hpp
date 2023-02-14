#include "iterator_traits.hpp"

namespace ft
{
    template <typename T>
    class random_access_iter
    {
        public :
            typedef typename iterator_traits<T*>::iterator_category iterator_category;
            typedef typename iterator_traits<T*>::value_type        value_type;
            typedef typename iterator_traits<T*>::difference_type   difference_type;
            typedef typename iterator_traits<T*>::pointer           pointer;
            typedef typename iterator_traits<T*>::reference         reference;

            random_access_iter();
            random_access_iter(pointer elem);
            random_access_iter(const random_access_iter &iter);
            virtual ~random_access_iter();
            pointer base() const{ return (it);}
            random_access_iter  operator=(const random_access_iter iter);
            reference operator*() const { return (*it);}
            pointer operator->() {return (&operator*());}
            random_access_iter &operator++()
            {
                it++;
                return (*this);
            }
            random_access_iter operator++(int)
            {
                random_access_iter tmp(*this);
                it++;
                return (tmp);
            }
            random_access_iter &operator--()
            {
                it--;
                return (*this);
            }
            random_access_iter operator--(int)
            {
                random_access_iter tmp(*this);
                it--;
                return (tmp);
            }
            random_access_iter operator+(difference_type diff){return (it + diff);}
            random_access_iter operator-(difference_type diff){return (it - diff);}
            random_access_iter &operator-=(difference_type diff)
            {
                it -= diff;
                return (*this);
            }
            random_access_iter &operator+=(difference_type diff)
            {
                it += diff;
                return (*this);
            }
            reference operator[](difference_type pos)
            {
                return (*operator+(pos));
            }
            operator random_access_iter<const T> () const
            {
                return (random_access_iter<const T>(it));
            }
        private :
            pointer it;
    };
	template <typename T>
	bool	operator==(const ft::random_access_iter<T> lhs, const ft::random_access_iter<T> rhs)
	{ return (lhs.base() == rhs.base()); }

	template<typename T_L, typename T_R>
	bool	operator==(const ft::random_access_iter<T_L> lhs, const ft::random_access_iter<T_R> rhs)
	{ return (lhs.base() == rhs.base()); }

	template <typename T>
	bool	operator!=(const ft::random_access_iter<T> lhs, const ft::random_access_iter<T> rhs)
	{ return (lhs.base() != rhs.base()); }

	template<typename T_L, typename T_R>
	bool	operator!=(const ft::random_access_iter<T_L> lhs, const ft::random_access_iter<T_R> rhs)
	{ return (lhs.base() != rhs.base()); }

	template <typename T>
	bool	operator<(const ft::random_access_iter<T> lhs,
			  const ft::random_access_iter<T> rhs)
	{ return (lhs.base() < rhs.base()); }

	template<typename T_L, typename T_R>
	bool	operator<(const ft::random_access_iter<T_L> lhs, const ft::random_access_iter<T_R> rhs)
	{ return (lhs.base() < rhs.base()); }

	template <typename T>
	bool	operator>(const ft::random_access_iter<T> lhs, const ft::random_access_iter<T> rhs)
	{ return (lhs.base() > rhs.base()); }

	template<typename T_L, typename T_R>
	bool	operator>(const ft::random_access_iter<T_L> lhs, const ft::random_access_iter<T_R> rhs)
	{ return (lhs.base() > rhs.base()); }

	template <typename T>
	bool	operator<=(const ft::random_access_iter<T> lhs, const ft::random_access_iter<T> rhs)
	{ return (lhs.base() <= rhs.base()); }

	template<typename T_L, typename T_R>
	bool	operator<=(const ft::random_access_iter<T_L> lhs, const ft::random_access_iter<T_R> rhs)
	{ return (lhs.base() <= rhs.base()); }

	template <typename T>
	bool	operator>=(const ft::random_access_iter<T> lhs, const ft::random_access_iter<T> rhs)
	{ return (lhs.base() >= rhs.base()); }

	template<typename T_L, typename T_R>
	bool	operator>=(const ft::random_access_iter<T_L> lhs, const ft::random_access_iter<T_R> rhs)
	{ return (lhs.base() >= rhs.base()); }

	template<typename T>
	ft::random_access_iter<T>
	operator+(typename ft::random_access_iter<T>::difference_type n, typename ft::random_access_iter<T>& rai)
	{ return (&(*rai) + n); }

	template <typename T>
	typename ft::random_access_iter<T>::difference_type
	operator-(const ft::random_access_iter<T> lhs, const ft::random_access_iter<T> rhs)
	{ return (lhs.base() - rhs.base()); }

	template<typename T_L, typename T_R>
	typename ft::random_access_iter<T_L>::difference_type
	operator-(const ft::random_access_iter<T_L> lhs, const ft::random_access_iter<T_R> rhs)
	{ return (lhs.base() - rhs.base()); }
    template <typename T>
    class reverse_random_access_iter
    {
        public :
            typedef T                                               iterator;
            typedef typename iterator_traits<T>::iterator_category iterator_category;
            typedef typename iterator_traits<T>::value_type        value_type;
            typedef typename iterator_traits<T>::difference_type   difference_type;
            typedef typename iterator_traits<T>::pointer           pointer;
            typedef typename iterator_traits<T>::reference         reference;

            reverse_random_access_iter();
            reverse_random_access_iter(pointer elem);
            reverse_random_access_iter(const reverse_random_access_iter &iter);
            virtual ~reverse_random_access_iter();
            pointer base() const{ return (it);}
            reverse_random_access_iter  operator=(const reverse_random_access_iter iter);
            reference operator*() const { return (*it);}
            pointer operator->() {return (&operator*());}
            reverse_random_access_iter &operator++()
            {
                it--;
                return (*this);
            }
            reverse_random_access_iter operator++(int)
            {
                reverse_random_access_iter tmp(*this);
                it--;
                return (tmp);
            }
            reverse_random_access_iter &operator--()
            {
                it++;
                return (*this);
            }
            reverse_random_access_iter operator--(int)
            {
                reverse_random_access_iter tmp(*this);
                it++;
                return (tmp);
            }
            reverse_random_access_iter operator+(difference_type diff){return (it - diff);}
            reverse_random_access_iter operator-(difference_type diff){return (it + diff);}
            reverse_random_access_iter &operator-=(difference_type diff)
            {
                it += diff;
                return (*this);
            }
            reverse_random_access_iter &operator+=(difference_type diff)
            {
                it -= diff;
                return (*this);
            }
            reference operator[](difference_type pos)
            {
                return (*operator-(pos));
            }
            operator reverse_random_access_iter<const T> () const
            {
                return (reverse_random_access_iter<const T>(it));
            }
        private :
            iterator it;
    };
}