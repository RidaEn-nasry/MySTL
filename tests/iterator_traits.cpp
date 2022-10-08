

#include <test.hpp>
void ft_iterator_traits_tests_suite() {

  /**********************************/
  /***      ITERATOR TRAITS       ***/
  /*********************************/
  {
    std::string test_name("Iterator traits tests ");

    // iterator traits for Iter / pointer / const pointer
    ft::vector<int> v((size_t)5, 42);
    ft::vector<int>::iterator it = v.begin();

    /*** ITERATOR TRAITS of Iterator type ***/
    REQUIRE_STREQ(typeid(ft::iterator_traits<ft::vector<int>::iterator>::iterator_category).name(), typeid(std::random_access_iterator_tag).name(), test_name, "iterator_traits<iterator>::iterator_category should be of type std::iterator_traits<iterator>::iterator_category");
    REQUIRE_STREQ(typeid(ft::iterator_traits<ft::vector<int>::iterator>::value_type).name(), typeid(int).name(), test_name, "iterator_traits<iterator>::value_type should be of type std::iterator_traits<iterator>::value_type");
    REQUIRE_STREQ(typeid(ft::iterator_traits<ft::vector<int>::iterator>::difference_type).name(), typeid(std::ptrdiff_t).name(), test_name, "iterator_traits<iterator>::difference_type should be of type std::iterator_traits<iterator>::difference_type");
    REQUIRE_STREQ(typeid(ft::iterator_traits<ft::vector<int>::iterator>::pointer).name(), typeid(int*).name(), test_name, "iterator_traits<iterator>::pointer should be of type std::iterator_traits<iterator>::pointer");
    REQUIRE_STREQ(typeid(ft::iterator_traits<ft::vector<int>::iterator>::reference).name(), typeid(int&).name(), test_name, "iterator_traits<iterator>::reference should be of type std::iterator_traits<iterator>::reference");

    /*** ITERATOR TRAITS of pointer type ***/
    REQUIRE_STREQ(typeid(ft::iterator_traits<int*>::iterator_category).name(), typeid(std::random_access_iterator_tag).name(), test_name, "iterator_traits<pointer>::iterator_category should be of type std::random_access_iterator_tag");
    REQUIRE_STREQ(typeid(ft::iterator_traits<int*>::value_type).name(), typeid(int).name(), test_name, "iterator_traits<pointer>::value_type should be of type int");
    REQUIRE_STREQ(typeid(ft::iterator_traits<int*>::difference_type).name(), typeid(std::ptrdiff_t).name(), test_name, "iterator_traits<pointer>::difference_type should be of type std::ptrdiff_t");
    REQUIRE_STREQ(typeid(ft::iterator_traits<int*>::pointer).name(), typeid(int*).name(), test_name, "iterator_traits<pointer>::pointer should be of type int*");
    REQUIRE_STREQ(typeid(ft::iterator_traits<int*>::reference).name(), typeid(int&).name(), test_name, "iterator_traits<pointer>::reference should be of type int&");

    /*** ITERATOR TRAITS of const pointer type ***/
    REQUIRE_STREQ(typeid(ft::iterator_traits<const int*>::iterator_category).name(), typeid(std::random_access_iterator_tag).name(), test_name, "iterator_traits<const pointer>::iterator_category should be of type std::random_access_iterator_tag");
    REQUIRE_STREQ(typeid(ft::iterator_traits<const int*>::value_type).name(), typeid(int).name(), test_name, "iterator_traits<const pointer>::value_type should be of type int");
    REQUIRE_STREQ(typeid(ft::iterator_traits<const int*>::difference_type).name(), typeid(std::ptrdiff_t).name(), test_name, "iterator_traits<const pointer>::difference_type should be of type std::ptrdiff_t");
    REQUIRE_STREQ(typeid(ft::iterator_traits<const int*>::pointer).name(), typeid(const int*).name(), test_name, "iterator_traits<const pointer>::pointer should be of type const int*");
    REQUIRE_STREQ(typeid(ft::iterator_traits<const int*>::reference).name(), typeid(const int&).name(), test_name, "iterator_traits<const pointer>::reference should be of type const int&");
    
    INFO_OK(test_name);
  }
}

