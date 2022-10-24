/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:56:03 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/24 18:15:40 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @file Vector.hpp
 * @author rida ennasry
 * @brief Vector container re-implementation.
 * @date 2022/09/20
 */

// TODO: a conversion constructor and operator= for converting from iterator to const_iterator

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <reverse_iterator.hpp>
#include <choose_type.hpp>
#include <equal.hpp>
#include <lexico_compare.hpp>
namespace ft
{
  template <typename T, typename Alloc = std::allocator<T> >

  class vector
  {
  public:
    /*************** Member types ***************/

    /* elements type */
    typedef T value_type;

    /* allocator type */
    typedef Alloc allocator_type;

    /* reference to chunk of memory allocated by allocator */
    typedef typename allocator_type::reference reference;

    /* const reference to chunk of memory allocated by allocator */
    typedef typename allocator_type::const_reference const_reference;

    /* pointer to memory allocated by std::allocater */
    typedef typename allocator_type::pointer pointer;

    /* const pointer to chunk of memory allocated by allocator */
    typedef typename allocator_type::const_pointer const_pointer;

    /* difference type */
    typedef typename allocator_type::difference_type difference_type;

    /* size type */
    typedef typename allocator_type::size_type size_type;

    /******************** Iterators ********************/

    /* iterator base implementation */
    template <bool Const = false>
    class iterator_base
    {

      // protected:

    public:
      /* iterator traits */
      typedef std::random_access_iterator_tag iterator_category;
      typedef T value_type;
      typedef std::ptrdiff_t difference_type;

      typedef typename choose_type<Const, const T *, T *>::type pointer;
      typedef typename choose_type<Const, const T &, T &>::type reference;

      /* constructors & destcructors */
      inline iterator_base() : _ptr(NULL){};
      inline iterator_base(const iterator_base &other) : _ptr(other._ptr){};
      inline iterator_base<Const> &operator=(const iterator_base &other)
      {
        _ptr = other._ptr;
        return *this;
      };

      iterator_base(pointer ptr) : _ptr(ptr){};

      inline ~iterator_base(){};

      /* member functions */

      /* equality operators */
      inline bool operator==(const iterator_base<Const> &other) const
      {
        return _ptr == other._ptr;
      };
      inline bool operator!=(const iterator_base<Const> &other) const
      {
        return _ptr != other._ptr;
      };

      /* increment operators */

      /* prefix */
      // inline iterator_base& operator++() {
      //   _ptr++;
      //   return *this;
      // };

      inline iterator_base<Const> &operator++()
      {
        _ptr++;
        return *this;
      }

      /* postfix */
      inline iterator_base<Const> operator++(int)
      {
        iterator_base<Const> tmp(*this);
        operator++();
        return tmp;
      };

      /* dereferenceable */
      inline reference operator*() const { return *_ptr; };

      /* decrement operators */

      /* prefix */
      inline iterator_base<Const> &operator--()
      {
        _ptr--;
        return *this;
      };

      /* postfix */
      inline iterator_base<Const> operator--(int)
      {
        iterator_base<Const> tmp(*this);
        operator--();
        return tmp;
      };

      /* arithmetic operators */

      /* addition iterator + n */
      inline iterator_base<Const> operator+(difference_type n) const
      {
        return iterator_base<Const>(_ptr + n);
      };

      /* addition n + iterator */
      inline friend iterator_base<Const> operator+(difference_type n,
                                                   const iterator_base<Const> &it)
      {
        return iterator_base<Const>(it._ptr + n);
      };

      /* subtraction iterator - n */
      inline iterator_base<Const> operator-(difference_type n) const
      {
        return iterator_base<Const>(_ptr - n);
      };

      /* subtraction iterator - iterator */
      inline difference_type operator-(const iterator_base<Const> &other) const
      {
        return _ptr - other._ptr;
      };

      /* equality relational operators */
      inline bool operator<(const iterator_base<Const> &other) const
      {
        return _ptr < other._ptr;
      };
      inline bool operator>(const iterator_base<Const> &other) const
      {
        return _ptr > other._ptr;
      };
      inline bool operator<=(const iterator_base<Const> &other) const
      {
        return _ptr <= other._ptr;
      };
      inline bool operator>=(const iterator_base<Const> &other) const
      {
        return _ptr >= other._ptr;
      };

      /* compound assignment operators */

      inline iterator_base<Const> &operator+=(difference_type n)
      {
        _ptr += n;
        return *this;
      };

      inline iterator_base<Const> &operator-=(difference_type n)
      {
        _ptr -= n;
        return *this;
      };

