// /* **************************************************************************
// */
// /* */
// /*                                                        :::      ::::::::
// */
/*   bst.hpp                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+ */
// /*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+ */
// /*                                                +#+#+#+#+#+   +#+ */
// /*   Created: 2022/10/12 16:25:51 by ren-nasr          #+#    #+# */
/*   Updated: 2022/10/13 16:16:23 by ren-nasr         ###   ########.fr       */
// /* */
// /* **************************************************************************
// */

// #ifndef BST_HPP
// #define BST_HPP
// #include <less.hpp>

// template <class T>
// struct BSTNode {
//   struct BSTNode* right;
//   struct BSTNode* left;
//   struct BSTNode* parent;
//   T data;
// };

// template <class T, class Compare ft::less<T> >
// class BST {

// public:
//   BST() : _root(NULL), _size(0) {}

//   ~BST() {};

//   BST(const BST<T>& other) { *this = other; }

//   BST& operator=(const BST<T>& rhs) {
//     if (this != &other)
//     {
//       // we will copy the intire bst
//     }
//     return *this;
//   }

//   // operations on the binary search tree
//   // inserting, deleting, adding, searching

// private:
//   BSTNode<T>* _root;
//   size_t _size;
//   Compare _compare;
// };

// #endif

#include <stdio.h>
template <class T> class BSTNode {
public:
  /** member types **/
  typedef BSTNode<T> self;
  typedef T value_type;

  // constructors
  BSTNode() : _right(NULL), _left(NULL), _parent(NULL), _data(T()) {}
  BSTNode(value_type data = value_type(), const self* parent = NULL,
    const self* right = NULL, const self* left = NULL)
    : _data(data), _parent(parent), _right(right), _left(left) {}

  const value_type& getData() { return _data; }

  void setData(value_type data) { _data = data; }

private:
  self* _right;
  self* _left;
  self* _parent;
  T _data;
};

template <class T> class BST {

public:
  /** member types **/
  typedef BSTNode<T> node_type;
  typedef T value_type;

  BST() { _root = new node_type; }

  void add_left(value_type data) {
    node_type* node = _root;
    node_type* parent;
    while (node != NULL) {
      if (!node->left)
        parent = node;
      node = node->left;
    }
    node = new node_type(data, node);
  }

  void add_right(value_type data) {
    node_type* node = _root;
    node_type* parent;

    while (node != NULL) {
      if (!node->right)
        parent = node;
      node = node->right;
    }
    node = new node_type(data, node);
  }

private:
  node_type* _root;
};
