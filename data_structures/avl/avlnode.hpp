/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlnode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:03:35 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/15 16:04:07 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLNODE_HPP
#define AVLNODE_HPP

#include <stdio.h>

template <class T>
class AVLNode {
public:
  /** Member types **/
  typedef T value_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef  AVLNode<T> self;

  /** Member functions **/

  // (1) default constructor
  AVLNode() : _right(NULL), _left(NULL), _parent(NULL), _data(value_type()) {};

  // (2) constructor with data and optional parent
  AVLNode(value_type data, const self* parent = NULL) : _right(NULL), _left(NULL), _data(data) {}

  // getters 
  reference getData() { return _data; }

  self* right() { return _right; }

  self* left() { return _left; }

  self* parent() { return _parent; }

  // setters 
  void setData(const_reference data) { _data = data; }
  void setRight(const self* right) { _right = right; }
  void setLeft(const self* left) { _left = left; }
  void setParent(const self* parent) { _parent = parent; }

private:
  value_type _data;
  self* _right;
  self* _left;
  self* _parent;
};

#endif
