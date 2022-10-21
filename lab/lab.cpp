#include <map>
#include <iostream>


#include "maindummy.hpp"
template <class MyType>
struct MyClass
{
    MyType i;
    MyClass(MyType i) : i(i) {}
};

template <class MyType>
MyClass<MyType> make_my_class(MyType i)
{
    return MyClass<MyType>(i);
}

int main()
{
    MyClass my_class(1);
}
