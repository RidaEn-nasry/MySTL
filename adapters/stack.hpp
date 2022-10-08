/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:47:18 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/07 19:17:47 by ren-nasr         ###   ########.fr       */
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
  public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

    /************************** Member functions **************************/
    explicit  stack(const container_type& cntr = container_type()) : _cntr(cntr) {}

    bool empty() const { return _cntr.empty(); }
    size_type size() const { return _cntr.size(); }

    value_type& top() { return _cntr.back(); }
    const value_type& top() const { return _cntr.back(); }

    void push(const value_type& val) {
      _cntr.push_back(val);
    }

    void pop() { _cntr.pop_back(); }

    void swap(stack& x) { _cntr.swap(x._cntr); }
    // adding templates to all these guys.
    friend bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
      return lhs._cntr == rhs._cntr;
    }

    friend bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
      return !(lhs == rhs);
    }

    friend bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
      return lhs._cntr < rhs._cntr;
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

  private:
    container_type _cntr;
  };
  /************************* non-member functions *************************/
  template <class T, class Container>
  bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._cntr == rhs._cntr;
  };

  template <class T, class Container>
  bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._cntr != rhs._cntr;
  };

  template <class T, class Container>
  bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._cntr < rhs._cntr;
  };

  template <class T, class Container>
  bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._cntr <= rhs._cntr;
  };

  template <class T, class Container>
  bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._cntr > rhs._cntr;
  };

  template <class T, class Container>
  bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return lhs._cntr >= rhs._cntr;
  };

  template <class T, class Container>
  void swap(stack<T, Container>& x, stack<T, Container>& y) {
    x.swap(y);
  };

#endif
} // namespace ft