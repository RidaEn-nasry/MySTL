#include <iostream>
#include <vector>
#include <map>


int main()
{
  std::map<int, int> map;
  map[1] = 1;
  map[2] = 2;
  map[3] = 3;
  std::cout << map[1] << std::endl;
  return 0;
}