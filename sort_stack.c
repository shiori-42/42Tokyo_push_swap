/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:39 by syonekur          #+#    #+#             */
/*   Updated: 2024/06/30 13:49:12 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack *a, t_stack *b)
{
	int	len_a;

	len_a = stack_len(a);
	if (len_a-- > 3 && !is_sorted(a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted(a))
		pb(b, a);
	while (len_a-- > 3 && !is_sorted(a))
	{
		init_nodes(a->top, b->top);
		move_a_to_b(a, b);
	}
	sort_three(a->top);
	while (b->top)
	{
		init_nodes(a->top, b->top);
		move_b_to_a(a, b);
	}
	assign_index(a->top);
	min_on_top(a);
}

int	find_min_index(t_node *top)
{
	t_node	*current;
	int		min_index;

	current = top;
	min_index = current->index;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
		}
		current = current->next;
	}
	return (min_index);
}

void	move_a_to_b(t_node *a_top, t_node *b_top)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(a_top);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		rotate_both(&a_top, &b_top);
	}
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
	{
		rev_rotate_both(&a_top, &b_top);
	}
	prep_for_push(&a_top, cheapest_node, 'a');
	prep_for_push(&b_top, cheapest_node, 'b');
	pb(&b_top, &a_top);
}

void	move_b_to_a(t_node *a_top, t_node *b_top)
{
	prep_for_push(&a_top, b_top->target_node, 'a');
	pa(&a_top, &b_top);
}


void min_on_top(t_node *top)
{
    t_node *min_node = find_min(top);
	set_index(top);
    while (top != min_node)
    {
        if (min_node->above_median)
            ra(top);
        else
            rra(top);
    }
}



get_cheapest実装する