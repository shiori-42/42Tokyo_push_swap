/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:46:52 by syonekur          #+#    #+#             */
/*   Updated: 2024/08/01 23:16:19 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len((*a));
	if (len_a-- > 3 && !is_sorted(*a))
		push(b, a, "pb");
	if (len_a-- > 3 && !is_sorted(*a))
		push(b, a, "pb");
	while (len_a-- > 3 && !is_sorted(*a))
	{
		set_index_both_stack(*a,*b);
		find_target_a(*a, *b);
		calc_all_push_costs(*a,*b);
		mark_cheapest_node(*a);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_index_both_stack(*a,*b);
		find_target_b(*a, *b);
		move_b_to_a(a, b);
	}
	min_node_on_top(a);
}

void move_a_to_b(t_node **a, t_node **b){
    t_node *cheapest_node = find_cheapest_node(*a);
    if (!cheapest_node)
        return;

    if (cheapest_node->best_direction == UP_UP)
		rotate_both(a, b, cheapest_node);
    else if (cheapest_node->best_direction == DOWN_DOWN)
    {
		rev_rotate_both(a, b, cheapest_node);
    }

    move_to_target(a, cheapest_node, 'a');
    move_to_target(b, cheapest_node->target_node, 'b');

    push(b, a, "pb");
}

void	move_b_to_a(t_node **a, t_node **b)
{
	move_to_target(a, (*b)->target_node, 'a');
	push(a, b, "pa");
}

void min_node_on_top(t_node **top)
{
    t_node *min_node;
    int stack_size;

    min_node = find_min_node(*top);
    stack_size = stack_len(*top);
    set_index_stack(*top);
    while ((*top) != min_node)
    {
        if (min_node->index <= (stack_size - 1) / 2)
            rotate(top, "ra");
        else
            rev_rotate(top, "rra");
    }
}


