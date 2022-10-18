/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl22.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:12:40 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/17 19:53:29 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implementation of AVL tree as a templated class. */

// should the avl class be implmented as node or a class wrapper that manages
// the node

// balancing will happen when we try to insert a node in the tree

#ifndef AVL_HPP
#define AVL_HPP

#include <less.hpp>
#include "avlnode.hpp"

namespace ft
{

	template <class T>
	class AVLTree
	{
	public:
		/** member types **/
		typedef T value_type;
		typedef AVLNode<T> node_type;


		// default constructor
		AVLTree() : _root(NULL), _size(0) {}

		// initializing constructor
		explicit AVLTree(const value_type& data)
		{
			_root = new node_type;
			_root->setData(data);
			_root->setParent(NULL);
			_root->setLeft(NULL);
			_root->setRight(NULL);
			_size = 1;
		}

		AVLTree(const AVLTree<T>& other) { *this = other; }

		AVLTree<T>& operator=(const AVLTree<T>& other)
		{

			if (this != &other)
			{
				if (_root != NULL)
					clear();
				copy(other._root);
				_size = other._size;
			}
			return *this;
		}

		~AVLTree() { clear(); }

		void clear() {
			// traverse the tree and delete all the nodes
			node_type* current = _root;
			node_type* parent = NULL;

			while (current != NULL) {
				if (current->left() != NULL) {
					current = current->left();
				}
				else if (current->right() != NULL) {
					current = current->right();
				}
				else {
					parent = current->parent();
					// if the current node is the left child of its parent , set the parent's left child to NULL
					if (parent != NULL && parent->left() == current) {
						delete current;

						parent->setLeft(NULL);
					}
					// if the current node is the right child of its parent , set the parent's right child to NULL
					else if (parent != NULL && parent->right() == current) {
						delete current;
						parent->setRight(NULL);
					}
					--_size;
					current = parent;
				}
			}
		};

		void copy(node_type* other)
		{
			if (other == NULL)
				return;
			insert(other->getData());
			copy(other->left());
			copy(other->right());
		}


		// removing a node
		void remove(value_type& data) {
			node_type* node = _find(data);
			if (node->getData() != data)
				return;
			// if the node has no children or one child
			if (node->left() == NULL || node->right == NULL)
				_splice(node);
			else {
				// find the smallest node in the right subtree
				node_type* min = node->right();
				while (min->left() != NULL)
					min = min->left();
				// replace the data of the node with the data of the min node
				node->setData(min->getData());
				// remove the min node
				_splice(min);
			}
		}

		void insert(const value_type& data)
		{
			// if the tree is empty then add the node as the root
			if (!_root)
			{
				_root = _new_node(data, NULL);
				return;
			}
			// if node exists don't add it
			node_type* tmp = _find(data);
			if (tmp->getData() == data)
				return;
			if (tmp->getData() > data)
				tmp->setLeft(_new_node(data, tmp));
			else
				tmp->setRight(_new_node(data, tmp));
			_size++;
			_balance(tmp);
		}

		// finding a node
		const value_type& find(const value_type& data) const
		{
			node_type* tmp = _root;

			if (!tmp)
				return NULL;
			while (tmp)
			{
				if (tmp->getData() == data)
					return tmp->getData();
				if (tmp->getData() > data)
					tmp = tmp->left();
				else
					tmp = tmp->right();
			}
			return NULL;
		};

		// getters 
		int height() const { return _root->height(); }


		// traverse the tree and print the data of each node
		void print() const {
			_print(_root);
		}


	private:
		node_type* _root;
		size_t _size;

