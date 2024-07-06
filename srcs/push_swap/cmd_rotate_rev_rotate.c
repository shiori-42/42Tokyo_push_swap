/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:41:26 by shiori            #+#    #+#             */
/*   Updated: 2024/07/05 16:00:53 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **top, char *op)
{
	t_node	*first;
	t_node	*current;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	first = *top;
	current = *top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	*top = first->next;
	current->next = first;
	first->next = NULL;
	print_operation(op);
}

void	rev_rotate(t_node **top, char *op)
{
	t_node	*current;
	t_node	*prev;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	current = *top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *top;
	*top = current;
	print_operation(op);
}

void	rotate_both(t_node **a, t_node **b,t_node *cheapest_node)
{
	while((*a)!=cheapest_node && (*b)!=cheapest_node )
	{
		rotate(a, "rr");
		rotate(b, NULL);
		set_index((*a));
		set_index((*b));
	}
}

void	rev_rotate_both(t_node **a, t_node **b,t_node *cheapest_node)
{
	while((*a)!=cheapest_node && (*b)!=cheapest_node )
	{
		rev_rotate(a, "rrr");
		rev_rotate(b, NULL);
		set_index((*a));
		set_index((*b));
	}
}


