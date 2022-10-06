#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
struct Meow {
  void purr() {
    puts("Meow<T>::purr");
  };
};

template <> struct Meow<int> {
  void purr() {
    puts("Meow<int>::purr();");
  }
};


int main() {
  Meow<long> l;
  l.purr();
  
  Meow<int> i;
  i.purr();
}


