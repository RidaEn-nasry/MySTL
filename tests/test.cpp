/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:49:06 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/08 20:59:15 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.hpp>


void  ft_run_all_tests() {
  // ft_iterator_traits_tests_suite();
  ft_vector_tests_suite();
  ft_stack_tests_suite();
  ft_pair_tests_suite();
  // ft_list_tests_suite();
  
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Usage: ./test [test_name] \t \
    use `./test --list` to list all tests" << std::endl;
    exit(1);
  }
  else if (strcmp(argv[1], "--list") == 0) {
    std::cout << "./test all \t\t to run all tests or\n./test <test_name>\t\tfrom Available tests: " << std::endl;
    std::cout << "vector\nstack\nlist\niterator_traits" << std::endl;
    exit(0);
  }
  else if (strcmp(argv[1], "all") == 0)
    ft_run_all_tests();
  else if (strcmp(argv[1], "vector") == 0)
    ft_vector_tests_suite();
  else if (strcmp(argv[1], "iterator_traits") == 0)
    ft_iterator_traits_tests_suite();
  else if (strcmp(argv[1], "reverse_iterator") == 0)
    ft_reverse_iterator_tests_suite();
  else if (strcmp(argv[1], "enable_if") == 0)
    ft_enable_if_tests_suite();
  else if (strcmp(argv[1], "pair") == 0)
    ft_pair_tests_suite();
  else if (strcmp(argv[1], "stack") == 0)
    ft_stack_tests_suite();
  else
  {
    std::cout << "Test not found" << std::endl;
    std::cout << "Usage: ./test [test_name] \t \
    use `./test --list` to list all tests" << std::endl;
    exit(1);
  }


}