/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:47:18 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/24 18:29:33 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*********************************************************************************************/
 /*  stack is a container adapter (container adapters are classes that encapsulate other )  */
 /* container and provide an different interface to access and modify those containers thus */
 /* changing their behaviour.                                                               */
 /*******************************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP
#include <equal.hpp>
#include <lexico_compare.hpp>
#include <stack.hpp>
#include <vector.hpp>

namespace ft {


  template <class T, class Container = vector<T> >
  class stack {
    /************************** Member types **************************/
  public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

    /************************** Member functions **************************/
    explicit  stack(const container_type& cntr = container_type()) : c(cntr) {}

    bool empty() const { return c.empty(); }
    size_type size() const { return c.size(); }

    value_type& top() { return c.back(); }
    const value_type& top() const { return c.back(); }

    void push(const value_type& val) {
      c.push_back(val);
    }

    void pop() { c.pop_back(); }

    void swap(stack& x) { c.swap(x.c); }
    /************************* non-member functions *************************/

    friend bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
      return lhs.c == rhs.c;
    }

    friend bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
      return !(lhs == rhs);
    }

    friend bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
      return lhs.c < rhs.c;
    }

    friend bool operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
      return !(rhs < lhs);
    }

    friend bool operator>  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
      return rhs < lhs;
    }
    friend bool operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
      return !(lhs < rhs);
    }

    void swap(stack<T, Container>& x, stack<T, Container>& y) {
      x.swap(y);
    };

    
    // member objects
  protected:
    container_type c;
  };

} // namespace ft

#endif