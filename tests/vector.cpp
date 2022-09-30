




#include <test.hpp>
// receive allocater_type of ft::vecrtor 
bool  check_allocator() {
  ft::vector<int> v1;
  const char* all_name = typeid(v1.get_allocator()).name();
  std::vector<int> v2;
  const char* std_all_name = typeid(v2.get_allocator()).name();
  return strcmp(all_name, std_all_name) == 0;
};


void ft_vector_tests_suite() {

  /********************************************************************************/
  /*                                 BASIC TESTS                                  */
  /********************************************************************************/

  char* test_name = strdup("Basic tests ");
  T ft::vector<int> v1;
  REQUIRE(typeid(v1).name(), test_name, "either you kidding me... or you're vector is not in the `ft` namespace"); C;

  INFO_OK(test_name);

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
    // char* test_name = strdup("Range constructor tests ");
    // REQUIRE(check_allocator(), test_name, "`ft::vector<T>::allocater_type` should be the same as `std::vector<T>::allocater_type`");
    // ft::vector<float> v1(129, 1.2);
    // ft::vector<float> v2(v1.begin(), v1.end());
    // REQUIRE_EQ(v1.size(), v2.size(), test_name, "`size` should be the same as `vector2.size()` when vector is range constructed");
    // REQUIRE_EQ(v1.capacity(), v2.capacity(), test_name, "`capacity` should be the same as `vector2.capacity()` when vector is range constructed");
    // for (size_t i = 0; i < v2.size(); i++) {
    //   REQUIRE_EQ(v1[i], v2[i], test_name, "each `vector[n]` should be the same as `vector2[n]` when vector is range constructed");
    // }
    // free(test_name);
    // INFO_OK(test_name);
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






}