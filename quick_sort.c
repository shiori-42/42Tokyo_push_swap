/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:32:29 by syonekur          #+#    #+#             */
/*   Updated: 2024/02/04 15:44:25 by syonekur         ###   ########.fr       */
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

int	find_pivot(t_stack *stack, int size)
{
	t_node	*current;
	int		*values;
	int		i;
	int		pivot;

	values = malloc(sizeof(int) * size);
	if (!values)
		exit(EXIT_FAILURE);
	current = stack->top;
	i = 0;
	while (i < size)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	pivot = values[size / 2];
	free(values);
	return (pivot);
}

void	quick_sort(t_stack *a, t_stack *b, int size)
{
	int	pivot;
	int	push_cnt;
	int	i;

	if (size <= 3)
	{
		void	sort_three(a, size);
		return ;
	}
	pivot = find_pivot(a, size);
	push_cnt = 0;
	i = 0;
	while (i < size)
	{
		if (a->top->value < pivot)
		{
			push(b, pop(a));
			print_operation("pb");
			push_cnt++;
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
