#include <map>
#include <iostream>

// template <typename key, typename val, typename comp = std::less<key> >
// class map
// {
// public:
//     typedef comp key_compare;
//     class custom_comp
//     {
//     public:
//         custom_comp(int c) : c_(c) {}
//         bool operator()(const key &lhs, const key &rhs) const
//         {
//             return comp()(lhs, rhs);
//         }

//     private:
//         key_compare c_;
//     };
//     map(comp c = comp()) : _comp(c) {}

// private:
//     custom_comp _comp;
// };

int main () {
    std::map<int, int> m;
    std::map<int, int>::iterator itend = m.end();
    return 0;
}