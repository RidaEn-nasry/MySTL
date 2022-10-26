/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:49:06 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/26 11:25:06 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.hpp>

void ft_run_all_tests()
{
  ft_vector_tests_suite();
  ft_stack_tests_suite();
  ft_pair_tests_suite();
  ft_lexico_compare_tests_suite();
  ft_enable_if_tests_suite();
  ft_is_integral_tests_suite();
  ft_equal_tests_suite();
  ft_map_tests_suite();
  ft_benchmark_vec_tests_suite();
  ft_benchmark_map_tests_suite();
  ft_benchmark_stack_tests_suite();
  char* seed = new char[10];
  snprintf(seed, 10, "%ld", (time(NULL) % 100));
  main_test(seed);
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: ./test [test_name] \t \
    use `./test -list` to list all tests"
      << std::endl;
    exit(1);
  }
  else if (strcmp(argv[1], "-list") == 0)
  {
    std::cout << "./test all \t\t to run all tests or\n./test <test_name>\t\tfrom Available tests: " << std::endl;
    std::cout << "vector\nstack\npair\navlnode\nlexico\nenable_if\nis_integral\nequal\nreverse_iterator\n" << std::endl;
    exit(0);
  }
  else if (strcmp(argv[1], "all") == 0)
    ft_run_all_tests();
  else if (strcmp(argv[1], "vector") == 0)
    ft_vector_tests_suite();
  else if (strcmp(argv[1], "enable_if") == 0)
    ft_enable_if_tests_suite();
  else if (strcmp(argv[1], "pair") == 0)
    ft_pair_tests_suite();
  else if (strcmp(argv[1], "stack") == 0)
    ft_stack_tests_suite();
  else if (strcmp(argv[1], "lexico") == 0)
    ft_lexico_compare_tests_suite();
  else if (strcmp(argv[1], "is_integral") == 0)
    ft_is_integral_tests_suite();
  else if (strcmp(argv[1], "equal") == 0)
    ft_equal_tests_suite();

  else if (strcmp(argv[1], "map") == 0)
    ft_map_tests_suite();
  else if (strcmp(argv[1], "benchmark") == 0)
  {
    if (argc == 2) {
      ft_benchmark_vec_tests_suite();
      ft_benchmark_map_tests_suite();
      ft_benchmark_stack_tests_suite();
    }
    else if (strcmp(argv[2], "vector") == 0)
      ft_benchmark_vec_tests_suite();
    else if (strcmp(argv[2], "map") == 0)
      ft_benchmark_map_tests_suite();
    else if (strcmp(argv[2], "stack") == 0)
      ft_benchmark_stack_tests_suite();
  }
  else if (strcmp(argv[1], "main") == 0)
  {
    // convert an srand to char* 
    char* seed = new char[10];
    snprintf(seed, 10, "%ld", (time(NULL) % 100));
    main_test(seed);
  }
  else
  {
    std::cout << "Test not found" << std::endl;
    std::cout << "Usage: ./test [test_name] \t \
    use `./test -list` to list all tests"
      << std::endl;
    exit(1);
  }
}