/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:04:13 by syonekur          #+#    #+#             */
/*   Updated: 2024/02/07 23:10:04 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *top)
{
	while (top && top->next)
	{
		if (top->value > top->next->value)
			return (0);
		top = top->next;
	}
	return (1);
}

void	babblesort_a(t_stack *a)
{
	int		swapped;
	t_node	*current;

	swapped = 1;
	if (!a || !a->top)
		return ;
	while (swapped)
	{
		swapped = 0;
		current = a->top;
		while (current->next != NULL)
		{
			{
				if (current->value > current->next->value)
					swap(&current);
				swapped = 1;
			}
			rotate(&(a->top));
			current = current->next;
		}
	}
	while (is_sorted(a->top))
	{
		reverseRotate(&(a->top));
	}
}
