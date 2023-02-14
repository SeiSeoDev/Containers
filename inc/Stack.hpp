#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>

namespace ft{
	template <class T, class Container = std::vector<T> >
		class stack {
		
		private:
			template <typename _T, typename _Container>
			friend bool operator==(const stack<_T, _Container>& x,
				const stack<_T, _Container>& y);

			template <typename _T, typename _Container>
			friend bool operator< (const stack<_T, _Container>& x,
				const stack<_T, _Container>& y);

			template <typename _T, typename _Container>
			friend bool operator!= (const stack<_T, _Container>& x,
				const stack<_T, _Container>& y);
			
			template <typename _T, typename _Container>
			friend bool operator<= (const stack<_T, _Container>& x,
				const stack<_T, _Container>& y);

			template <typename _T, typename _Container>
			friend bool operator>= (const stack<_T, _Container>& x,
				const stack<_T, _Container>& y);

			template <typename _T, typename _Container>
			friend bool operator> (const stack<_T, _Container>& x,
				const stack<_T, _Container>& y);

		public:
			typedef typename 	Container::value_type value_type;
			typedef typename 	Container::size_type size_type;
			typedef 			Container container_type;

		protected:
			Container _c;

		public:
			explicit stack(const Container& ctn = Container()) : _c(ctn) {}
			
			bool empty() const { return _c.empty(); }
			size_type size() const { return _c.size(); }
			value_type& top() { return _c.back(); }
			const value_type& top() const { return _c.back(); }
			void push(const value_type& x) { _c.push_back(x); }
			void pop() { _c.pop_back(); }
		};
		// non member fcts
}


#endif