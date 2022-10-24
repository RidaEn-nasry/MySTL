#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(2);
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
    return 0;
}