      /* subscript operator */
      inline reference operator[](difference_type n) const { return _ptr[n]; };

    private:
      pointer _ptr;
    };

    typedef iterator_base<false> iterator;
    typedef iterator_base<true> const_iterator;

    typedef reverse_iterator<const_iterator> const_reverse_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;

    /************* Constructors **************/

    /* default constructor */
    explicit vector(const allocator_type &alloc = allocator_type())
    {
      this->_alloc = alloc;
      this->_size = 0;
      this->_capacity = 0;
      this->_vector = NULL;
    }

    /* fill constructor */
    explicit vector(size_type n, const value_type &val = value_type(),
                    const allocator_type &alloc = allocator_type())
    {
      this->_alloc = alloc;
      this->_size = n;
      this->_capacity = n;
      this->_vector = this->_alloc.allocate(_capacity);
      for (size_type i = 0; i < _capacity; i++)
        this->_alloc.construct(this->_vector + i, val);
    }

    /* range constructor */
    template <class InputIterator>
    vector(InputIterator first, InputIterator last,
           const allocator_type &alloc = allocator_type())
    {
      this->_alloc = alloc;
      // clearing everything
      clear();
      // getting the size of the range
      _size = last - first;
      _capacity = _size;
      // allocating memory
      _vector = _alloc.allocate(_capacity);
      for (size_type i = 0; i < _size; i++)
      {
        _alloc.construct(_vector + i, *first);
        first++;
      }
    };

    /* copy constructor */
    vector(const vector &x)
    {
      this->_alloc = x._alloc;
      this->_size = 0;
      this->_capacity = 0;
      this->assign(x.cbegin(), x.cend());
    };

    /************** Member functions *************/

    /* iterator member functions */

    iterator begin() { return iterator(this->_vector); };
    iterator end() { return iterator(this->_vector + this->_size); };

    const_iterator cbegin() const { return const_iterator(this->_vector); };
    const_iterator cend() const
    {
      return const_iterator(this->_vector + this->_size);
    };

    // reverse iterator
    reverse_iterator rbegin() { return reverse_iterator(this->end()); };
    reverse_iterator rend() { return reverse_iterator(this->begin()); };

    const_reverse_iterator crbegin() const
    {
      return const_reverse_iterator(this->cend());
    };
    const_reverse_iterator crend() const
    {
      return const_reverse_iterator(this->cbegin());
    };

    /* capacity member functions */

    // reserve
    void reserve(size_type n)
    {

      if (n > this->_capacity)
      {
        pointer tmp = this->_alloc.allocate(n);
        for (size_type i = 0; i < this->_size; i++)
          this->_alloc.construct(tmp + i, this->_vector[i]);
        if (this->_vector)
          this->_alloc.deallocate(this->_vector, this->_capacity);
        this->_vector = tmp;
        this->_capacity = n;
      }
      else
        return;
    };

    // resize
    void resize(size_type n, value_type val = value_type())
    {
      if (n > this->_size)
        insert(this->end(), n - this->_size, val);
      else if (n < this->_size)
      {
        erase(this->begin() + n, this->end());
      }
      else
        return;
    };

    size_type size() const { return this->_size; };
    size_type capacity() const { return this->_capacity; };
    bool empty() const { return this->_size == 0; };

    // max size
    size_type max_size() const
    {
      return std::numeric_limits<size_type>::max() / sizeof(value_type);
    };

    // shrink to fit
    // void shrink_to_fit() {
    //   if (this->_size == this->_capacity)
    //     return;
    //   pointer tmp = this->_alloc.allocate(this->_size);
    //   for (size_type i = 0; i < this->_size; i++)
    //     this->_alloc.construct(tmp + i, this->_vector[i]);
    //   this->_alloc.deallocate(this->_vector, this->_capacity);
    //   this->_vector = tmp;
    //   this->_capacity = this->_size;
    // };

    /* element access member functions */
    reference front() { return this->_vector[0]; };
    const_reference front() const { return this->_vector[0]; };
    reference back() { return this->_vector[this->_size - 1]; };
    const_reference back() const { return this->_vector[this->_size - 1]; };
    reference operator[](size_type n) { return this->_vector[n]; };
    const_reference operator[](size_type n) const { return this->_vector[n]; };

    value_type *data()
    {
      if (this->_size == 0)
        return NULL;
      return this->_vector;
    };
    const value_type *data() const { return this->_vector; };

    reference at(size_type n)
    {
      if (n >= this->_size)
        throw std::out_of_range("vector::at");
      return this->_vector[n];
    };

