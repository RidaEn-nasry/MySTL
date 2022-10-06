/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:45:19 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/06 15:16:10 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/* SFINAE : substitution failure is not an error                             */
/*         if a template is not instantiated because of a substitution       */
/*         failure, the compiler will not report an error                    */
/*                                                                           */
/* enable_if :                                                               */
/*         enable_if is a template that takes a boolean value and a type     */
/*         as template parameters. If the boolean value is true, the type    */
/*         is returned, otherwise the type is not returned                   */
/*                                                                           */
/*         enable_if is used to enable a template only if a condition is     */
/*         true.                                                             */
/*****************************************************************************/


namespace ft {
#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

  template <bool Cond, class T = void>
  struct enable_if {};

  template <class T>
  struct enable_if<true, T> {
    typedef T type;
  };

#endif
} // namespace ft
