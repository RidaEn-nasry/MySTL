
#include "pair.hpp"
#include "dummy.hpp"


namespace ft
{
    template <class T1, class T2, class T3>
    class mainDummy
    {
    public:
        typedef pair<T1, T2> pair_type;
        typedef dummy<pair<T1, T2>, T3> dummy_type;
    };
}
