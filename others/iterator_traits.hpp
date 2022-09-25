

template < class Iter >
struct iterator_triats {
  typedef typename Iter::value_type value_type;
  typedef typename Iter::difference_type difference_type;
  typedef typename Iter::pointer pointer;
  typedef typename Iter::reference reference;
  typedef typename Iter::iterator_category iterator_category;
};

