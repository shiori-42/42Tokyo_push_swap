NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS= function.c main.c utils.c libft_util.c babblesort.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
