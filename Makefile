NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes

SRCS = src/main.c src/operations.c src/operations_2.c src/operations_3.c \
       src/sort.c src/utils.c src/utils_2.c src/stack.c src/parse.c \
       src/parse_utils.c

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