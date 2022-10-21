/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:12:30 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/21 09:55:21 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    /* ************************************************************************** */
    /* reverse_iterator is is an adapter that provides a way to iterate over a    */
    /* container backwards.                                                       */
    /* reverse_iterator has always an offset of -1 with respect to the underlying */
    /* iterator.                                                                  */
    /* reverse_iterator adapter can accept random access iterator / bidirectional */
    /* iterator as underlying iterator.                                           */
    /* &*it = &*(it.base() - 1)                                                   */
    /* ************************************************************************** */
#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <iterator_traits.hpp>

namespace ft {
  template <class Iter>
  class reverse_iterator {
    /*********************** Member types ***********************/
  public:
    typedef typename iterator_traits<Iter>::iterator_category iterator_category;
    typedef typename iterator_traits<Iter>::value_type value_type;
    typedef typename iterator_traits<Iter>::difference_type difference_type;
    typedef typename iterator_traits<Iter>::pointer pointer;
    typedef typename iterator_traits<Iter>::reference reference;

    /* ********************* Member functions ********************* */

    /* --------------------- Constructors --------------------- */
    // current
    reverse_iterator() : _current() {}
    // initializaion
    explicit reverse_iterator(Iter x) : _current(x) {}
    // copy
    template <class U>
    reverse_iterator(const reverse_iterator<U>& other) : _current(other.base()) {}

    /* ------------------- other Member functions ------------------- */
    // base 
    Iter base() const { return _current; };
    // operator*
    inline reference operator*() const {
      Iter tmp = _current;
      return *--tmp;
    }
    // operator->
    inline pointer operator->() const { return &(operator*()); }

    // operator++ (pre)
    inline reverse_iterator& operator++() {
      --_current;
      return *this;
    }
    // operator++ (post)
    inline reverse_iterator operator++(int) {
      reverse_iterator tmp = *this;
      --_current;
      return tmp;
    }

    inline reverse_iterator operator--() {
      ++_current;
      return *this;
    }

    inline reverse_iterator operator--(int) {
      reverse_iterator tmp = *this;
      ++_current;
      return tmp;
    }

    // operator+  (offset)
    inline reverse_iterator operator+(difference_type n) const {
      return reverse_iterator(_current - n);
    }

    // operator- (offset)
    inline reverse_iterator operator-(difference_type n) const {
      return reverse_iterator(_current + n);
    }

    // operator+= (offset)
    inline reverse_iterator operator+=(difference_type n) {
      _current -= n;
      return *this;
    }

    // operator-= (offset)
    inline reverse_iterator operator-=(difference_type n) {
      _current += n;
      return *this;
    }

    // operator[] (offset)
    inline reference operator[](difference_type n) {
      return *(*this + n);
    }

  private:
    Iter _current;

  };
  /*************************** Non-member functions ***************************/

  // operator+ (offset)
  template <class Iter>
  reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it) {
    return rev_it + n;
  }

  // operator- (offset)
  template <class Iter>
  reverse_iterator<Iter> operator-(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it) {
    return rev_it - n;
  }

  // relational operators
  template <class Iter>
  bool operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
    return lhs.base() == rhs.base();
  }
  template <class Iter>
  bool operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
    return lhs.base() != rhs.base();
  }

  template <class Iter>
  bool operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
    return lhs.base() != rhs.base();
  }

  template <class Iter>
  bool operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
    return lhs.base() > rhs.base();
  }

  template <class Iter>
  bool operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
    return lhs.base() <= rhs.base();
  }

  template <class Iter>
  bool operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
    return lhs.base() >= rhs.base();
  }



} // namespace ft
#endif