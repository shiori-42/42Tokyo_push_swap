/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:32:29 by syonekur          #+#    #+#             */
/*   Updated: 2024/01/26 23:23:22 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *top)
{
	int	cnt;

	cnt = 0;
	while (top)
	{
		cnt++;
		top = top->next;
	}
	return (cnt);
}

t_node	*choose_pivot(t_node *top, int size)
{
	int	i;
	int	middle;

	i = 0;
	middle = size / 2;
	while (i < middle)
	{
		top = top->next;
		i++;
	}
	return (top);
}

void	quick_sort(t_stack *a, t_stack *b, int size)
{
	t_node	*pivot;
	int		push_cnt;
	int		i;

	if (size <= 1)
		return ;
	pivot = choose_pivot(a->top, size);
	push_cnt = 0;
	i = 0;
	while (i < size)
	{
		if (a->top->value < pivot->value)
		{
			push(&b->top, pop(&a->top));
			print_operation("pb");
			push_cnt++;
		}
		else
		{
			rotate(&a->top);
			print_operation("ra");
		}
		i++;
	}
	quick_sort(b, a, push_cnt);
	quick_sort(a, b, size - push_cnt);
	while (push_cnt--)
	{
		push(&a->top, pop(&b->top));
	}
}
