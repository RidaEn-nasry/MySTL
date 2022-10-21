/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:42:45 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/21 09:56:49 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <type_traits>

namespace ft {

  template <class T>
  struct is_integral {
    /** member constants */
    static const bool value = false;
    /** member functions **/
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<bool> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<char> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<char16_t> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<char32_t> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<wchar_t> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<signed char> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<short int> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<int> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<long int> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<long long int> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<unsigned char> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<unsigned short int> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<unsigned int> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<unsigned long int> {
    static const bool value = true;
    operator bool() const { return value; }
  };

  template <>
  struct is_integral<unsigned long long int> {
    static const bool value = true;
    operator bool() const { return value; }
  };


} // namespace ft
#endif