		// find that returns an address to the node , if the node doesn't exist , it returns the address of the parent	node
		node_type* _find(const value_type& data) const
		{
			node_type* tmp = _root;
			node_type* parent = NULL;

			if (!tmp)
				return NULL;
			while (tmp)
			{
				// if found return the node
				if (tmp->getData() == data)
					return tmp;
				// if not found , save the parent and go to the next node
				parent = tmp;
				// if the data is smaller than the current node , go to the left
				if (tmp->getData() > data)
					tmp = tmp->left();
				// if the data is bigger than the current node , go to the right
				else
					tmp = tmp->right();
			}
			return parent;

		};

		node_type* _new_node(const value_type& data, node_type* parent)
		{
			node_type* new_node = new node_type(data, parent);
			new_node->setLeft(NULL);
			new_node->setRight(NULL);
			return new_node;
		};

		// balance the tree
		void _balance(node_type* node) {
			// check all node's ancestors for balance factor
			node_type* tmp = node;
			while (tmp) {
				int bal = tmp->balance();

				// if tree is balanced, continue
				if (bal > -2 && bal < 2) {
					tmp = tmp->parent();
					continue;
				}
				// if tree is left heavy
				if (bal > 1) {
					// if left child is right heavy
					if (tmp->left()->balance() < 0)
						_left_rotate(tmp->left());
					_right_rotate(tmp);
				}
				// if tree is right heavy 
				else {
					// if right child is left heavy
					if (tmp->right()->balance() > 0)
						_right_rotate(tmp->right());
					_left_rotate(tmp);
				}
				tmp = tmp->parent();
			}
		}


		void _left_rotate(node_type* node) {
			node_type* right_child = node->right();
			node_type* parent = node->parent();
			node_type* right_child_left = right_child->left();
			// if node is root
			if (!parent)
				// set the right child as the root
				_root = right_child;
			else {
				// if node is left child
				if (parent->left() == node)
					// set the right child as the left child
					parent->setLeft(right_child);
				// if node is right child
				else
					// set the right child as the right child
					parent->setRight(right_child);
			}
			// set the right child's parent to the node's parent
			right_child->setParent(parent);
			// set the node's parent to the right child
			node->setParent(right_child);
			// set the right child's left child to the node
			right_child->setLeft(node);
			// set the node's right child to the right child's left child
			node->setRight(right_child_left);
			// if the right child's left child exists
			if (right_child_left)
				// set the right child's left child's parent to the node
				right_child_left->setParent(node);
		}



		void _right_rotate(node_type* node) {
			node_type* left_child = node->left();
			node_type* parent = node->parent();
			node_type* left_child_right = left_child->right();
			// if node is root
			if (!parent)
				// set the left child as the root
				_root = left_child;
			else {
				// if node is left child
				if (parent->left() == node)
					// set the left child as the left child
					parent->setLeft(left_child);
				// if node is right child
				else
					// set the left child as the right child
					parent->setRight(left_child);
			}
			// set the left child's parent to the node's parent
			left_child->setParent(parent);
			// set the node's parent to the left child
			node->setParent(left_child);
			// set the left child's right child to the node
			left_child->setRight(node);
			// set the node's left child to the left child's right child
			node->setLeft(left_child_right);
			// if the left child's right child exists
			if (left_child_right)
				// set the left child's right child's parent to the node
				left_child_right->setParent(node);
		};

		// splice a node with 0 or 1 child
		void _splice(node_type* node) {
			node_type* tmp, parent;
			// if node has left or right child
			if (node->left() != NULL)
				tmp = node->left();
			else
				tmp = node->right();
			// if node is root, set the child as the root
			if (node == _root) {
				_root = tmp;
				_root->setParent(NULL);
			}
			else {
				parent = node->parent();
				if (parent->left() == node)
					parent->setLeft(tmp);
				else
					parent->setRight(tmp);
			}
			if (tmp)
				tmp->setParent(parent);
			// delete the node
			delete node;
			--_size;
		};

		void _print(node_type* node) const {
			if (node) {
				_print(node->left());
				std::cout << node->getData() << std::endl;
				_print(node->right());
			};
		};
	};

}; // namespace ft
#endif
