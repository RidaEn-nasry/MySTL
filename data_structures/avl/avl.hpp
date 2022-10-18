/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:36:58 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/18 14:37:41 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/* half-assed implementation of AVL tree as a templated class.               */
/* it takes a key and a value and stores them in a node.                     */
/*****************************************************************************/


namespace ft {
#ifndef AVL_HPP
#define AVL_HPP

#include <less.hpp>
#include "avlnode.hpp"
#include <iostream>

  template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<AVLNode<T> > >
  class AVLTree {
  public:

    /** member types **/
    // typedef T mapped_type;

    // typedef 
    // typedef va
    typedef AVLNode<T> node_type;
    typedef Compare key_compare;

    typedef typename Alloc::template rebind<node_type>::other allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;

    // default constructor
    AVLTree(const allocator_type& alloc = allocator_type()) {
      _alloc = alloc;
      _comp = Compare();
      _root = 0;
      _size = 0;
    };

    // initializing constructor
    explicit AVLTree(const node_type* node) {
      _alloc = allocator_type();
      _comp = Compare();
      _root = _alloc.allocate(1);
      _alloc.construct(_root, node);
      _root->setParent(NULL);
      _root->setLeft(NULL);
      _root->setRight(NULL);
      _size = 1;
    };

    AVLTree(const AVLTree<T>& other) { *this = other; }

    AVLTree<T>& operator=(const AVLTree<T>& other) {
      if (this != &other) {
        if (_root != NULL)
          clear();
        copy(other._root);
        _size = other._size;
      }
      return *this;
    }

    ~AVLTree() { clear(); }

    /** member functions **/

    // searching 
    const node_type& find(const node_type* node) const {
      node_type* tmp = _root;
      while (tmp != NULL) {
        // search for the node using compare
        if (_comp(node->data(), tmp->data()))
          tmp = tmp->left();
        else if (_comp(tmp->data(), node->data()))
          tmp = tmp->right();
        else
          return tmp->data();
      }
      return NULL;
    };

    // inserting 
    void insert(const node_type* node) {
      if (!_root)
      {
        _root = _alloc.allocate(1);
        _alloc.construct(_root, node);
        _root->setParent(NULL);
        _root->setLeft(NULL);
        _root->setRight(NULL);
        _size++;
        return;
      }

      node_type* node = _root;
      node = _find(data);
      if (node->data() == data)
        return;
      node_type* new_node = _alloc.allocate(1);
      _alloc.construct(new_node, data);
      new_node->setParent(node);
      new_node->setLeft(NULL);
      new_node->setRight(NULL);
      if (_comp(data, node->data()))
        node->setLeft(new_node);
      else
        node->setRight(new_node);
      _size++;
      _balance();
    };

    // deleting
    void remove(mapped_type& data) {
      node_type* node = _find(data);
      if (node->data() != data)
        return;
      // if node has no children, or only one child
      if (node->left() == NULL || node->right == NULL)
        _splice(node);
      else {
        // find the smallest node in the right subtree
        node_type* min = node->right();
        while (min->left() != NULL)
          min = min->left();
        // replace the node with the smallest node in the right subtree
        node->setData(min->data());
        _splice(min);
      }
    }

    // clearing
    void clear() {
      node_type* current = _root;
      node_type* parent = NULL;
      while (current != NULL) {
        // if the node has a left child, go to it
        if (current->left() != NULL)
          current = current->left();
        else if (current->right() != NULL)
          current = current->right();
        else {
          parent = current->parent();
          // if the current node is the left child of its parent , set the parent's left child to NULL
          if (parent != NULL && parent->left() == current) {
            _alloc.destroy(current);
            _alloc.deallocate(current, 1);
            parent->setLeft(NULL);
          }
          else if (parent != NULL && parent->right() == current) {
            _alloc.destroy(current);
            _alloc.deallocate(current, 1);
            parent->setRight(NULL);
          }
          --_size;
          current = parent;
        }
      }
    };

    // copy
    void copy(node_type* other) {
      if (other == NULL)
        return;
      insert(other->data());
      copy(other->left());
      copy(other->right());
    }

