/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:12:40 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/16 12:46:02 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implementation of AVL tree as a templated class. */

// should the avl class be implmented as node or a class wrapper that manages
// the node

// balancing will happen when we try to insert a node in the tree

#ifndef AVL_HPP
#define AVL_HPPavlnode

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
		typedef T value_type;

		// default constructor
		AVLTree() : _root(NULL), _size(0) {}

		// initializing constructor
		explicit AVLTree(const value_type &data)
		{
			_root = new node_type;
			_root->setData(data);
			_root->setParent(NULL);
			_root->setLeft(NULL);
			_root->setRight(NULL);
			_size = 1;
		}

		AVLTree(const AVLTree<T> &other) { *this = other; }

		AVLTree<T> &operator=(const AVLTree<T> &other)
		{
			// clear the tree and then copy the other tree
			// clear();
			// _root = copy(other._root);
			// _size = other._size;
			// return *this;
		}

		void clear(){

		};

		void add(const value_type &data)
		{
			if (!_root)
				node_type *tmp = _find(data);
			if (tmp->getData() == data)
				return;
			else if (tmp->getData() > data)
			{
				node_type *right = tmp->right();
				right = _new_node(data, tmp);
			}
			else if (tmp->getData() < data)
			{
				node_type *left = tmp->left();
				left = _new_node(data, tmp);
			}
		}

		// finding a node
		const value_type &find(const value_type &data) const
		{
			node_type *tmp = _root;
			if (!tmp)
				return NULL;
			while (tmp)
			{
				value_type tmp_data = tmp->getData();
				if (data > tmp_data)
					tmp = tmp->right();
				else if (data < tmp_data)
					tmp = tmp->left();
				else
					return tmp->getData();
			}
			node_type *parent = tmp->parent();
			return parent->getData();
		};

	private:
		node_type *_root;
		size_t _size;

		// find that returns an address
		void _find(const value_type &data) const
		{
			node_type *tmp = _root;
			while (tmp)
			{
				value_type tmp_data = tmp->getData();
				if (data > tmp_data)
					tmp = tmp->right();
				else if (data < tmp_data)
					tmp = tmp->left();
				else
					return tmp;
			}
			return tmp->parent();
		};

		node_type *_new_node(const value_type &data, node_type *parent)
		{
			node_type *new_node = new node_type;
			new_node->setData(data);
			new_node->setParent(parent);
			new_node->setLeft(NULL);
			new_node->setRight(NULL);
			return new_node;
		};

	} // namespace ft
#endif
