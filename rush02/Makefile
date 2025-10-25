NAME = rush-02

HEADERS = rush02.h

SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re

