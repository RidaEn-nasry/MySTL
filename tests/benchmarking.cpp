/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmarking.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:22:03 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/24 20:50:27 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// benchmarking vector and map with std::map and std::vector

#include <test.hpp>



void ft_benchmarking_tests_suite()
{

  // vector

  std::cout << "\033[1;31m"
            << "vector benchmark"
            << "\033[0m" << std::endl;

  {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
    std::clock_t ft_start;
    std::clock_t std_start;
    double ft_duration;
    double std_duration2;

    ft_start = std::clock();
    for (int i = 0; i < VEC_TEST_SIZE; i++)
      ft_vector.push_back(i);
    ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
    //sleep(2);
    std_start = std::clock();
    for (int i = 0; i < VEC_TEST_SIZE; i++)
      std_vector.push_back(i);
    std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;
  

    std::cout << "----------------------------------------" << '\n';
    std::cout << "\033[1;33m"
              << "ft::vector push_back: " << ft_duration << '\n';
    std::cout << "\033[1;33m"
              << "std::vector push_back: " << std_duration2 << '\n';
    std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
              << "with a ratio of " << (ft_duration / std_duration2) << '\n';
    std::cout << "----------------------------------------" << '\n';

    ft_start = std::clock();
    for (int i = 0; i < VEC_TEST_SIZE; i++)
      ft_vector.pop_back();
    ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
    //sleep(2);
    std_start = std::clock();
    for (int i = 0; i < VEC_TEST_SIZE; i++)
      std_vector.pop_back();
    std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;

    std::cout << "----------------------------------------" << '\n';
    std::cout << "\033[1;33m"
              << "ft::vector pop_back: " << ft_duration << '\n';
    std::cout << "\033[1;33m"
              << "std::vector pop_back: " << std_duration2 << '\n';
    std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
              << "with a ratio of " << (ft_duration / std_duration2) << '\n';
    std::cout << "----------------------------------------" << '\n';

    {
      // iterator
      ft::vector<int> ft_ite_vec(VEC_TEST_SIZE);
      std::vector<int> std_ite_vec(VEC_TEST_SIZE);
      std::clock_t ft_ite_start;
      std::clock_t std_ite_start;
      double ft_ite_duration;
      double std_ite_duration2;
      
      ft_ite_start = std::clock();
      for (ft::vector<int>::iterator it = ft_ite_vec.begin(); it != ft_ite_vec.end(); it++)
        *it = 0;
      ft_ite_duration = (std::clock() - ft_ite_start) / (double)CLOCKS_PER_SEC;

      //sleep(2);
      std_ite_start = std::clock();
      for (std::vector<int>::iterator it = std_ite_vec.begin(); it != std_ite_vec.end(); it++)
        *it = 0;
      std_ite_duration2 = (std::clock() - std_ite_start) / (double)CLOCKS_PER_SEC;

      std::cout << "----------------------------------------" << '\n';
      std::cout << "\033[1;33m"
                << "ft::vector iterator: " << ft_ite_duration << '\n';
      std::cout << "\033[1;33m"
                << "std::vector iterator: " << ft_ite_duration << '\n';
      std::cout << "ft:: is" << (ft_ite_duration < ft_ite_duration ? " faster" : " slower") << " than std::"
                << "with a ratio of " << (ft_ite_duration / std_ite_duration2) << '\n';
      std::cout << "----------------------------------------" << '\n';
    }
    // resize


    ft_start = std::clock();
    ft_vector.resize(VEC_TEST_SIZE * 2);
    ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
    //sleep(2);
    std_start = std::clock();
    std_vector.resize(VEC_TEST_SIZE * 2);
    std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;

    std::cout << "----------------------------------------" << '\n';
    std::cout << "\033[1;33m"
              << "ft::vector resize: " << ft_duration << '\n';
    std::cout << "\033[1;33m"
              << "std::vector resize: " << std_duration2 << '\n';
    std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
              << "with a ratio of " << (ft_duration / std_duration2) << '\n';
    std::cout << "----------------------------------------" << '\n';

    // // clear
    ft_start = std::clock();
    ft_vector.clear();
    ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
    //sleep(2);
    std_start = std::clock();
    std_vector.clear();
    std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;

    std::cout << "----------------------------------------" << '\n';
    std::cout << "\033[1;33m"
              << "ft::vector clear: " << ft_duration << '\n';
    std::cout << "\033[1;33m"
              << "std::vector clear: " << std_duration2 << '\n';
    std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
              << "with a ratio of " << (ft_duration / std_duration2) << '\n';
    std::cout << "----------------------------------------" << '\n';
  };

  std::cout << "\033[1;31m"
            << "map benchmark"
            << "\033[0m" << std::endl;

  {

      std::map<int, int> std_map;
      ft::map<int, int> ft_map;
      std::clock_t ft_start;
      std::clock_t std_start;
      double ft_duration;
      double std_duration2;

      ft_start = std::clock();
      for (int i = 0; i < MAP_TEST_SIZE; i++)
        ft_map.insert(ft::make_pair(i, i));
      ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
      //sleep(2);
      std_start = std::clock();
      for (int i = 0; i < MAP_TEST_SIZE; i++)
        std_map.insert(std::make_pair(i, i));
      std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;

      std::cout << "----------------------------------------" << '\n';
      std::cout << "\033[1;33m"
                << "ft::map insert: " << ft_duration << '\n';
      std::cout << "\033[1;33m"
                << "std::map insert: " << std_duration2 << '\n';
      std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
                << "with a ratio of " << (ft_duration / std_duration2) << '\n';
      std::cout << "----------------------------------------" << '\n';

      // // erase

      ft_start = std::clock();

      for (int i = 0; i < MAP_TEST_SIZE; i++)
        ft_map.erase(i);
      ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;

      //sleep(2);
      std_start = std::clock();
    
      for (int i = 0; i < MAP_TEST_SIZE; i++)
        std_map.erase(i);
      std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;
      std::cout << "----------------------------------------" << '\n';
      std::cout << "\033[1;33m"
                << "ft::map clear: " << ft_duration << '\n';
      std::cout << "\033[1;33m"
                << "std::map clear: " << std_duration2 << '\n';
      std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
                << "with a ratio of " << (ft_duration / std_duration2) << '\n';
      std::cout << "----------------------------------------" << '\n';

      // [] operator
      ft_start = std::clock();
      for (int i = 0; i < MAP_TEST_SIZE; i++)
        ft_map[i] = i;
      ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
      //sleep(2);
      std_start = std::clock();
      for (int i = 0; i < MAP_TEST_SIZE; i++)
        std_map[i] = i;
      std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;
      std::cout << "----------------------------------------" << '\n';
      std::cout << "\033[1;33m"
                << "ft::map [] operator: " << ft_duration << '\n';
      std::cout << "\033[1;33m"
                << "std::map [] operator: " << std_duration2 << '\n';
      std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
                << "with a ratio of " << (ft_duration / std_duration2) << '\n';
      std::cout << "----------------------------------------" << '\n';

      // // find
      ft_start = std::clock();
      for (int i = 0; i < MAP_TEST_SIZE; i++)
        ft_map.find(i);
      ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
      //sleep(2);
      std_start = std::clock();
      for (int i = 0; i < MAP_TEST_SIZE; i++)
        std_map.find(i);
      std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;
      std::cout << "----------------------------------------" << '\n';
      std::cout << "\033[1;33m"
                << "ft::map find: " << ft_duration << '\n';
      std::cout << "\033[1;33m"
                << "std::map find: " << std_duration2 << '\n';
      std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
                << "with a ratio of " << (ft_duration / std_duration2) << '\n';
      std::cout << "----------------------------------------" << '\n';

      // iterator
      ft_start = std::clock();
      for (ft::map<int, int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
        *it;
      ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
      //sleep(2);
      std_start = std::clock();
      for (std::map<int, int>::iterator it = std_map.begin(); it != std_map.end(); it++)
        *it;
      std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;

      std::cout << "----------------------------------------" << '\n';
      std::cout << "\033[1;33m"
                << "ft::map iterator: " << ft_duration << '\n';
      std::cout << "\033[1;33m"
                << "std::map iterator: " << std_duration2 << '\n';
      std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
                << "with a ratio of " << (ft_duration / std_duration2) << '\n';
      std::cout << "----------------------------------------" << '\n';
  };

  std::cout << "\033[1;31m"
            << "stack benchmark"
            << "\033[0m" << std::endl;

  {
    ft::stack<int> ft_stack;
    std::stack<int> std_stack;
    std::clock_t ft_start;
    std::clock_t std_start;
    double ft_duration;
    double std_duration2;

    // push
    ft_start = std::clock();
    for (int i = 0; i < STACK_TEST_SIZE; i++)
      ft_stack.push(i);
    ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
    //sleep(2);
    std_start = std::clock();
    for (int i = 0; i < STACK_TEST_SIZE; i++)
      std_stack.push(i);
    std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;
    std::cout << "----------------------------------------" << '\n';
    std::cout << "\033[1;33m"
              << "ft::stack push: " << ft_duration << '\n';
    std::cout << "\033[1;33m"
              << "std::stack push: " << std_duration2 << '\n';
    std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
              << "with a ratio of " << (ft_duration / std_duration2) << '\n';
    std::cout << "----------------------------------------" << '\n';

    // // pop
    ft_start = std::clock();
    for (int i = 0; i < STACK_TEST_SIZE; i++)
      ft_stack.pop();
    ft_duration = (std::clock() - ft_start) / (double)CLOCKS_PER_SEC;
    //sleep(2);
    std_start = std::clock();
    for (int i = 0; i < STACK_TEST_SIZE; i++)
      std_stack.pop();
    std_duration2 = (std::clock() - std_start) / (double)CLOCKS_PER_SEC;
    std::cout << "----------------------------------------" << '\n';
    std::cout << "\033[1;33m"
              << "ft::stack pop: " << ft_duration << '\n';
    std::cout << "\033[1;33m"
              << "std::stack pop: " << std_duration2 << '\n';

    std::cout << "ft:: is" << (ft_duration < std_duration2 ? " faster" : " slower") << " than std::"
              << "with a ratio of " << (ft_duration / std_duration2) << '\n';
    std::cout << "----------------------------------------" << '\n';
  }
}
