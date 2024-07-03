CC=cc -g -fsanitize=address
CFLAGS=-Wall -Wextra -Werror
INCLUDES= -I./includes -I./libft/includes

LIBFT=libft/libft.a
SRCDIR=srcs/
SRCFILES=main.c sort_stack.c sort_three.c stack_utils.c \
function.c function2.c init_stack.c int_a_to_b.c 

SRCS=$(addprefix $(SRCDIR), $(SRCFILES))
OBJS=$(SRCS:.c=.o)

NAME=push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
