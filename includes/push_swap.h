/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:12:40 by syonekur          #+#    #+#             */
/*   Updated: 2024/08/01 23:08:08 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
	struct s_node	*target_node;
	int				is_cheapest;
	int				push_cost;
	int best_direction;
}					t_node;

enum e_direction {
    UP_UP,
    DOWN_DOWN,
    UP_DOWN,
    DOWN_UP
};

void				free_stack(t_node **top);
void				free_errors(t_node **a);
int					check_comandline_args(char *argv);
int					is_sorted(t_node *top);
int					stack_len(t_node *top);
void				sort_three(t_node **top);
void				sort_stacks(t_node **a, t_node **b);
void				push(t_node **to, t_node **from, char *op);
int					pop(t_node **top);
void				swap(t_node **top, char *op);
void				rotate(t_node **top, char *op);
void				rev_rotate(t_node **top, char *op);
void				rotate_both(t_node **a, t_node **b, t_node *cheapest_node);
void				rev_rotate_both(t_node **a, t_node **b,
						t_node *cheapest_node);
void				move_to_target(t_node **top, t_node *node, char stack_name);
void				move_a_to_b(t_node **a, t_node **b);
void				move_b_to_a(t_node **a, t_node **b);
void				set_index_stack(t_node *top);
void    set_index_both_stack(t_node *a,t_node *b);
void				min_node_on_top(t_node **top);
t_node				*find_min_node(t_node *top);
t_node				*find_max_node(t_node *top);
t_node				*find_cheapest_node(t_node *top);
void				print_operation(char *op);
void				find_target_a(t_node *a, t_node *b);
void				find_target_b(t_node *a, t_node *b);
void				mark_cheapest_node(t_node *top);
int					is_duplicate(t_node *top, int nbr);
int	ft_min(int a, int b);
int	ft_max(int a, int b);
void calc_all_push_costs(t_node *a,t_node *b);
int calc_cost_up_up(t_node *a);
int calc_cost_down_down(t_node *a, int len_a, int len_b);
int calc_cost_up_down(t_node *a, int len_b);
int calc_cost_down_up(t_node *a, int len_a);



#endif