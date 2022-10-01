

#include <test.hpp>
void ft_iterator_traits_tests_suite() {

  /**********************************/
  /***      ITERATOR TRAITS       ***/
  /*********************************/
  {
    char* test_name = strdup("Iterator traits tests ");

    ft::iterator_traits<ft::vector<char>::iterator>::iterator_category ft_it_cat;
    REQUIRE_STREQ(typeid(ft_it_cat).name(), typeid(std::random_access_iterator_tag).name(), test_name, "`ft::iterator_traits<ft::vector<T>::iterator>::iterator_category` should be `std::random_access_iterator_tag`");
    REQUIRE_STREQ(typeid(ft::iterator_traits<ft::vector<char>::iterator>::value_type).name(), typeid(char).name(), test_name, "`ft::iterator_traits<ft::vector<T>::iterator>::value_type` should be `T`");
    REQUIRE_STREQ(typeid(ft::iterator_traits<ft::vector<char>::iterator>::difference_type).name(), typeid(std::ptrdiff_t).name(), test_name, "`ft::iterator_traits<ft::vector<T>::iterator>::difference_type` should be `std::ptrdiff_t`");
    REQUIRE_STREQ(typeid(ft::iterator_traits<ft::vector<char>::iterator>::pointer).name(), typeid(char*).name(), test_name, "`ft::iterator_traits<ft::vector<T>::iterator>::pointer` should be `T*`");
    REQUIRE_STREQ(typeid(ft::iterator_traits<ft::vector<char>::iterator>::reference).name(), typeid(char&).name(), test_name, "`ft::iterator_traits<ft::vector<T>::iterator>::reference` should be `T&`");
    INFO_OK(test_name);
  }
}

