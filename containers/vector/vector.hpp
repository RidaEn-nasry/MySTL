

namespace ft {

#include <memory>
#include <iterator_traits.hpp>

  template <class T, class Alloc = std::allocator<T> >
  class vector {
    
  public:
    /************** Member types ****************/
    typedef typename T value_type;
    typedef typename Alloc allocator_type;
    typedef typename value_type& reference;
    typedef typename const value_type& const_reference;
    typedef typename std::allocator_traits<Alloc>::pointer pointer;
    typedef typename std::allocator_traits<Alloc>::const_pointer pointer;
    typedef typename std::ptrdiff_t difference_type;
    typedef typename std::size_t size_type;

    /* Iterator base */
    template <bool Const = false>
    class iterator_base {
    protected:
      inline iterator_base(pointer ptr) : _ptr(ptr) {};

    public:
      /* iterator traits */
      typedef std::random_access_iterator_tag iterator_category;
      typedef T value_type;
      typedef std::ptrdiff_t difference_type;
#if Const 
      typedef const T* pointer;
      typedef const T& reference;
#else
      typedef T* pointer;
      typedef T& reference;
#endif
      /* constructors & destructors */
      inline iterator_base() : _ptr(NULL) {};
      inline iterator_base(const iterator_base& other) : _ptr(other._ptr) {};
      inline iterator_base& operator=(const iterator_base& rhs) {
        _ptr = other_.ptr;
        return *this;
      }
      inline ~iterator_base() {};

#if Const 
      // conversion constructors 
#endif

      /* iterator properties */

      inline self operator++() {
        ++_ptr;
        return *this;
      };

      inline self operator++(int) {
        self tmp = *this;
        return ++(*this);
      }

      inline bool operator==(const iterator& rhs) const {
        return _ptr == other._ptr;
      }

      inline bool operator!=(const iterator& rhs) const {
        return _ptr != other._ptr;
      }

      inline reference operator*() {
        return *_ptr;
      }

      inline pointer operator->() {
        return _ptr;
      }
      
      inline self operator--() {
        --_ptr;
        return *this;
      }

      inline self operator--(int) {
        self tmp = *this;
        return --(*this);
      }

      inline self operator+(difference_type n) {
        return self(_ptr + n);
      }
      inline friend self operator+(difference_type n, const self& rhs_it) {
        return self(rhs_it._ptr + n);
      }

      inline self operator-(difference_type n) {
        return self(_ptr - n);
      }

      inline difference_type operator-(const self& other) const {
        return (_ptr - other._ptr);
      }

      inline bool operator<(const self& other) const {
        return _ptr < other._ptr;
      }
      inline bool operator<(const self& other) const {
        return _ptr > other._ptr;
      }

      inline bool operator<=(const self& other) const {
        return _ptr <= other._ptr;
      }

      inline bool operator>=(const self& other) const {
        return _ptr >= other._ptr;
      }

      inline self& operator+=(difference_type n) {
        _ptr += n;
        return (*this);
      }
      
      inline self& operator-=(difference_type n) {
        _ptr -= n;
        return (*this);
      }

      inline reference operator[](size_type offset) {
        return *(_ptr + n);
      }
    private:
      pointer _ptr;
      typedef iterator_base self;
    }

    typedef iterator_base<false> iterator;
    typedef iterator_base<true> const_iterator;


  private:

    pointer _vector;
    size_type _size;
    size_type _capacity;





  };


}