#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    map<string, int> m;
    m.insert(pair<string, int>("a", 1));
    m.insert(pair<string, int>("b", 2));
    m.insert(pair<string, int>("c", 3));


    map<string, int>::iterator it = m.begin();
    map<string, int>::iterator it2 = m.end();
    map<string, int> m2;
    m2.insert(it, it2);

    for (map<string, int>::iterator it = m2.begin(); it != m2.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';


    return 0;
}