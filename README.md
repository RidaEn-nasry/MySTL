
# todo
- support a converting copy constructor from iterator to const_iterator
- support equality operator from iterator to const_iterator

# Resources:


TOOLS
See in real time how template functions/classes are generated
https://cppinsights.io/

STL

The guy that tutored in these videos have been maintaining Microsoft’s STL since 2007.
<br>https://learn.microsoft.com/en-us/shows/c9-lectures-stephan-t-lavavej-standard-template-library-stl-/
<br>Save these for later.https://www.mica.edu.vn/perso/Vu-Hai/EE3490/Ref/The%20C++Standard%20Library%20-%202nd%20Edition.pdf
<br>https://www.pdfdrive.com/stl-tutorial-and-reference-guide-c-programming-with-the-standard-template-library-e187782001.html
<br>
<br>What ? And why ? Member types is used in containers/iterators ?
<br>https://stackoverflow.com/questions/31494286/what-is-meaning-of-member-types-in-stl-container
<br>https://stackoverflow.com/questions/37714566/what-do-member-types-mean-in-vectors
<br>
<br>Why allocaters ?
<br>https://stackoverflow.com/questions/31358804/whats-the-advantage-of-using-stdallocator-instead-of-new-in-c
<br>
<br>What’s the difference between destroy & deallocate in std::allocater ?
<br>https://stackoverflow.com/questions/26667026/difference-between-destroy-destructor-deallocate-in-stdallocator
<br>https://stackoverflow.com/questions/33709766/whats-the-difference-between-destroy-the-objects-and-free-the-associated-memory
<br>
<br>What is this “one-past-the end iterator” and given that comparing an invalid pointer is UB how is it legal to compare it ?
<br>https://stackoverflow.com/questions/2728299/why-is-comparing-against-end-iterator-legal
<br>
<br>Writing an iterator for your container
<br>https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
<br>https://codereview.stackexchange.com/questions/202157/basic-iterator-supporting-vector-implementation
<br>
<br>What is tag dispatching ?
<br>https://www.fluentcpp.com/2018/04/27/tag-dispatching/
<br>Why tag dispatching is used in iterator implementation:
<br>https://www.modernescpp.com/index.php/softwaredesign-with-traits-and-tag-dispatching
<br>
<br>Why using a friend member function for the expression (n + iterator)
<br>https://stackoverflow.com/questions/27225388/why-is-it-recommended-to-declare-functions-as-friends-in-operator-overloading
<br>https://users.monash.edu/~jonmc/CSE2305/Topics/10.19.OpOverload/html/text.html#a_slight_problem_of_ordering
<br>
<br>How vector grow ? and which growth strategy to use for vector container?
<br>https://stackoverflow.com/questions/5232198/how-does-the-capacity-of-stdvector-grow-automatically-what-is-the-rate
<br>
<br>WTF is this `const value_type& val = value_type()` ? or what’s the default values of vector’s constructors ?
<br>https://stackoverflow.com/questions/42743604/default-values-when-creating-a-vector-c
<br>
<br>What’s the default capacity of vector ?
<br>https://stackoverflow.com/questions/48744449/is-it-guaranteed-that-stdvector-default-construction-does-not-call-new
<br>https://stackoverflow.com/questions/12271017/initial-capacity-of-vector-in-c
<br>
<br>Why access member functions have a const and non-const version ?
<br>https://stackoverflow.com/questions/63730953/operator-overloading-with-const-and-non-const-versions
<br>
<br>Ok wait ? iterator invalidation is extremely an important idea to understand how iterators work!!!! So what is iterator invalidation ?
<br>https://stackoverflow.com/questions/16904454/what-is-iterator-invalidation
<br>what is namelookup & arg-dep lookup & overloadresolution...?
<br>https://learn.microsoft.com/en-us/shows/c9-lectures-stephan-t-lavavej-core-c-/stephan-t-lavavej-core-c-1-of-n
<br>https://abseil.io/tips/49#:~:text=Overview,for%20a%20matching%20function%20declaration.
<br>Why fill insert member function isn’t valid after filling ?
<br>https://stackoverflow.com/questions/23845033/why-iterator-vectorinsert-is-not-valid-after-filling-iterator-insert-const-i
<br> what the heck is SFINEA ?
<br>https://blog.abhattacharyea.dev/sfinae-in-cpp/
<br>https://www.cppstories.com/2016/02/notes-on-c-sfinae/
<br>`enable_if` and SFINEA ? 
<br>https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/enable-if
<br> destructing non-class types ?? WTF ??? 
https://stackoverflow.com/questions/60006759/do-primitive-types-in-c-have-destructors
