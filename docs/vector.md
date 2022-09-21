# Re-inventing the wheel: std::vector





# The why before the how ? 
The most important question that a half-awake homosapien should always start with is **why**? so **why std::vector** ? 
**what is the need for std::vector** ? **and what is the problem that std::vector trying to solve** ?

if you come from a C background, and used arrays as your primary data structure in a reasonbly mid to large scale programs, you'll mary vectors litterly in the first date.
these things are dynamic and allow for a flexibility you wish you had in C, no more reallocation no more array-related segfaults, and once you start reading the container's internals you'll find all your past pains and heart-breaks reflected in one class. you can't help but fall in love with it.

so enough rambling **why `std::vector`** ? `std::vector` comes as a reply to the statement **what if i don't know the size of my array at compile time** ? and as C past citizen you've tried to solve this problem using c-style tricks.

```
// 1) your might have been storing the arr and size in a struct
typedef struct {
	some_type *arr;
	int size;
} half-assed-dynamic-array;

// then you init the struct like so 
half-assed-dynamic-array *arr = malloc(sizeof(half-assed-dynamic-array));
arr->arr = malloc(sizeof(some_type));
arr->size = 0;

// and then at each time you want to add an element you reallocate all over again
arr->arr = malloc(sizeof(some_type) * (arr->size + 1));
// and then you copy your old data to the new array
arr->arr[arr->size] = some_value;
arr->size++;

```
This is an over simplification, and you could see that this is costly either from a performance or a memory perspective, let alone your perspective.
your perspective probably looks something like : 
> ""I, is sick and tired of writing code that deals with hardware and memory management, I want to write code that deals with business logic, i want to code algorithms and data structures not solve a problem that has been solved 1000 times before me and i'm not even sure if i'm doing it right? probably not ! most likely not ! and .. "

ok that's it, i needed that ranting out of my system, i think you get the point , that's why we need `std::vector` ? ok now let's implement the container, exactly let's solve a problem that has been solved 1000 times before us, and we're not even sure if we're doing it right? probably not ! most likely not !.

## Here we go !
There are
