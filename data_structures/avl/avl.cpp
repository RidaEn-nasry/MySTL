


template <class T>
class Test {

public:
  template <class _other>
  struct rebind {
    typedef Test<_other> other;
  };

};

template <class T>
class Test2 {
  typedef Test<T> test_type;
  typedef typename test_type::template rebind<int>::other test_type2;
};

int main() {
  Test2<int> test2;
  return 0;
}
