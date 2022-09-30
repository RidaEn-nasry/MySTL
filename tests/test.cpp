/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:49:06 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/09/30 11:53:51 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.hpp>


int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Usage: ./test [test_name] \t \
    use `./test --list` to list all tests" << std::endl;
    exit(1);
  }
  else if (strcmp(argv[1], "--list") == 0) {
    std::cout << "Available tests:" << std::endl;
    std::cout << "vector\nstack\nlist" << std::endl;
    exit(0);
  }
  else if (strcmp(argv[1], "vector") == 0) {
    ft_vector_tests_suite();
    exit(0);
  }
  else if (strcmp(argv[1], "stack") == 0) {
    //ft_stack_tests_suite();
    exit(0);
  }

}