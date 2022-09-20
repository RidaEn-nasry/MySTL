
SRC=./vector/vector.cpp \
	./vector/vector.hpp \

CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror 
OBJ=$(SRC:.cpp=.o)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)


