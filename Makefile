NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./libft

LIBFT = libft/libft.a

PS_SRCDIR = srcs/push_swap/
PS_SRCFILES = calc_four_directions.c calc_push_cost.c cmd_push_pop_swap.c cmd_rotate_rev_rotate.c \
find_desired_node.c find_target_a.c find_target_b.c free_memory.c \
ft_min_ft_max.c handle_error.c move_to_target.c create_stack.c\
print_stdout.c main.c sort_stack.c sort_three.c sort_utils.c

PS_SRCS = $(addprefix $(PS_SRCDIR), $(PS_SRCFILES))
PS_OBJS = $(PS_SRCS:.c=.o)

CK_SRCDIR = srcs/checker/
CK_SRCFILES = checker_bonus.c
CK_SRCS = $(addprefix $(CK_SRCDIR), $(CK_SRCFILES))
CK_OBJS = $(CK_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(PS_OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(CK_OBJS) $(PS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CK_OBJS) $(filter-out srcs/push_swap/main.o, $(PS_OBJS)) $(LIBFT) -o $(BONUS_NAME)

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
