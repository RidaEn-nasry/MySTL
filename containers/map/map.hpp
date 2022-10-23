/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:48:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/23 18:35:37 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/* associative container that contains a sorted set of key-value pairs,       */
/* with unique keys. the sorting criteria is defined by the Compare class,    */
/* which defaults to less<Key>.                                               */
/* map is allocator-aware, and reversible.                                    */
/*****************************************************************************/

/// TODO:
// think about how the copy constructor of the iterator should work
// why you to put ft::AVLNode<...> and not AVLNode<...>
#ifndef MAP_HPP
#define MAP_HPP

#include <less.hpp>
#include <memory>
#include <pair.hpp>
#include <choose_type.hpp>
#include <reverse_iterator.hpp>
#include <avlnode.hpp>
#include <make_pair.hpp>

namespace ft
{

  template <class key, class T, class Compare = less<key>, class Alloc = std::allocator<pair<const key, T> > >
  class map
  {

  public:
    /************** Member types **************/

    typedef key key_type;
    typedef T mapped_type;
    typedef pair<const key, T> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::pointer pointer;
    typedef typename Alloc::const_pointer const_pointer;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;
    // value_compare class is functor adaptor so to speak,
    // it changes the behavior of the compare functor to compare keys only, (that's we want in map)
    class value_compare
    {
    public:
      typedef bool result_type;
      typedef value_type first_argument_type;
      typedef value_type second_argument_type;
      value_compare(const key_compare& c) : comp(c) {}
      bool operator()(const value_type& x, const value_type& y) const
      {
        return comp(x.first, y.first);
      };

    private:
      key_compare comp;
    };

  protected:
    /************** my Member types **************/
    // for my convenience so I don't have to type the whole thing, i'm lazy :D
    typedef ft::AVLNode<pair<const key, T>, value_compare> node_type;

  public:
    /************** Iterators **************/

    // a base implementation of the iterator, to be used by the const_iterator and iterator for sake of DRY
    template <bool Const>
    class iterator_base
    {
    public:
      /* iterator traits */
      typedef std::bidirectional_iterator_tag iterator_category;
      typedef value_type value_type;
      typedef std::ptrdiff_t difference_type;
      typedef typename choose_type<Const, const value_type*, value_type*>::type pointer;
      typedef typename choose_type<Const, const value_type&, value_type&>::type reference;

      /* constructor */
      // (1) default constructor
      iterator_base()
      {
        _current = NULL;
        _min = NULL;
        _max = NULL;
      };
      // (2) initialization constructor
      iterator_base(node_type* current, node_type* min, node_type* max)
      {
        _current = current;
        _min = min;
        _max = max;
      };
      // (3) copy constructor
      iterator_base(const iterator_base<Const>& other)
      {
        _current = other._current;
        _min = other._min;
        _max = other._max;
      };

      // copy assignment operator
      iterator_base<Const>& operator=(const iterator_base<Const>& other)
      {
        _current = other._current;
        _min = other._min;
        _max = other._max;
        return *this;
      };

      /* destructor */
      ~iterator_base() {}

      /* operators */

      // equality/inequality

      inline bool operator==(const iterator_base<Const>& other) const
      {
        return _current == other._current;
      };

      inline bool operator!=(const iterator_base<Const>& other) const
      {
        return _current != other._current;
      };

      // dereference
      inline reference operator*() const
      {
        return _current->data();
      };

      inline pointer operator->() const
      {
        return &(_current->data());
      };

      // increment/decrement

      // prefix ++
      inline iterator_base<Const>& operator++()
      {
        // ++ on end() is undefined
        if (_current == _max)
        {
          _current = NULL;
          return *this;
        }
        _current = _current->next();
        return *this;
      };

      // postfix ++
      inline iterator_base<Const> operator++(int)
      {
        iterator_base<Const> tmp(*this);
        ++(*this);
        return tmp;
      };

      // prefix --
      inline iterator_base<Const>& operator--()
      {
        // -- on begin() is undefined
        if (_current == _min)
        {
          _current = NULL;
          return *this;
        }
        _current = _current->prev();
        return *this;
      };

      // postfix --
      inline iterator_base<Const> operator--(int)
      {
        iterator_base<Const> tmp(*this);
        --(*this);
        return tmp;
      };

    private:
      // node_type* _root;
      node_type* _current;
      node_type* _max;
      node_type* _min;
    };

    typedef iterator_base<false> iterator;
    typedef iterator_base<true> const_iterator;

    typedef reverse_iterator<const_iterator> const_reverse_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;

