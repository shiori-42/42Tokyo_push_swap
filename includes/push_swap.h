/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:12:40 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/14 20:41:22 by syonekur         ###   ########.fr       */
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
	int				above_median;
	int				push_cost;
	struct s_node	*next;
	struct s_node	*target_node;
	int				cheapest;
}					t_node;

void				free_stack(t_node **top);
void				free_errors(t_node **a);
int					check_comandline_args(char *argv);
int					call_load_stack(t_node **a, int argc, char **argv);
void				load_stack(t_node **a, char **argv);
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
void				set_index(t_node *top);
void				min_on_top(t_node **top);
t_node				*get_cheapest(t_node *top);
t_node				*find_min(t_node *top);
t_node				*find_max(t_node *top);
void				init_nodes_a(t_node *a, t_node *b);
void				init_nodes_b(t_node *a, t_node *b);
void				print_operation(char *op);
void				find_target_a(t_node *a, t_node *b);
void				find_target_b(t_node *a, t_node *b);
void				calc_cost_for_push_a(t_node *a, t_node *b);
void				find_cheapest(t_node *top);
int					is_duplicate(t_node *top, int nbr);
void				execute_cmd_2(t_node **a, t_node **b, char *cmd);

#endif