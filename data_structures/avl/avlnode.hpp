/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlnode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:03:35 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/16 19:14:55 by ren-nasr         ###   ########.fr       */
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
  AVLNode() : _right(NULL), _left(NULL), _parent(NULL), _data(value_type()) {}

  // (2) constructor with data and optional parent
  AVLNode(value_type data, self* parent = NULL) : _right(NULL), _left(NULL), _data(data), _parent(parent) {}

  // getters 
  inline const_reference getData() const { return _data; }

  inline self* right() const { return _right; }

  inline self* left() { return _left; }

  inline self* parent() { return _parent; }

  inline int height() const {
    // calculate the height of the node 
    // if the node is a leaf then the height is 0
    // if the node has only one child then the height is 1
    // if the node has two children then the height is the max height of the two children + 1
    int left_height = 0;
    int right_height = 0;
    if (_left != NULL) {
      left_height = _left->height();
    }
    if (_right != NULL) {
      right_height = _right->height();
    }
    return (left_height > right_height ? left_height : right_height) + 1;
  }

  // setters 
  void setData(reference data) { _data = data; }
  void setRight(self* right) { _right = right; }
  void setLeft(self* left) { _left = left; }
  void setParent(self* parent) { _parent = parent; }


  // calculate the balance of the node
  int balance() const {
    // the balance is the height of the left subtree - the height of the right subtree
    int left_height = _left == NULL ? 0 : _left->height();
    int right_height = _right == NULL ? 0 : _right->height();
    return left_height - right_height;
  }
private:
  value_type _data;
  self* _right;
  self* _left;
  self* _parent;


};

#endif
