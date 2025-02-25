NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRCS = src/main.c src/operations.c src/sort.c src/utils.c src/stack.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re