/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:12:40 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/03 20:32:57 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
#include "../libft/libft.h" 


typedef struct s_node
{
	int				num;
	int				index;
	int				above_median;
	int				push_cost;
	struct s_node	*next;
	struct s_node	*target_node;
	int				cheapst;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

void free_stacks(t_stack *stack);
int pop(t_node **top);
int check_syntax(char *arg);
void load_stack(t_stack *stack, char **argv);
int is_sorted(t_stack *stack);
int stack_len(t_node *top);
void sa(t_node **top);
void sort_three(t_node **top);
void sort_stacks(t_stack *a, t_stack *b);

void pb(t_node **b_top, t_node **a_top);
void pa(t_node **a_top, t_node **b_top);
void rotate_both(t_node **a_top, t_node **b_top);
void rev_rotate_both(t_node **a_top, t_node **b_top);
void prep_for_push(t_node **stack_top, t_node *node, char stack_name);
void move_a_to_b(t_node **a_top, t_node **b_top);
void move_b_to_a(t_node **a_top, t_node **b_top);
void set_index(t_node *top);
void min_on_top(t_stack *stack);
t_node *get_cheapst(t_node *top);
t_node *find_min(t_node *top);
t_node  *find_max(t_node *top); 
void init_nodes_a(t_node *a_top, t_node *b_top);
void	init_nodes_b(t_node *a_top, t_node *b_top);

void print_operation( char *op);

void push(t_node **top, int num, char *op);
void swap(t_node **top, char *op);
void rotate(t_node **top, char *op);
void rev_rotate(t_node **top, char *op);
void print_stack(t_stack *stack);

#endif