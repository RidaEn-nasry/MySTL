/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator_wrapper.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:46:59 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/06 17:52:49 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <bool flag, class isTrue, class isFalse>
struct choose;

template <class isTrue, class isFalse>
struct choose<true, isTrue, isFalse> {
  typedef isTrue type;
};

template <class isTrue, class isFalse>
struct choose < false, isTrue, isFalse> {
  typedef isFalse type;
};


