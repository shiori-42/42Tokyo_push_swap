CC=cc -g -fsanitize=address
CFLAGS=-Wall -Wextra -Werror
INCLUDES= -I./includes -I./libft/includes

LIBFT=libft/libft.a
SRCDIR=srcs/
SRCFILES=cmd_push_pop_swap.c find_target_a.c sort_stack.c \
cmd_rotate_rev_rotate.c find_target_b.c sort_three.c \
create_stack.c main.c stack_utils.c \

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
