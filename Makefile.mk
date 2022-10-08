

NAME=test

OBJS=$(SRCS:.c=.o)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME)