/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlnode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:03:35 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/12 16:04:20 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLNODE_HPP
#define AVLNODE_HPP

template <class T>
class AVLNode {
public:
  /** Member types **/
  typedef T value_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef self AVLNode<T>;

  /** Member functions **/

  // (1) default constructor
  AVLNode() : _right(NULL), left(NULL), parent(NULL), _data(value_type()) {};

  // (2) constructor with data and optional parent
  AVLNode(value_type data, const self* parent = NULL) : right(NULL), left(NULL), _data(data) {}

  // getters 
  const T& getData() { return _data; }

  // setters 
  void setData(const_reference data) { _data = data }


private:
  value_type _data;
  self* right;
  self* left;
  self* parent;
};

#endif