    const_reference at(size_type n) const
    {
      if (n >= this->_size)
        throw std::out_of_range("vector::at");
      return this->_vector[n];
    };

    /* modifiers member functions */

    // range assign
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last)
    {
      clear();
      insert(this->begin(), first, last);
    };

    // fill assign
    void assign(size_type n, const value_type &val)
    {
      clear();
      insert(this->begin(), n, val);
    };

    // clear
    void clear() { erase(this->begin(), this->end()); };

    // erase
    iterator erase(iterator position)
    {
      if (position == this->end())
        return position;
      // move all elements after position to the left
      for (iterator it = position; it != this->end() - 1; it++)
        *it = *(it + 1);
      this->_alloc.destroy(this->_vector + this->_size - 1);
      this->_size--;
      return position;
    };

    // erase range
    iterator erase(iterator first, iterator last)
    {
      if (first == last)
        return first;
      // get range
      size_type n = last - first;
      // move all elements after last to the left
      for (iterator it = first; it != this->end() - n; it++)
        *it = *(it + n);
      // destroy last n elements
      for (size_type i = 0; i < n; i++)
        this->_alloc.destroy(this->_vector + this->_size - 1 - i);
      this->_size -= n;
      return first;
    };

    // insert single element
    iterator insert(iterator position, const value_type &val)
    {
      if (_capacity == 0)
      {
        reserve(1);
        _alloc.construct(this->_vector, val);
        _size++;
        return position;
      }
      else if (this->_size == this->_capacity)
      {
        // get position index
        size_type index = position - this->begin();
        reserve(this->_capacity == 0 ? 1 : this->_capacity * 1.5);
        reserve(_capacity * 1.5);
        // reassign position
        position = this->begin() + index;
      }
      this->_size++;
      // move all elements after position to the right
      for (iterator it = this->end() - 1; it != position; it--)
        *it = *(it - 1);
      pointer toConstruct = this->_vector + (position - this->begin());
      this->_alloc.construct(toConstruct, val);
      return position;
    };

    // insert fill
    void insert(iterator position, size_type n, const value_type &val)
    {
      for (size_type i = 0; i < n; i++)
      {
        position = insert(position, val);
        position++;
      }
    };

    // range insert
    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last)
    {
      for (InputIterator it = first; it != last; it++)
      {
        position = insert(position, *it);
        position++;
      }
    };
    // push back
    void push_back(const value_type &val)
    {
      if (_capacity == 0)
      {
        _vector = _alloc.allocate(1);
        _alloc.construct(this->_vector, val);
        _capacity = 1;
        _size = _capacity;
        return;
      }
      insert(this->end(), val);
    };

    // pop back
    void pop_back() { erase(this->end() - 1); };

    // swap
    void swap(vector &other)
    {
      pointer tmp = this->_vector;
      this->_vector = other._vector;
      other._vector = tmp;
      size_type tmp_size = this->_size;
      this->_size = other._size;
      other._size = tmp_size;
      size_type tmp_capacity = this->_capacity;
      this->_capacity = other._capacity;
      other._capacity = tmp_capacity;
    };

    // emplace
    // emplace back
    /*** allocator member functions ***/
    allocator_type get_allocator() const { return this->_alloc; };

    /* non-member functions */
    friend bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
      if (lhs.size() != rhs.size())
        return false;
      for (size_t i = 0; i < lhs.size(); i++)
        if (lhs[i] != rhs[i])
          return false;
      return true;
    };
    friend bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
      return !(lhs == rhs);
    };

    friend bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
      for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
        if (lhs[i] < rhs[i])
          return true;
        else if (lhs[i] > rhs[i])
          return false;
      return lhs.size() < rhs.size();
    }

    friend bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
      return rhs < lhs;
    };

    friend bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
      return (lhs < rhs) || (lhs == rhs);
    };
    friend bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
      return (lhs > rhs) || (lhs == rhs);
    };
    // swap
    friend void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
      x.swap(y);
    };

  private:
    allocator_type _alloc;
    size_type _size;
    size_type _capacity;
    pointer _vector;
    // a reallocation method
    void _reallocate(size_type new_capacity)
    {
      // allocate new memory
      pointer new_vec = this->_alloc.allocate(new_capacity);
      // copy old memory to new memory
      for (size_type i = 0; i < this->_size; i++)
        this->_alloc.construct(new_vec + i, this->_vector[i]);
      // deallocate old memory
      this->_alloc.deallocate(this->_vector, this->_capacity);
      // set new memory
      this->_vector = new_vec;
      this->_capacity = new_capacity;
    }
  };
  // eeeeewf, fuck me.

} // namespace ft

#endif