    // height
    int height() const {
      return _root->height();
    }

    // print 
    void print() const {
      _print(_root);
    };

    // getters 
    node_type* root() const { return _root; }
    // end 
    node_type* end() const { return NULL; }
    // min 
    node_type* min() const {
      node_type* node = _root;
      while (node->left() != NULL)
        node = node->left();
      return node;
    };
    // max
    node_type* max() const {
      node_type* node = _root;
      while (node->right() != NULL)
        node = node->right();
      return node;
    };



  private:
    node_type* _root;
    size_t _size;
    key_compare _comp;
    allocator_type _alloc;


    /* private member functions */
    node_type* _find(const mapped_type& data) {
      node_type* node = _root;
      node_type* parent = NULL;
      while (node != NULL) {
        // save the parent as the closest node
        parent = node;
        // search for the node using compare
        if (_comp(data, node->data()))
          node = node->left();
        else if (_comp(node->data(), data))
          node = node->right();
        else
          return node;
      }
      return parent;
    };

    // balance the tree
    void _balance() {
      int balance = _root->balance();
      if (balance < 2 && balance > -2)
        return;
      // if left heavy
      if (balance > 1) {
        // if left-right heavy
        if (_root->left()->balance() < 0)
          _rotateLeft(_root->left());
        _rotateRight(_root);
      }
      // if right heavy
      else {
        // if right-left heavy
        if (_root->right()->balance() > 0)
          _rotateRight(_root->right());
        _rotateLeft(_root);
      }
    };

    void _rotateLeft(node_type* node) {
      node_type* right = node->right();
      node_type* parent = node->parent();
      node_type* right_left = right->left();

      // if node is root
      if (!parent)
        // set the right child as root
        _root = right;
      else {
        // if node is left child
        if (parent->left() == node)
          // set the right child as left child
          parent->setLeft(right);
        else // if node is right child
          // set the right child as right child
          parent->setRight(right);
      }
      // set the right child's parent to the node's parent
      right->setParent(parent);
      // set the node's parent to the right child
      node->setParent(right);
      // set the right child's left child to the node
      right->setLeft(node);
      // set the node's right child to the right child's left child
      node->setRight(right_left);
      // if the right child's left child is not null
      if (right_left)
        // set the right child's left child's parent to the node
        right_left->setParent(node);
    };

    void _rotateRight(node_type* node) {
      node_type* left = node->left();
      node_type* parent = node->parent();
      node_type* left_right = left->right();

      // if node is root
      if (!parent)
        // set the left child as root
        _root = left;
      else {
        // if node is left child
        if (parent->left() == node)
          // set the left child as left child
          parent->setLeft(left);
        else // if node is right child
          // set the left child as right child
          parent->setRight(left);
      }
      // set the left child's parent to the node's parent
      left->setParent(parent);
      // set the node's parent to the left child
      node->setParent(left);
      // set the left child's right child to the node
      left->setRight(node);
      // set the node's left child to the left child's right child
      node->setLeft(left_right);
      // if the left child's right child is not null
      if (left_right)
        // set the left child's right child's parent to the node
        left_right->setParent(node);
    };


    // splice a leaf or single-child node
    void _splice(node_type* node) {
      node_type* tmp, parent;
      // if node has left or right child
      if (node->left() != NULL)
        tmp = node->left();
      else
        tmp = node->right();
      // if node is root
      if (node == _root)
        _root = tmp;
      else {
        parent = node->parent();
        // if node is left child of parent
        if (parent->left() == node)
          parent->setLeft(tmp);
        else // if node is right child of parent
          parent->setRight(tmp);
      }
      // if node has a child, set the child's parent to the node's parent
      if (tmp)
        tmp->setParent(node->parent());
      // deallocate the node
      _alloc.destroy(node);
      _alloc.deallocate(node, 1);
      --_size;
    };

    void _print(node_type* node) const {
      if (node == NULL)
        return;
      _print(node->left());
      std::cout << node->data() << std::endl;
      _print(node->right());
    };

  }; // end of AVLTree class

}; // namespace ft
#endif