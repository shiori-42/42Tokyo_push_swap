/* ************************************************************************** */
/*                     *stack                                                       */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:39 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/05 14:39:47 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len((*a));
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a((*a) ,(*b));
		move_a_to_b(a,b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b((*a) ,(*b));
		move_b_to_a(a,b);
	}
	set_index(*a);
	min_on_top(a);
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		rotate_both(a, b,cheapest_node);
	}
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
	{
		rev_rotate_both(a, b,cheapest_node);
	}
	move_to_target(a, cheapest_node, 'a');
	move_to_target(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	move_to_target(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	min_on_top(t_node **top)
{
	t_node	*min_node;

	min_node = find_min(*top);
	set_index(*top);
	while ((*top) != min_node)
	{
		if (min_node->above_median)
			rotate(top, "ra");
		else
			rev_rotate(top, "rra");
	}
}

t_node	*get_cheapest(t_node *top)
{
	t_node	*current;

	if(!top)
		return(NULL);
	current = top;
	while (current)
	{
		if (current->cheapest == 1)
			return (current);
		current = current->next;
	}
	return (NULL);
}
