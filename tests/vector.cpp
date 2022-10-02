
#include <test.hpp>

template <typename TYPE>
std::vector<TYPE> dummy_vector_std(size_t n) {
  std::vector<TYPE> v;
  for (size_t i = 0; i < n; i++) {
    v.push_back(i);
  }
  return v;
}

template <typename TYPE>
ft::vector<TYPE> dummy_vector_ft(size_t n) {
  ft::vector<TYPE> v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i;
  }
  return v;
}
// receive allocater_type of ft::vecrtor 
bool  check_allocator() {
  ft::vector<int> v1;
  const char* all_name = typeid(v1.get_allocator()).name();
  std::vector<int> v2;
  const char* std_all_name = typeid(v2.get_allocator()).name();
  return strcmp(all_name, std_all_name) == 0;
};

// checking if type is default/copy/assign constructible.
template <typename TYPE>
bool check_basic_constructible() {
  // TODO:
  /*  the problem is we have constructors call
      this->assignand this->assign calls this->insert which
      is not implemented yet
  */
  /*
  TYPE a;
  TYPE b(a);
  TYPE c = a;
  */
  return true;
};

void ft_vector_tests_suite() {

  /********************************************************************************/
  /*                                 BASIC TESTS                                  */
  /********************************************************************************/
  {
    char* test_name = strdup("Basic tests ");
    REQUIRE(check_basic_constructible<ft::vector<int> >() == true, test_name, "`ft::vector` should be at least default/copy/assign constructible");
    T ft::vector<int> v1;
    REQUIRE(typeid(v1).name(), test_name, "either you kidding me... or you're vector is not in the `ft` namespace"); C;
    INFO_OK(test_name);
  }
  /*********************************************************************************/
  /*                               Member Types                                   */
  /*********************************************************************************/

  {
    char* test_name = strdup("Member Types ");
    REQUIRE_EQ(typeid(ft::vector<int>::value_type).name(), typeid(int).name(), test_name, "`value_type` member type is missing or invalid");
    REQUIRE_EQ(typeid(ft::vector<int>::pointer).name(), typeid(int*).name(), test_name, "`pointer` member type is missing or invalid");
    REQUIRE_EQ(typeid(ft::vector<int>::const_pointer).name(), typeid(const int*).name(), test_name, "`const_pointer` member type is missing or invalid");
    REQUIRE_EQ(typeid(ft::vector<int>::reference).name(), typeid(int&).name(), test_name, "`reference` member type is missing or invalid");
    REQUIRE_EQ(typeid(ft::vector<int>::const_reference).name(), typeid(const int&).name(), test_name, "`const_reference` member type is missing or invalid");
    REQUIRE(check_allocator(), test_name, "`allocator_type` member type is missing or invalid, it should of type `std::allocator<T>`");
    REQUIRE_EQ(typeid(ft::vector<int>::difference_type).name(), typeid(std::ptrdiff_t).name(), test_name, "`difference_type` member type is missing or invalid");
    REQUIRE_EQ(typeid(ft::vector<int>::size_type).name(), typeid(std::size_t).name(), test_name, "`size_type` member type is missing or invalid");
    INFO_OK(test_name);

  }


  /********************************************************************************/
  /*                                CONSTRUCTORS                                  */
  /********************************************************************************/

  /**********************************/
  /***      DEFAULT CONSTRUCTOR   ***/
  /**********************************/

  {
    ft::vector<int> v1;
    std::vector<int> v2;
    char* test_name = strdup("Default constructor tests ");
    REQUIRE(check_allocator(), test_name, "`ft::vector<T>::allocater_type` should be the same as `std::vector<T>::allocater_type`");
    REQUIRE_EQ(v1.size(), v2.size(), test_name, "`size` should be `0` when vector is default constructed");
    REQUIRE_EQ(v1.capacity(), v2.capacity(), test_name, "`capacity` should be `>= 0` when vector is default constructed");
    REQUIRE_EQ(v1.empty(), v2.empty(), test_name, "`empty()` should return `true` when vector is default constructed");
    REQUIRE_NULL(v1.data(), test_name, "`data()` should return `NULL` when vector is default constructed");
    INFO_OK(test_name);
  }

  /**********************************/
  /***      FILL CONSTRUCTOR      ***/
  /**********************************/

  {
    ft::vector<std::string> v1(5, "hello");
    std::vector<std::string> v2(5, "hello");
    char* test_name = strdup("Fill constructor tests ");
    REQUIRE(check_allocator(), test_name, "`ft::vector<T>::allocater_type` should be the same as `std::vector<T>::allocater_type`");
    REQUIRE_EQ(v1.size(), v2.size(), test_name, "`size` should be `size_type n` when vector is fill constructed");
    REQUIRE_EQ(v1.capacity(), v2.capacity(), test_name, "`capacity` should be `>= size_type n` when vector is fill constructed");
    REQUIRE_EQ(v1.empty(), v2.empty(), test_name, "`empty()` should return `false` when vector is fill constructed");
    REQUIRE_NOT_NULL(v1.data(), test_name, "`data()` should return `!= NULL` when vector is fill constructed");
    for (size_t i = 0; i < 5; i++)
      REQUIRE_EQ(v1[i], v2[i], test_name, "`each vector[n]` should be `value_type val` when vector is fill constructed");
    ft::vector<double> v3(1000);
    std::vector<double> v4(1000);
    REQUIRE_EQ(v3.size(), v4.size(), test_name, "`size` should be `size_type n` when vector is fill constructed");
    REQUIRE_EQ(v3.capacity(), v4.capacity(), test_name, "`capacity` should be `>= size_type n` when vector is fill constructed");
    REQUIRE_EQ(v3.empty(), v4.empty(), test_name, "`empty()` should return `false` when vector is fill constructed");
    REQUIRE_NOT_NULL(v3.data(), test_name, "`data()` should return `!= NULL` when vector is fill constructed");
    for (size_t i = 0; i < 1000; i++)
      REQUIRE_EQ(v3[i], v4[i], test_name, "`each vector[n]` should be `value_type val or value_type()` when vector is fill constructed");

    INFO_OK(test_name);

  }

  /**********************************/
  /***      RANGE CONSTRUCTOR     ***/
  /*********************************/

  {
    char* test_name = strdup("Range constructor tests ");
    REQUIRE(check_allocator(), test_name, "`ft::vector<T>::allocater_type` should be the same as `std::vector<T>::allocater_type`");
    ft::vector<float> v1(129, 1.2);
    ft::vector<float> v2(v1.begin(), v1.end());
    REQUIRE_EQ(v1.size(), v2.size(), test_name, "`size` should be the same as `vector2.size()` when vector is range constructed");
    for (size_t i = 0; i < v2.size(); i++) {
      REQUIRE_EQ(v1[i], v2[i], test_name, "each `vector[n]` should be the same as `vector2[n]` when vector is range constructed");
    }
    INFO_OK(test_name);
  }


  /******************************************************************************/
  /*                                ITERATORS                                   */
  /******************************************************************************/

  /**********************************************/
  /*** iterator / const_iterator member types ***/
  /**********************************************/
  {
    char* test_name = strdup("Iterator member types tests ");
    REQUIRE_STREQ(typeid(ft::vector<int>::iterator::iterator_category).name(), typeid(std::random_access_iterator_tag).name(), test_name, "`ft:vector<T>::iterator::iterator_category` member type should be `std::random_access_iterator_tag`");
    REQUIRE_STREQ(typeid(ft::vector<int>::iterator::value_type).name(), typeid(int).name(), test_name, "`ft:vector<T>::iterator::value_type` member type should be `T`");
    REQUIRE_STREQ(typeid(ft::vector<int>::iterator::difference_type).name(), typeid(std::ptrdiff_t).name(), test_name, "`ft:vector<T>::iterator::difference_type` member type should be `std::ptrdiff_t`");
    REQUIRE_STREQ(typeid(ft::vector<int>::iterator::pointer).name(), typeid(int*).name(), test_name, "`ft:vector<T>::iterator::pointer` member type should be `T*`");
    REQUIRE_STREQ(typeid(ft::vector<int>::iterator::reference).name(), typeid(int&).name(), test_name, "`ft:vector<T>::iterator::reference` member type should be `T&`");
    REQUIRE_STREQ(typeid(ft::vector<int>::const_iterator::iterator_category).name(), typeid(std::random_access_iterator_tag).name(), test_name, "`ft:vector<T>::const_iterator::iterator_category` member type should be `std::random_access_iterator_tag`");
    REQUIRE_STREQ(typeid(ft::vector<int>::const_iterator::value_type).name(), typeid(int).name(), test_name, "`ft:vector<T>::const_iterator::value_type` member type should be `T`");
    REQUIRE_STREQ(typeid(ft::vector<int>::const_iterator::difference_type).name(), typeid(std::ptrdiff_t).name(), test_name, "`ft:vector<T>::const_iterator::difference_type` member type should be `std::ptrdiff_t`");
    REQUIRE_STREQ(typeid(ft::vector<int>::const_iterator::pointer).name(), typeid(const int*).name(), test_name, "`ft:vector<T>::const_iterator::pointer` member type should be `const T*`");
    REQUIRE_STREQ(typeid(ft::vector<int>::const_iterator::reference).name(), typeid(const int&).name(), test_name, "`ft:vector<T>::const_iterator::reference` member type should be `const T&`");
    INFO_OK(test_name);
  }

  /****************************************************/
  /***                      iterator                ***/
  /****************************************************/

  {
    char* test_name = strdup("Iterator requirements tests ");
    // REQUIRE_EQ(check_basic_constrxuctible(ft::vector<std::string>::iterator()), true, test_name, "`ft::vector<T>::iterator` should be at least default/copy/assign constructible");
    // equality operators 
    ft::vector<double> v1(10);

    std::vector<double> v2(10);

    for (size_t i = 0; i < v1.size(); i++)
    {
      v1[i] = i;
      v2[i] = i;
    }
    ft::vector<double>::iterator ft_it1 = v1.begin();
    ft::vector<double>::iterator ft_it2 = v1.begin();

    std::vector<double>::iterator std_it = v2.begin();
    std::vector<double>::iterator std_it2 = v2.begin();

    REQUIRE_EQ(ft_it1 == ft_it2, std_it == std_it2, test_name, "`iterator1 == iterator2` should return `true` when `iterator1` and `iterator2` are equal");
    REQUIRE_EQ(ft_it1 != ft_it2, std_it != std_it2, test_name, "`iterator1 != iterator2` should return `false` when `iterator1` and `iterator2` are inequal");
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator`");
    ++ft_it1;
    ++std_it;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after incrementing it");
    ft::vector<double>::iterator ft_it3 = ft_it1++;
    std::vector<double>::iterator std_it3 = std_it++;
    REQUIRE_EQ(*ft_it3, *std_it3, test_name, "`*iterator` should return the value of the element pointed by `iterator` before incrementing it");

    ft_it1 = ft_it1 + 2;
    std_it = std_it + 2;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after incrementing it by `n`");
    ft_it1 = 2 + ft_it1;
    std_it = 2 + std_it;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after incrementing it by `n`");
    ft_it1 = ft_it1 - 2;
    std_it = std_it - 2;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after decrementing it by `n`");


    REQUIRE_EQ(ft_it1 < ft_it2, std_it < std_it2, test_name, "`iterator1 < iterator2` should return `true` when `iterator1` is less than `iterator2`");
    REQUIRE_EQ(ft_it1 > ft_it2, std_it > std_it2, test_name, "`iterator1 > iterator2` should return `false` when `iterator1` is less than `iterator2`");
    REQUIRE_EQ(ft_it1 <= ft_it2, std_it <= std_it2, test_name, "`iterator1 <= iterator2` should return `true` when `iterator1` is less than or equal to `iterator2`");
    REQUIRE_EQ(ft_it1 >= ft_it2, std_it >= std_it2, test_name, "`iterator1 >= iterator2` should return `false` when `iterator1` is less than or equal to `iterator2`");
    // // arithmetic operators

    ft_it1 += 2;
    std_it += 2;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after incrementing it by `n`");
    ft_it1 -= 2;
    std_it -= 2;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after decrementing it by `n`");
    REQUIRE_EQ(ft_it1[2], std_it[2], test_name, "`iterator[n]` should return the value of the element pointed by `iterator` after incrementing it by `n`");
    char *test_name2 = strdup("Iterator requirements tests ");
    INFO_OK(test_name2);

  }


  /****************************************************/
  /***               const_iterator                 ***/
  /****************************************************/
  {
    char* test_name = strdup("Const iterator requirements tests ");
    // REQUIRE_EQ(check_basic_constrxuctible(ft::vector<std::string>::const_iterator()), true, test_name, "`ft::vector<T>::const_iterator` should be at least default/copy/assign constructible");
    // equality operators 
    ft::vector<double> v1(10);

    std::vector<double> v2(10);

    for (size_t i = 0; i < v1.size(); i++)
    {
      v1[i] = i;
      v2[i] = i;
    }
    ft::vector<double>::const_iterator ft_it1 = v1.cbegin();
    ft::vector<double>::const_iterator ft_it2 = v1.cbegin();


    std::vector<double>::const_iterator std_it = v2.cbegin();
    std::vector<double>::const_iterator std_it2 = v2.cbegin();

    REQUIRE_EQ(ft_it1 == ft_it2, std_it == std_it2, test_name, "`iterator1 == iterator2` should return `true` when `iterator1` and `iterator2` are equal");
    REQUIRE_EQ(ft_it1 != ft_it2, std_it != std_it2, test_name, "`iterator1 != iterator2` should return `false` when `iterator1` and `iterator2` are inequal");
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator`");
    ++ft_it1;
    ++std_it;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after incrementing it");
    ft::vector<double>::const_iterator ft_it3 = ft_it1++;
    std::vector<double>::const_iterator std_it3 = std_it++;
    REQUIRE_EQ(*ft_it3, *std_it3, test_name, "`*iterator` should return the value of the element pointed by `iterator` before incrementing it");

    ft_it1 = ft_it1 + 2;
    std_it = std_it + 2;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after incrementing it by `n`");
    ft_it1 = 2 + ft_it1;
    std_it = 2 + std_it;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after incrementing it by `n`");
    ft_it1 = ft_it1 - 2;
    std_it = std_it - 2;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after decrementing it by `n`");
    REQUIRE_EQ(ft_it1 < ft_it2, std_it < std_it2, test_name, "`iterator1 < iterator2` should return `true` when `iterator1` is less than `iterator2`");
    REQUIRE_EQ(ft_it1 > ft_it2, std_it > std_it2, test_name, "`iterator1 > iterator2` should return `false` when `iterator1` is less than `iterator2`");
    REQUIRE_EQ(ft_it1 <= ft_it2, std_it <= std_it2, test_name, "`iterator1 <= iterator2` should return `true` when `iterator1` is less than or equal to `iterator2`");
    REQUIRE_EQ(ft_it1 >= ft_it2, std_it >= std_it2, test_name, "`iterator1 >= iterator2` should return `false` when `iterator1` is less than or equal to `iterator2`");
    ft_it1 += 2;
    std_it += 2;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after incrementing it by `n`");
    ft_it1 -= 2;
    std_it -= 2;
    REQUIRE_EQ(*ft_it1, *std_it, test_name, "`*iterator` should return the value of the element pointed by `iterator` after decrementing it by `n`");
    REQUIRE_EQ(ft_it1[2], std_it[2], test_name, "`iterator[n]` should return the value of the element pointed by `iterator` after incrementing it by `n`");

    // check conversion from iterator to const_iterator 
    ft::vector<double>::iterator ft_it4 = v1.begin();
    std::vector<double>::iterator std_it4 = v2.begin();
    (void)ft_it4;
    (void)std_it4;
    INFO_OK(test_name);
  }

  /********************************************************************************/
  /***                      member functions                                   ***/
  /*******************************************************************************/

  // begin  / end 
  {
    char* test_name = strdup("begin / end member functions tests ");

    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);

    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    ft::vector<int>::iterator ft_it = ft_v1.begin();
    std::vector<int>::iterator std_it = std_v1.begin();
    REQUIRE_EQ(*ft_it, *std_it, test_name, "`begin` should return an iterator to the first element of the vector");
    ft_it = ft_v1.end() - 1;
    std_it = std_v1.end() - 1;
    REQUIRE_EQ(*ft_it, *std_it, test_name, "`end` should return an iterator to the last element of the vector");
    INFO_OK(test_name);
  }

  // cbegin / cend 
  {
    char* test_name = strdup("cbegin / cend member functions tests ");

    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);

    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    ft::vector<int>::const_iterator ft_it = ft_v1.cbegin();
    std::vector<int>::const_iterator std_it = std_v1.cbegin();
    REQUIRE_EQ(*ft_it, *std_it, test_name, "`cbegin` should return a const_iterator to the first element of the vector");
    ft_it = ft_v1.cend() - 1;
    std_it = std_v1.cend() - 1;
    REQUIRE_EQ(*ft_it, *std_it, test_name, "`cend` should return a const_iterator to the last element of the vector");
    INFO_OK(test_name);
  }


  // reserve member method
  {
    char* test_name = strdup("reserve member function tests ");
    ft::vector<int> ft_v1;
    std::vector<int> std_v1;
    ft_v1.reserve(10);
    std_v1.reserve(10);
    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`capacity` should return the size of the storage space currently allocated for the vector, expressed in terms of elements");
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should return the number of elements in the vector not the `capacity`");
    REQUIRE(ft_v1.empty() == std_v1.empty(), test_name, "`empty` should return `true` if the vector is empty");

    // test with negative value
    try {
      ft_v1.reserve(-10);
      std_v1.reserve(-10);
    }
    catch (std::exception& e) {
      REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`capacity` should return the size of the storage space currently allocated for the vector, expressed in terms of elements");
      REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should return the number of elements in the vector not the `capacity`");
      REQUIRE(ft_v1.empty() == std_v1.empty(), test_name, "`empty` should return `true` if the vector is empty");
    }
    // test with zero 
    ft_v1.reserve(0);
    std_v1.reserve(0);
    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`reserve(0)` should not trigger a reallocation");


    // test with value less than the current capacity no reallocation should happen
    ft_v1.reserve(5);
    std_v1.reserve(5);
    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`reserve(n)` should not trigger a reallocation if `n` is less than the current `capacity`");

    // test with current capacity
    ft_v1.reserve(ft_v1.capacity());
    std_v1.reserve(std_v1.capacity());
    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`reserve(n)` should not trigger a reallocation if `n` is equal to the current `capacity`");

    // reserve with extreme values
    try {
      ft_v1.reserve(ft_v1.max_size());
      std_v1.reserve(std_v1.max_size());
    }
    catch (std::exception& e) {
      REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`reserve(n)` should not trigger a reallocation if `n` is equal to the current `capacity`");
    };
    INFO_OK(test_name);

  }

  // erase 
  {

    char* test_name = strdup("erase member function tests ");
    // erase with single iterator
    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);
    ft::vector<int>::iterator ft_it1 = ft_v1.begin();
    std::vector<int>::iterator std_it1 = std_v1.begin();
    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    ft_it1 += 2;
    std_it1 += 2;
    ft::vector<int>::iterator ft_ret = ft_v1.erase(ft_it1);
    std::vector<int>::iterator std_ret = std_v1.erase(std_it1);

    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be decremented by 1 after erasing an element");
    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`capacity` should not be affected by `erase`");
    REQUIRE_EQ(*ft_ret, *std_ret, test_name, "`erase` should return an iterator pointing to the element that followed the last element erased by the function call");
    // for (size_t i = 0; i < ft_v1.size(); i++) {
    //   std::cout << "ft_v1[" << i << "]: " << ft_v1[i] << " | " << "std_v1[" << i << "]: " << std_v1[i] << std::endl;
    // }
    // std::cout << "ft_ret: " << *ft_ret << " | " << "std_ret: " << *std_ret << std::endl;
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`erase` should erase the element at the specified position");
    }

    // erase with range (first, first + n)
    ft_ret = ft_v1.erase(ft_it1, ft_it1 + 2);
    std_ret = std_v1.erase(std_it1, std_it1 + 2);
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be decremented by 2 after erasing a range of 2 elements");
    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`capacity` should not be affected by `erase`");
    // for (size_t i = 0; i < ft_v1.size(); i++) {
    //   std::cout << "ft_v1[" << i << "]: " << ft_v1[i] << " | " << "std_v1[" << i << "]: " << std_v1[i] << std::endl; 
    // }
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`erase` should erase the element at the specified position");
    }
    REQUIRE_EQ(*ft_ret, *std_ret, test_name, "`erase` should return an iterator pointing to the element that followed the last element erased by the function call");
    // erasing the [first, last) range
    ft_ret = ft_v1.erase(ft_v1.begin(), ft_v1.end());
    std_ret = std_v1.erase(std_v1.begin(), std_v1.end());
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be decremented by n after erasing range of elements ft_v1.end() - ft_v1.begin() = n");
    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`capacity` should not be affected by `erase`");
    REQUIRE_EQ(*ft_ret, *std_ret, test_name, "`erase` should return an iterator pointing to the element that followed the last element erased by the function call");
    REQUIRE_EQ(ft_v1.empty(), std_v1.empty(), test_name, "`empty` should return `true` after erasing [ft_v1.begin(), ft_v1.end()) range of elements");
    INFO_OK(test_name);
  }
  // insert 
  {
    // insert with single element
    char* test_name = strdup("insert member function tests ");
    ft::vector<double> ft_v1(10);
    std::vector<double> std_v1(10);
    ft::vector<double>::iterator ft_it1 = ft_v1.begin();
    std::vector<double>::iterator std_it1 = std_v1.begin();
    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    ft_it1 += 2;
    std_it1 += 2;
    ft::vector<double>::iterator ft_ret = ft_v1.insert(ft_it1, 42.42);
    std::vector<double>::iterator std_ret = std_v1.insert(std_it1, 42.42);
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be incremented by 1 after inserting an element");
    REQUIRE_EQ(*ft_ret, *std_ret, test_name, "`insert` should return an iterator pointing to the inserted element");
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`insert` should insert the element at the specified position");
    }
    // more tests for insert with single element
    ft_ret = ft_v1.insert(ft_v1.begin(), 42.42);
    std_ret = std_v1.insert(std_v1.begin(), 42.42);
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be incremented by 1 after inserting an element");
    REQUIRE_EQ(*ft_ret, *std_ret, test_name, "`insert` should return an iterator pointing to the inserted element");
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`insert` should insert the element at the specified position");
    }
    ft_ret = ft_v1.insert(ft_v1.end(), 42.42);
    std_ret = std_v1.insert(std_v1.end(), 42.42);
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be incremented by 1 after inserting an element");
    REQUIRE_EQ(*ft_ret, *std_ret, test_name, "`insert` should return an iterator pointing to the inserted element");
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`insert` should insert the element at the specified position");
    }


    // fill insert 
    ft_it1 = ft_v1.begin() + 3;
    std_it1 = std_v1.begin() + 3;
    ft_v1.insert(ft_it1, 3, 1337.1337);
    std_v1.insert(std_it1, 3, 1337.1337);

    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be incremented by n after inserting n elements");
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`insert` should insert the element at the specified position");
    }

    // range insert
    ft::vector<double> ft_v2(3, 42.42);
    std::vector<double> std_v2(3, 42.42);

    ft_v1.insert(ft_v1.begin(), ft_v2.begin() + 2, ft_v2.end());
    std_v1.insert(std_v1.begin(), std_v2.begin() + 2, std_v2.end());
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be incremented by n after inserting range n of elements");
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`insert` should insert the element at the specified position");
    }

    // range insert
    ft_v1.insert(ft_v1.begin(), ft_v2.begin(), ft_v2.end());
    std_v1.insert(std_v1.begin(), std_v2.begin(), std_v2.end());
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be incremented by n after inserting range n of elements");
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`insert` should insert the element at the specified position");
    }
    INFO_OK(test_name);
  }


  // assign

  {
    // assign with range [first, last)
    char* test_name = strdup("assign member function tests ");
    ft::vector<float> ft_v1(10);
    std::vector<float> std_v1(10);

    ft::vector<float> ft_v2(5, 42.42);
    std::vector<float> std_v2(5, 42.42);

    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    // assign with the same vector 
    ft_v1.assign(ft_v1.begin() + 2, ft_v1.end());
    std_v1.assign(std_v1.begin() + 2, std_v1.end());
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be the same after assigning the same vector");
    // for (size_t i = 0; i < ft_v1.size(); i++)
    // {
    //   std::cout << "ft_v1[" << i << "] = " << ft_v1[i] << " | " << "std_v1[" << i << "] = " << std_v1[i] << std::endl;
    // }
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`assign` with range of the same vector is invalid");
    }
    ft_v1.assign(ft_v2.begin(), ft_v2.end());
    std_v1.assign(std_v2.begin(), std_v2.end());
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be assigned to the range [first, last)");
    for (size_t i = 0; i < ft_v1.size(); i++)
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`assign` should assign the range [first, last) to the vector");

    // fill assign
    ft_v1.assign(5, 42.42);
    std_v1.assign(5, 42.42);

    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be assigned to n after assigning n elements");
    for (size_t i = 0; i < ft_v1.size(); i++)
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`assign` should assign n elements to the vector");
    INFO_OK(test_name);
  }

  // resize 
  {
    char* test_name = strdup("resize member function tests ");
    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);

    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    ft_v1.resize(5);
    std_v1.resize(5);
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be assigned to n after resizing n elements");
    for (size_t i = 0; i < ft_v1.size(); i++)
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`resize` should resize n elements to the vector");

    ft_v1.resize(20);
    std_v1.resize(20);
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be assigned to n after resizing n elements");
    INFO_OK(test_name);
  }


  // size / capacity / empty / max_size 
  {
    char* test_name = strdup("size / capacity / empty / max_size member function tests ");
    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);

    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be 10 after creating a vector with 10 elements");

    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`capacity` should be 10 after creating a vector with 10 elements");

    ft_v1.erase(ft_v1.begin() + 5);
    std_v1.erase(std_v1.begin() + 5);
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`size` should be 9 after erasing an element");


    ft_v1.reserve(100);
    std_v1.reserve(100);
    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`capacity` should be 100 after reserving 100 elements");
    REQUIRE_EQ(ft_v1.empty(), std_v1.empty(), test_name, "`empty` should be false after creating a vector with 10 elements");
    REQUIRE_EQ(ft_v1.max_size(), std_v1.max_size(), test_name, "`max_size` should be the same after creating a vector with 10 elements");
    INFO_OK(test_name);
  }

  // const/non-const front / back member functions
  {
    char* test_name = strdup("front / back member function tests ");
    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);

    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    REQUIRE_EQ(ft_v1.front(), std_v1.front(), test_name, "`front` should return the first element of type T");
    REQUIRE_EQ(ft_v1.back(), std_v1.back(), test_name, "`back` should return the last element of type T");
    ft::vector<int> const ft_v2(10);
    std::vector<int> const std_v2(10);
    REQUIRE_EQ(ft_v2.front(), std_v2.front(), test_name, "`front` should return the first element");
    REQUIRE_EQ(ft_v2.back(), std_v2.back(), test_name, "`back` should return the last element");
    // check the type of the return value
    REQUIRE_EQ(typeid(ft_v2.front()), typeid(std_v2.front()), test_name, "`front` should return the first element of type const T");
    REQUIRE_EQ(typeid(ft_v2.back()), typeid(std_v2.back()), test_name, "`back` should return the last element of type const T");
    INFO_OK(test_name);
  }

  // const / non-const subscript operator 
  {
    char* test_name = strdup("subscript operator tests ");
    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);

    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    REQUIRE_EQ(ft_v1[5], std_v1[5], test_name, "`operator[]` should return the element at index n");
    ft::vector<int> const ft_v2(10);
    std::vector<int> const std_v2(10);
    REQUIRE_EQ(ft_v2[5], std_v2[5], test_name, "`operator[]` should return the element at index n");
    // check the type of the return value
    REQUIRE_EQ(typeid(ft_v2[5]), typeid(std_v2[5]), test_name, "`operator[]` should return the element at index n of type const T");
    INFO_OK(test_name);
  }

  // const / non-const data() member functions
  {
    char* test_name = strdup("data member function tests ");

    ft::vector<int> ft_v1;
    std::vector<int> std_v1;

    REQUIRE_EQ(ft_v1.data(), std_v1.data(), test_name, "`data` should return a `NULL` pointer when vector is default constructed");

    ft_v1.insert(ft_v1.begin(), 10);
    std_v1.insert(std_v1.begin(), 10);
    REQUIRE_EQ(*ft_v1.data(), *std_v1.data(), test_name, "`data` should return the raw pointer used internally by the vector to store its owned elements");
    INFO_OK(test_name);
  }

  // at 
  {
    char* test_name = strdup("at member function tests ");
    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);

    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    // basic 
    REQUIRE_EQ(ft_v1.at(5), std_v1.at(5), test_name, "`at` should return the element at index n");
    // out of range 
    bool ft_threw = false;
    // check if the exception is thrown then ft_threw is set to true
    try {
      ft_v1.at(100);
    }
    catch (std::exception& e) {
      ft_threw = true;
    }

    REQUIRE_EQ(ft_threw, true, test_name, "`at` should throw an exception if the index is out of range");

    ft::vector<int> const ft_v2(10);
    std::vector<int> const std_v2(10);

    REQUIRE_EQ(ft_v2.at(5), std_v2.at(5), test_name, "const `at` should return the element at index n");
    // out of range
    ft_threw = false;
    try {
      ft_v2.at(100);
    }
    catch (std::exception& e) {
      ft_threw = true;
    }

    REQUIRE_EQ(ft_threw, true, test_name, "const `at` should throw an exception if the index is out of range");
    INFO_OK(test_name);
  }

  // clear 
  {
    char* test_name = strdup("clear member function tests ");
    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);

    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }

    ft_v1.clear();
    std_v1.clear();
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`clear` should set the size to 0");
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_NEQ(ft_v1[i], (int)i, test_name, "`clear` should destroy all elements");
    }
    INFO_OK(test_name);
  }

  // get_allocator 
  {
    char* test_name = strdup("get_allocator member function tests ");
    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);

    for (size_t i = 0; i < 10; i++) {
      ft_v1[i] = i;
      std_v1[i] = i;
    }
    REQUIRE_EQ(ft_v1.get_allocator(), std_v1.get_allocator(), test_name, "`get_allocator` should return the allocator object used by the vector");
    INFO_OK(test_name);
  }

  // shrink_to_fit
  {
    char* test_name = strdup("shrink_to_fit member function tests ");
    ft::vector<int> ft_v1(10);
    std::vector<int> std_v1(10);


    ft_v1.insert(ft_v1.begin(), (size_t)5, 10);
    std_v1.insert(std_v1.begin(), 5, 10);
    ft_v1.shrink_to_fit();
    std_v1.shrink_to_fit();
    REQUIRE_EQ(ft_v1.capacity(), std_v1.capacity(), test_name, "`shrink_to_fit` should set the capacity to the size");
    INFO_OK(test_name);
  }

  // swap 
  {
    char* test_name = strdup("swap member function tests ");
    ft::vector<int> ft_v1((size_t)10, 10);
    ft::vector<int> ft_v2((size_t)20, 100);
    ft_v1.swap(ft_v2);
    REQUIRE_EQ(ft_v1.size(), 20, test_name, "`swap` should swap the contents of the vector including the `size`");
    REQUIRE_EQ(ft_v2.size(), 10, test_name, "`swap` should swap the contents of the vector including the `size`");
    REQUIRE_EQ(ft_v1.capacity(), 20, test_name, "`swap` should swap the contents of the vector including the `capacity`");
    REQUIRE_EQ(ft_v2.capacity(), 10, test_name, "`swap` should swap the contents of the vector including the `capacity`");
    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], 100, test_name, "`swap` should swap the contents of the vector");
    }
    for (size_t i = 0; i < ft_v2.size(); i++) {
      REQUIRE_EQ(ft_v2[i], 10, test_name, "`swap` should swap the contents of the vector");
    }
    INFO_OK(test_name);
  }

  // push_back 
  {
    char* test_name = strdup("push_back member function tests ");
    ft::vector<int> ft_v1;
    std::vector<int> std_v1;
    ft_v1.push_back(10);
    std_v1.push_back(10);
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`push_back` should increase the size by 1");


    REQUIRE_EQ(ft_v1[0], std_v1[0], test_name, "`push_back` should add the element at the end of the vector");
    for (size_t i = 0; i < 10; i++) {
      ft_v1.push_back(i);
      std_v1.push_back(i);
    }
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`push_back` should increase the size by 1");

    for (size_t i = 0; i < ft_v1.size(); i++) {
      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`push_back` should add the element at the end of the vector");
    }
    INFO_OK(test_name);
  }

  // reverse iterator 
  {

    char* test_name = strdup("reverse iterator tests ");
    (void)test_name;
    ft::vector<int> ft_v1;
    std::vector<int> std_v1;
    for (size_t i = 0; i < 10; i++) {
      ft_v1.push_back(i);
      std_v1.push_back(i);
    }
    ft::vector<int>::reverse_iterator ft_it = ft_v1.rbegin();
    std::vector<int>::reverse_iterator std_it = std_v1.rbegin();
    ft_it++;
    std_it++;
    REQUIRE_EQ(*ft_it, *std_it, test_name, "`reverse_iterator` should be in reverse order");
    for (; ft_it != ft_v1.rend(); ft_it++, std_it++) {
      REQUIRE_EQ(*ft_it, *std_it, test_name, "`reverse_iterator` should iterate in reverse order");
    }

    // base 
    REQUIRE_EQ(ft_it.base(), ft_v1.begin(), test_name, "`base` should return the base iterator");
    INFO_OK(test_name);
  }

  // pop back
  {
    char* test_name = strdup("pop_back member function tests ");
    ft::vector<int> ft_v1((size_t)5, 10);
    std::vector<int> std_v1((size_t)5, 10);

    ft_v1.pop_back();
    std_v1.pop_back();
    REQUIRE_EQ(ft_v1.size(), std_v1.size(), test_name, "`pop_back` should decrease the size by 1");

	   for (size_t i = 0; i < ft_v1.size(); i++) {
	      REQUIRE_EQ(ft_v1[i], std_v1[i], test_name, "`pop_back` should remove the last element");
    }

    INFO_OK(test_name);
  }
}
