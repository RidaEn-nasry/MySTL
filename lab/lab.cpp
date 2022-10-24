#include <iostream>
#include <map>
// #include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, char> m;
    for (int i = 0; i < 10; i++)
        m[i] = 'a' + i;

    std::cout << m[1000] << std::endl;
    return 0;
}