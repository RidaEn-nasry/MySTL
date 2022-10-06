
NAME=test

# Variables
CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror -g
RM=rm -f

OTHERS=-I./type_traits/ -I./tests/ -I./adapters/
CONTAINERS=-I./containers/
TESTS=./tests/vector.cpp\
			./tests/test.cpp\
			./tests/iterator_traits.cpp\
			./tests/reverse_iterator.cpp\
			./tests/stack.cpp\
			./tests/enable_if.cpp

DEP=./containers/vector.hpp\
	./type_traits/iterator_traits.hpp\
	./type_traits/enable_if.hpp\
	./adapters/reverse_iterator.hpp\
	./adapters/stack.hpp\
	./tests/test.hpp

TEST_OBJS=$(TESTS:.cpp=.o)

%.o: %.cpp $(DEP)
	$(CXX) $(CXXFLAGS) -c $< -o $@  $(OTHERS) $(CONTAINERS)
all: $(NAME)

$(NAME): $(TEST_OBJS) $(DEP)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(TEST_OBJS)

clean: 
	$(RM) $(TEST_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
