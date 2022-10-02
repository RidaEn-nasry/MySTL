
# Resources:

STL

The guy that tutored in these videos have been maintaining Microsoft’s STL since 2007.
https://learn.microsoft.com/en-us/shows/c9-lectures-stephan-t-lavavej-standard-template-library-stl-/
Save these for later.https://www.mica.edu.vn/perso/Vu-Hai/EE3490/Ref/The%20C++Standard%20Library%20-%202nd%20Edition.pdf
https://www.pdfdrive.com/stl-tutorial-and-reference-guide-c-programming-with-the-standard-template-library-e187782001.html

What ? And why ? Member types is used in containers/iterators ?
https://stackoverflow.com/questions/31494286/what-is-meaning-of-member-types-in-stl-container
https://stackoverflow.com/questions/37714566/what-do-member-types-mean-in-vectors

Why allocaters ?
https://stackoverflow.com/questions/31358804/whats-the-advantage-of-using-stdallocator-instead-of-new-in-c

What’s the difference between destroy & deallocate in std::allocater ?
https://stackoverflow.com/questions/26667026/difference-between-destroy-destructor-deallocate-in-stdallocator
https://stackoverflow.com/questions/33709766/whats-the-difference-between-destroy-the-objects-and-free-the-associated-memory

What is this “one-past-the end iterator” and given that comparing an invalid pointer is UB how is it legal to compare it ?
https://stackoverflow.com/questions/2728299/why-is-comparing-against-end-iterator-legal

Writing an iterator for your container
https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
https://codereview.stackexchange.com/questions/202157/basic-iterator-supporting-vector-implementation

What is tag dispatching ?
https://www.fluentcpp.com/2018/04/27/tag-dispatching/
Why tag dispatching is used in iterator implementation:
https://www.modernescpp.com/index.php/softwaredesign-with-traits-and-tag-dispatching

Why using a friend member function for the expression (n + iterator)
https://stackoverflow.com/questions/27225388/why-is-it-recommended-to-declare-functions-as-friends-in-operator-overloading
https://users.monash.edu/~jonmc/CSE2305/Topics/10.19.OpOverload/html/text.html#a_slight_problem_of_ordering

How vector grow ? and which growth strategy to use for vector container?
https://stackoverflow.com/questions/5232198/how-does-the-capacity-of-stdvector-grow-automatically-what-is-the-rate

WTF is this `const value_type& val = value_type()` ? or what’s the default values of vector’s constructors ?
https://stackoverflow.com/questions/42743604/default-values-when-creating-a-vector-c

What’s the default capacity of vector ?
https://stackoverflow.com/questions/48744449/is-it-guaranteed-that-stdvector-default-construction-does-not-call-new
https://stackoverflow.com/questions/12271017/initial-capacity-of-vector-in-c

Why access member functions have a const and non-const version ?
https://stackoverflow.com/questions/63730953/operator-overloading-with-const-and-non-const-versions

Ok wait ? iterator invalidation is extremely an important idea to understand how iterators work!!!! So what is iterator invalidation ?
https://stackoverflow.com/questions/16904454/what-is-iterator-invalidation

Why fill insert member function isn’t valid after filling ?
https://stackoverflow.com/questions/23845033/why-iterator-vectorinsert-is-not-valid-after-filling-iterator-insert-const-i

