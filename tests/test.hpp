

// TODO : - add tests to
// reverse_iterator.hpp , make_pair.hpp
#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <map>
#include <chrono>
#include <ctime>
#include <cstdlib>

// my shit

#include <enable_if.hpp>
#include <iterator_traits.hpp>
#include <vector.hpp>
#include <reverse_iterator.hpp>
#include <stack.hpp>
#include <pair.hpp>
#include <lexico_compare.hpp>
#include <less.hpp>
#include <is_integral.hpp>
#include <equal.hpp>
// #include <avlnode.hpp>
#include <map.hpp>

#include <unistd.h>
#include <sys/wait.h>
#include <typeinfo>

#define INFO_ERR() std::cout << "\033[31m[ERROR]\033[0m " << __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "(): " << std::endl;
#define INFO_OK(test_name) std::cout << "\033[1;34m" << test_name << "\033[0m" \
                                     << "\033[1;32m"                           \
                                     << "OK"                                   \
                                     << "\033[0m" << std::endl;
#define INFO_FAIL(test_name)                            \
  {                                                     \
    std::cout << "\033[1;34m" << test_name << "\033[0m" \
              << "\033[1;31m"                           \
              << "FAIL"                                 \
              << "\033[0m" << std::endl;                \
    INFO_ERR();                                         \
  }
#define REASON(msg)                                             \
  {                                                             \
    std::cout << "\033[1;31m"                                   \
              << "Reason: "                                     \
              << "\033[0m"                                      \
              << "\033[1;31m" << msg << "\033[0m" << std::endl; \
    exit(EXIT_FAILURE);                                         \
  }

// defining a wrapper try/catch to catch segfaults
#define T \
  try     \
  {
#define C                                                                             \
  }                                                                                   \
  catch (std::exception & e) { std::cout << "Exception: " << e.what() << std::endl; } \
  catch (...) { std::cout << "other exceptions to be catched later" << std::endl; }

// print "reason" and then msg

#define REQUIRE(x, test_name, msg) \
  if (!(x))                        \
  {                                \
    INFO_FAIL(test_name);          \
    REASON(msg);                   \
  }

// equality
#define REQUIRE_EQ(x, y, test_name, msg) \
  if ((x) != (y))                        \
  {                                      \
    INFO_FAIL(test_name);                \
    REASON(msg);                         \
  }
#define REQUIRE_NEQ(x, y, test_name, msg) \
  if ((x) == (y))                         \
  {                                       \
    INFO_FAIL(test_name);                 \
    REASON(msg);                          \
  }
#define REQUIRE_GT(x, y, test_name, msg) \
  if ((x) <= (y))                        \
  {                                      \
    INFO_FAIL(test_name);                \
    REASON(msg);                         \
  }
#define REQUIRE_LT(x, y, test_name, msg) \
  if ((x) >= (y))                        \
  {                                      \
    INFO_FAIL(test_name);                \
    REASON(msg);                         \
  }

#define REQUIRE_GE(x, y, test_name, msg) \
  if ((x) < (y))                         \
  {                                      \
    INFO_FAIL(test_name);                \
    REASON(msg);                         \
  }
#define REQUIRE_LE(x, y, test_name, msg) \
  if ((x) > (y))                         \
  {                                      \
    INFO_FAIL(test_name);                \
    REASON(msg);                         \
  }
// string equality
#define REQUIRE_STREQ(x, y, test_name, msg) \
  if (strcmp((x), (y)) != 0)                \
  {                                         \
    INFO_FAIL(test_name);                   \
    REASON(msg);                            \
  }

// null
#define REQUIRE_NULL(x, test_name, msg) \
  if ((x) != NULL)                      \
  {                                     \
    INFO_FAIL(test_name);               \
    REASON(msg);                        \
  }
#define REQUIRE_NOT_NULL(x, test_name, msg) \
  if ((x) == NULL)                          \
  {                                         \
    INFO_FAIL(test_name);                   \
    REASON(msg);                            \
  }





// memory leaks
// #define REQUIRE_NO_LEAKS(test_name) {  \
//     std::string cmd = "leaks -quiet ./test"; \
//     std::string log = " > leaks.log"; \
//     std::string cmd_log = cmd + log; \
//     if (fork() == 0) { \
//     system(cmd_log.c_str()); \
//     exit(EXIT_SUCCESS); \
//     } \
//     else { \
//     wait(NULL); \
//     };\
// };

void ft_vector_tests_suite();
void ft_stack_tests_suite();
void ft_iterator_traits_tests_suite();
void ft_reverse_iterator_tests_suite();
void ft_enable_if_tests_suite();
void ft_pair_tests_suite();
void ft_lexico_compare_tests_suite();
void ft_enable_if_tests_suite();
void ft_is_integral_tests_suite();
void ft_equal_tests_suite();
void ft_map_tests_suite();
void ft_avlnode_tests_suite();
void ft_benchmarking_tests_suite();

#endif
