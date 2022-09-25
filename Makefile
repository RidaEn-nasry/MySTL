

NAME=./container

# Variables
CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror
RM=rm -f

OTHERS=./others/iterator_traits.hpp
	   ./otherrs/iterator_wrapper.hpp
CONTAINERS=./containers/Vector.hpp
TESTS=./tests/tests.cpp \
	  ./tests/vector_tests.cpp

TEST_OBJS=$(TESTS:.cpp=.o)

%.o: %.cpp $(CONTAINERS) $(OTHERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(CONTAINERS) $(OTHERS)

all: $(NAME)

$(NAME): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(TEST_OBJS)

clean: 
	$(RM) $(TEST_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

