#include <map>
#include <iostream>


int main() {



  std::map<int, char> map;
  std::map<int, char>::iterator it;
  std::map<int, char>::iterator ite;
  map.erase(map.begin(), map.end());
  
  return 0;

}

