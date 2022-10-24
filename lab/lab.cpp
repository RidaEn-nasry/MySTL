#include <iostream>
#include <map>
// #include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "\n\nWelcome to Studytonight :-)\n\n\n";
    cout << " =====  Program to demonstrate the lower_bound() and upper_bound() in Map, in CPP  ===== \n\n\n";

    //Map declaration (Map with key and value both as integers)
    map<int, int> m;

    //Filling the elements by using the insert() method.
    cout << "Filling the Map with key-value pairs of integers in random order."; //Map automatically stores them in increasing order of keys

    //make_pair() is used to insert a key value pair into the map
    m.insert(make_pair(3, 30));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(5, 50));
    m.insert(make_pair(9, 90));
    m.insert(make_pair(1, 10));

    cout << "\n\nThe number of elements in the Map are: " << m.size();

    cout << "\n\nThe elements of the Map m are: ";

    map<int, int>::iterator i;

    for (i = m.begin(); i != m.end(); i++)
    {
        cout << "( " << i->first << ", " << i->second << " ) ";
    }

    map<int, int>::iterator low, high;

    //lower_bound(x) returns the iterator to the first element that is greater than or equal to element with key x
    low = m.lower_bound(5);

    cout << "\n\nThe lower bound of 5 has key: " << low->first << " and value: " << low->second << ". ";

    low = m.lower_bound(6);

    cout << "\n\nThe lower bound of 6 has key: " << low->first << " and value: " << low->second << ". ";

    //upper_bound(x) returns the iterator to the first element that is greater than element with key x
    high = m.upper_bound(3);

    cout << "\n\nThe upper bound of 3 has key: " << high->first << " and value: " << high->second << ". ";

    high = m.upper_bound(4);

    cout << "\n\nThe upper bound of 4 has key: " << high->first << " and value: " << high->second << ". ";

    cout << "\n\n\n";

    return 0;
}