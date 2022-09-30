
NAME=test

# Variables
CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror -g
RM=rm -f

OTHERS=-I./others/ -I./tests/
CONTAINERS=-I./containers/
TESTS=./tests/vector.cpp\
			./tests/test.cpp

DEP=./containers/vector.hpp\
	./others/iterator_traits.hpp\
	./tests/test.hpp

TEST_OBJS=$(TESTS:.cpp=.o)

%.o: %.cpp
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
