/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:47:18 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/02 13:05:58 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*********************************************************************************************/
 /*  stack is a container adapter (container adapters are classes that encapsulate other )  */
 /* container and provide an different interface to access and modify those containers thus */
 /* changing their behaviour.                                                               */
 /*******************************************************************************************/

namespace ft {
#ifndef STACK_HPP
#define STACK_HPP


  template <class T, class Container = vector<T> >
  class stack {
    /************************** Member types **************************/

    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

    /************************** Member functions **************************/
    explicit  stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

    bool empty() const { return _ctnr.empty(); }
    size_type size() const { return _ctnr.size(); }

    value_type& top() { return _ctrn.back(); }
    const value_type& top() const { return _ctnr.back(); }

    void push(const value_type& val) { _ctnr.push_back(val); }

    void pop() { _ctnr.pop_back(); }

    void swap(stack& x) noexcept { _ctnr.swap(x._ctnr); }

    // todo: emplace member function
  };
  /************************* non-member functions *************************/
  template <class T, class Container>
  bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._ctnr == rhs._ctnr;
  };

  template <class T, class Container>
  bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._ctnr != rhs._ctnr;
  };

  template <class T, class Container>
  bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._ctnr < rhs._ctnr;
  };

  template <class T, class Container>
  bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._ctnr <= rhs._ctnr;
  };
  
  template <class T, class Container>
  bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._ctnr > rhs._ctnr;
  };

  template <class T, class Container>
  bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._ctnr >= rhs._ctnr;
  };

  template <class T, class Container>
  void swap(stack<T, Container>& x, stack<T, Container>& y) noexcept {
    x.swap(y);
  };

#endif
} // namespace ft