    /************** Member functions **************/

    /* constructors */

    // (1) empty container constructor (default constructor)
    explicit map(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _alloc(alloc), _comp(comp), _node_alloc() {
      _size = 0;
      _root = NULL;
      _min = NULL;
      _max = NULL;
      // _dummy_end = NULL;
    };


    // (2) range constructor
    template <class InputIterator>
    map(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _alloc(alloc), _comp(comp), _node_alloc() {
      _size = 0;
      _root = NULL;
      _min = NULL;
      _max = NULL;
      // _dummy_end = NULL;
      insert(first, last);

      // dummy_end will be *_max->first + 1
      // _update_dummy_end();
      // _dummy_end = new node_type(value_type(_max->data().first + 1, T()), _comp);
      // _dummy_end->setParent(_max);
      // _max->setRight(_dummy_end);
    };

    // (3) copy constructor
    map(const map& x)
    {
      _comp = x._comp;
      _alloc = x._alloc;
      _root = NULL;
      _min = NULL;
      _max = NULL;
      _size = 0;
      insert(x.begin(), x.end());
    };

    /* destructor */
    ~map()
    {
      clear();
    };

    /* operator= */
    map& operator=(const map& x)
    {
      clear();
      insert(x.begin(), x.end());
      return *this;
    };

    /* iterators */
    iterator begin()
    {
      return iterator(_min, _min, _max);
    };
    const_iterator begin() const
    {
      return const_iterator(_min, _min, _max);
    };

    iterator end()
    {
      // return iterator(*_max->first + 1, )
      // return iterator(_max, _max, _min);
      // value_type val(_max->data().first + 1, T());
      // // node_type* dummy_end = _node_allocate(1);
      // // node_type
      // if (_dummy_end)
      // {
      //   value_type val = make_pair(_max->data().first + 1, _max->data().second);
      //   _dummy_end = _new_dummy_end(_dummy_end, val);
      //   _max->setRight(_dummy_end);
      //   _dummy_end->setParent(_max);
      // }
      return iterator(NULL, NULL, NULL);
      // {
      //   _node_alloc.destroy(_dummy_node);
      //   _node_alloc.deallocate(_dummy_node, 1);
      //   _dummy = 
      // }
      // return iterator(&node_type(val, _comp), _min, _max);
    };

    const_iterator end() const
    {
      return const_iterator(NULL, NULL, NULL);
    };

    reverse_iterator rbegin()
    {
      return reverse_iterator(end());
    };

    const_reverse_iterator rbegin() const
    {
      return const_reverse_iterator(end());
    };

    reverse_iterator rend()
    {
      return reverse_iterator(begin());
    };

    const_reverse_iterator rend() const
    {
      return const_reverse_iterator(begin());
    };

    /* capacity */
    bool empty() const
    {
      return _size == 0;
    };

    size_type size() const
    {
      return _size;
    };

    size_type max_size() const
    {
      return _alloc.max_size();
    };

    /* element access */
    // mapped_type &operator[](const key_type &k)
    // {
    //   // intresting stuff here
    // }

    // // at
    // mapped_type &at(const key_type &k)
    // {
    //   // intresting stuff here
    // }

    // const mapped_type &at(const key_type &k) const
    // {
    //   // intresting stuff here
    // }

    /* modifiers */

    // insert single element (1)
    pair<iterator, bool> insert(const value_type& val)
    {
      // if tree is empty, initialize it
      if (_root == NULL)
      {
        // initializing the tree
        // _root = _node_alloc.allocate(1);
        _root = _new_node(val, NULL);
        _min = _root;
        _max = _root;
        _size++;
        // _update_dummy_end();
        return make_pair(iterator(_root, _root, _root), true);
        // return pair<iterator, bool>(iterator(_root, _root, _root), true);
      };
      // else insert a new element
      pair<iterator, bool> ret = _insert(val);
      if (ret.second)
        _size++;
      return ret;
    };
    // insert witih hint (2)
    // iterator insert(iterator position, const value_type &val)
    // {
    //   // later
    // }
    // be 

    // insert range (3)
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {

      // if first == last, do nothing
      if (first == last)
        return;

      // if tree is empty, initialize it
      if (_root == NULL)
      {
        // initializing the tree
        _root = _new_node(*first, NULL);
        _min = _root;
        _max = _root;
        _size++;
        ++first;
      }

      // else insert a new element
      for (; first != last; ++first)
      {
        pair<iterator, bool> ret = _insert(*first);
        // no need to check if ret.second is true, because no duplicates are allowed but just in case...
        // a moron might try to smartass...
        if (ret.second)
          _size++;
      }
    };

    // erase single element (1)
    void erase(iterator position)
    {
      if (position == end())
        return;
      value_type& val = *position;
      // pair<const key_type, mapped_type> val(1, 'a');
      _remove(val);
      _size--;
    };

    // erase by key (2)
    size_type erase(const key_type& erase_key)
    {
      // if tree is empty, do nothing
      if (_root == NULL)
        return 0;

      // if key is not in the tree, do nothing
      node_type* node = _find(erase_key);
      if (node->data()->first != erase_key)
        return 0;

      // else remove the node
      _remove(node->data());
      _size--;
      return 1;
    };

    // erase range (3)
    void erase(iterator first, iterator last)
    {
      if (first == last)
        return;
      if (!_root)
        return;
      for (; first != last; ++first)
        erase(first);
    };

    // clear
    void clear()
    {
      if (_root == NULL)
        return;
      erase(begin(), end());
    };

  private:
    allocator_type _alloc;
    value_compare _comp;
    size_type _size;
    node_type* _root;
    node_type* _min;
    node_type* _max;
    // node_type* _dummy_end;
    // node_type* _dummy_end;
    std::allocator<node_type> _node_alloc;
    // int _balance;

    /********* private member functions *********/

    node_type* _new_node(const value_type& val, node_type* parent, node_type* left = NULL, node_type* right = NULL)
    {
      // key_compare comp();
      // value_compare compa(comp);
      node_type* new_node = _node_alloc.allocate(1);
      _node_alloc.construct(new_node, node_type(val, _comp, parent));
      new_node->setLeft(left);
      new_node->setRight(right);
      return new_node;
    };

    // _balancing the tree
    void _balance(node_type* node)
    {

      // checking balance starting from node and going up to the root
      node_type* tmp = node;
      while (tmp != _root && tmp != NULL)
      {
        int balance = tmp->balance();
        // if subtree is balanced, continue
        if (balance < 2 && balance > -2)
        {
          tmp = tmp->parent();
          continue;
        }
        // if subtree is left heavy
        else if (balance > 1)
        {
          // if subtree is left-right heavy
          if (tmp->left()->balance() < 0)
            _rotate_left(tmp->left());
          _rotate_right(tmp);
        }
        // if subtree is right-heavy
        else if (balance < -1)
        {
          // if subtree is right heavy
          if (tmp->right()->balance() > 0)
            _rotate_right(tmp->right());
          _rotate_left(tmp);
        }
        tmp = tmp->parent();
      }
    };

    void _rotate_left(node_type* node)
    {
      node_type* right = node->right();
      node_type* parent = node->parent();
      node_type* right_left = right->left();
      // if node if root
      if (!parent)
        // set the right child as root
        _root = right;
      else
      {
        // if node is left child
        if (parent->left() == node)
          // set the right child as left child
          parent->setLeft(right);
        else // if node is right child
          // set the right child as right child
          parent->setRight(right);
      }
      // set the right child's parent to node's parent
      right->setParent(parent);
      // set the right child's left child to node
      right->setLeft(node);
      // set node's parent to right child
      node->setParent(right);
      // set node's right child to right child's left child
      node->setRight(right_left);
      // if right child's left child exists
      if (right_left)
        // set right child's left child's parent to node
        right_left->setParent(node);
    };

    void _rotate_right(node_type* node)
    {
      node_type* left = node->left();
      node_type* parent = node->parent();
      node_type* left_right = left->right();

      // if node is root
      if (!parent)
        // set the left child as root
        _root = left;
      else
      {
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

    // _splicing
    void _splice(node_type* node)
    {
      node_type* tmp;
      // if node has a left/right child
      if (node->left())
        tmp = node->left();
      else // either actuall node or NULL
        tmp = node->right();
      // if node is root, set the child as root
      if (!node->parent())
        _root = tmp;
      else
      {
        // if node is left child of it's parent
        if (node->parent()->left() == node)
          // set the child as left child
          node->parent()->setLeft(tmp);
        else // either right child or NULL
          // set the child as right child
          node->parent()->setRight(tmp);
      }
      // if node has a child, set it's parent to node's parent,
      // if it's NULL, don't segfault yourself
      if (tmp)
        tmp->setParent(node->parent());
      _node_alloc.destroy(node);
      _node_alloc.deallocate(node, 1);
      // return tmp;
    };
    // minimum
    // finding min and max with help old min/max, which reduces TC to O(1)
    node_type* _minimum()
    {
      if (!_root)
        return NULL;
      node_type* old_min = _min;
      if (old_min == NULL)
        // in case it's been removed let's start from the root
        old_min = _root;
      while (old_min->left())
      {
        old_min = old_min->left();
      }
      _min = old_min;
      return old_min;
    };

    // maximum
    node_type* _maximum()
    {
      if (!_root)
        return NULL;
      node_type* old_max = _max;
      if (!old_max)
        // it might be removed, so we need to find it again
        old_max = _root;
      while (old_max->right() != NULL)
        old_max = old_max->right();
      _max = old_max;
      // updating _dummy_end 
      // _dummy_end = _node_alloc.allocate(1);
      // value_type val = make_pair(_max->data().first + 1, _max->data().second);
      // _node_alloc.construct(_dummy_end, node_type(val, _comp, _max));
      // _max->setRight(_dummy_end);
      // _dummy_end->setParent(_max);
      return old_max;
    };

    // _finding
    node_type* _find(const value_type& val)
    {
      node_type* node = _root;
      node_type* parent = NULL;
      // returning node or the closest node a.k.a parent
      while (node != NULL)
      {
        parent = node;
        if (_comp(val, node->data()))
          node = node->left();
        else if (_comp(node->data(), val))
          node = node->right();
        else
          return node;
      }
      return parent;
    }
    // _inserting
    pair<iterator, bool> _insert(const value_type& val)
    {
      // neat insert
      node_type* node = _root;
      // return node or the closest node a.k.a parent
      node = _find(val);

      // if node exist return an iterator to it.
      if (!_comp(node->data(), val) && !_comp(val, node->data()))
      {
        return make_pair(iterator(node, _min, _max), false);
      }
      node_type* new_node = _new_node(val, node);
      if (_comp(val, node->data()))
        // if smaller than it's parent, insert it to the left
        node->setLeft(new_node);
      else
        // if greater insert to the right
        node->setRight(new_node);
      // check tree balance
      _balance(node);
      // update min and max
      _max = _maximum();
      _min = _minimum();

      // updating dummy end
      // _update_dummy_end();
      // return iterator to the new node
      return make_pair(iterator(new_node, _min, _max), true);
    };

    // _removing
    void _remove(const value_type& data)
    {
      node_type* node = _find(data);
      // if node doesn't exist return NULL
      // if node->data is not equal to data return NULL
      if (_comp(node->data(), data) || _comp(data, node->data()))
        return;
      // if node has no children or only one child
      if (node->left() == NULL || node->right() == NULL)
        _splice(node);
      else
      {
        // find the smallest node in the right subtree
        node_type* min = node->right();
        while (min->left() != NULL)
          min = min->left();
        // exchange node's stuff
        // we should create a new node as we can't really change the key as it is const
        node_type* tmp_node = _new_node(min->data(), node->parent(), node->left(), node->right());
        // then we need to change min stuff's too
        // if it's has a right child, set it as left to it's parent
        if (min->right())
        {
          min->parent()->setLeft(min->right());
          min->right()->setParent(min->parent());
        }
        // delete the old node
        _node_alloc.destroy(node);
        _node_alloc.deallocate(node, 1);
        // set the new node
        node = tmp_node;
        // node->setData(min->data());
        // remove the smallest node
        _splice(min);
      }
      // check tree balance
      _balance(node);

      // update _dummy_end
      // _update_dummy_end();
      // update min and max
      _max = _maximum();
      _min = _minimum();
    };

    // node_type* _new_dummy_end(node_type* old_dummy_end, value_type val) {
    //   // _node_alloc.destroy(old_dummy_end);
    //   // _node_alloc.deallocate(old_dummy_end, 1);
    //   old_dummy_end = _node_alloc.allocate(1);
    //   _node_alloc.construct(old_dummy_end, node_type(val, _comp));
    //   return old_dummy_end;
    // }
    // void _update_dummy_end() {
    //   if (!_dummy_end)
    //     _dummy_end = _new_node(value_type(_max->data().first + 1, _max->data().second), _max);
    //   else if (_max->data().first + 1 != _dummy_end->data().first)
    //   {
    //     //   _node_alloc.destroy(_dummy_end);
    //     //   _node_alloc.deallocate(_dummy_end, 1);
    //     _dummy_end = _new_node(value_type(_max->data().first + 1, _max->data().second), _max);
    //   }
    //   _max->setRight(_dummy_end);
    //   _dummy_end->setParent(_max);
    // }
  }; // map class

}; // ft namespace

#endif