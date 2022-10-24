
NAME=test

CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror -g
RM=rm -f

OTHERS=-I./type_traits/ -I./tests/ -I./adapters/ -I./others/ -I./utility/ -I./algorithms/ -I./functional -I./containers/map/


CONTAINERS=-I./containers/
TESTS=./tests/vector.cpp\
			./tests/test.cpp\
			./tests/iterator_traits.cpp\
			./tests/reverse_iterator.cpp\
			./tests/stack.cpp\
			./tests/enable_if.cpp\
			./tests/pair.cpp\
			./tests/lexico_compare.cpp\
			./tests/is_integral.cpp\
			./tests/equal.cpp\
			./tests/avlnode.cpp\
			./tests/map.cpp\
			./tests/benchmarking.cpp\
			./tests/main_test.cpp

DEP=./others/choose_type.hpp\
	./containers/vector.hpp\
	./type_traits/iterator_traits.hpp\
	./type_traits/enable_if.hpp\
	./type_traits/is_integral.hpp\
	./adapters/reverse_iterator.hpp\
	./adapters/stack.hpp\
	./algorithms/equal.hpp\
	./algorithms/lexico_compare.hpp\
	./utility/make_pair.hpp\
	./functional/less.hpp\
	./utility/pair.hpp\
	./functional/less.hpp\
	./containers/map/avlnode.hpp\
	./containers/map/map.hpp\
	./tests/test.hpp

TEST_OBJS=$(TESTS:.cpp=.o)

%.o: %.cpp $(DEP)
	$(CXX) $(CXXFLAGS) -c $< -o $@  $(OTHERS) $(CONTAINERS)
all: $(NAME)

$(NAME): $(TEST_OBJS) $(DEP)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(TEST_OBJS)

pre-process:
	$(CXX) $(CXXFLAGS) -E $(TESTS) $(OTHERS) $(CONTAINERS) > pre-processed.cpp

clean: 
	$(RM) $(TEST_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
