/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:12:40 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/16 20:34:45 by ren-nasr         ###   ########.fr       */
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
			// clear the tree and then copy the other tree
			clear();
			// _root = copy(other._root);
			// _size = other._size;
			// return *this;
		}

		void clear() {
			node_type* tmp = _root;


		};

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
			// balance factor checking 
			// size_t bal = _root->balance();
			// if (bal > 2 || bal < -2)
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
				// if tree is left heavy
				if (bal > 1) {
					// if the left child is right heavy
					if (tmp->left()->balance() < 0)
						_left_rotate(tmp->left());
					_right_rotate(tmp);
				}
				// if tree is right heavy
				else if (bal < -1) {
					// if the right child is left heavy
					if (tmp->right()->balance() > 0)
						_right_rotate(tmp->right());
					_left_rotate(tmp);
				}
				tmp = tmp->parent();
			}
		};

		void _left_rotate(node_type* node) {
			// if node is the root
			if (!node->parent()) {
				// set the new root
				_root = node->right();
				_root->setParent(NULL);
			}
			// if node is not the root
			else {
				// if node is the left child of its parent, set node's right child as the left child of its parent
				if (node->parent()->left() == node)
					node->parent()->setLeft(node->right());
				// if node is the right child of its parent
				else
					node->parent()->setRight(node->right());
				// set the new parent of the right child
				node->right()->setParent(node->parent());
			}
			// set the new right child of the node
			node->setRight(node->right()->left());
			// set the new parent of the new right child
			if (node->right())
				node->right()->setParent(node);
			// set the new left child of the node
			node->setLeft(node);
			// set the new parent of the node
			node->setParent(node->left());
		};

		void _right_rotate(node_type* node) {
			// if node is the root
			if (!node->parent()) {
				// set the new root
				_root = node->left();
				_root->setParent(NULL);
			}
			// if node is not the root
			else {
				// if node is the left child of its parent
				if (node->parent()->left() == node)
					node->parent()->setLeft(node->left());
				// if node is the right child of its parent
				else
					node->parent()->setRight(node->left());
				// set the new parent of the left child
				node->left()->setParent(node->parent());
			}
			// set the new left child of the node
			node->setLeft(node->left()->right());
			// set the new parent of the new left child
			if (node->left())
				node->left()->setParent(node);
			// set the new right child of the node
			node->setRight(node);
			// set the new parent of the node
			node->setParent(node->right());
		};
	};
}; // namespace ft
#endif
