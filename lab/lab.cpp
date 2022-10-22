#include <map>
#include <iostream>


#include "maindummy.hpp"

// reproducing the error "non-const l" 


class A {
public:
    // 
private:
    int _a;
};
int main() {
    A a()
}