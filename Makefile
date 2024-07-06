NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDES = -I./includes -I./libft

LIBFT = libft/libft.a

PS_SRCDIR = srcs/push_swap/
PS_SRCFILES = cmd_push_pop_swap.c find_target_a.c sort_stack.c \
              cmd_rotate_rev_rotate.c find_target_b.c sort_three.c \
              create_stack.c push_swap.c stack_utils.c stack_utils2.c handle_error.c

PS_SRCS = $(addprefix $(PS_SRCDIR), $(PS_SRCFILES))
PS_OBJS = $(PS_SRCS:.c=.o)

CK_SRCDIR = srcs/checker/
CK_SRCFILES = checker_bonus.c get_next_line.c get_next_line_utils.c push_swap.c
CK_SRCS = $(addprefix $(CK_SRCDIR), $(CK_SRCFILES))
CK_OBJS = $(CK_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(PS_OBJS) $(LIBFT) -o $(NAME)

bonus: $(CK_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CK_OBJS) $(filter-out srcs/push_swap/push_swap.o, $(PS_OBJS)) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(PS_OBJS) $(CK_OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
