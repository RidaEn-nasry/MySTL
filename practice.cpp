
#include <iostream>

template <typename T, typename Alloc = std::allocator<T> >
class vector {
public:
  typedef T value_type;
  typedef Alloc allocator_type;
 
};
int main ( void )
{


  //vector<int> v;
  vector<int>::allocator_type alloc;
  std::cout << "allocator type is : " << typeid(alloc).name() << std::endl;
  return 0;
   
}

			
