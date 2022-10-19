/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:35:24 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/18 18:40:00 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

#ifndef PAIR_HPP
#define  PAIR_HPP

  template <class T1, class T2>
  struct pair {
    /** member types **/
    typedef T1 first_type;
    typedef T2 second_type;
    
    /** member variables **/
    first_type first;
    second_type second;

    /** member functions **/

    // (1) default constructor 
    inline pair() : first(), second() {};

    // (2) copy constructor 
    template <class U, class V>
    inline pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {};

    // (3) initialization constructor 
    inline pair(const first_type& a, const second_type& b) : first(a), second(b) {};

    // copy assignement constructor 
    inline pair& operator=(const pair& pr) {
      first = pr.first;
      second = pr.second;
      return *this;
    };


    /*** non-member function overloads **/
    friend inline bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
      return lhs.first == rhs.first && lhs.second == rhs.second;
    };

    friend inline bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
      return !(lhs == rhs);
    };

    friend inline bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
      return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    };
    
    friend inline bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
      return !(rhs < lhs);
    };
    friend inline bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
      return rhs < lhs;
    };
    friend inline bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
      return !(lhs < rhs);
    };

    

  };

#endif

};