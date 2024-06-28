/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:46 by syonekur          #+#    #+#             */
/*   Updated: 2024/06/28 22:32:02 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	while ((*stack)->top)
	{
		pop(&(*stack)->top);
	}
	free(*stack);
	*stack=NULL;
}

int	stack_len(t_node *top)
{
	int		len;
	t_node	*current;

	len = 0;
	current = top;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

t_node	*find_max(t_node *top)
{
	t_node	*max_node;
	t_node	*current;

	max_node = top;
	current = top->next;
	while (current)
	{
		if (current->num > max_node->num)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node	*find_min(t_stack *stack)
{
	long	min;
	t_node	*current;
	t_node	*min_node;

	current = stack->top;
	if (!current)
	{
		return (NULL);
	}
	min = LONG_MAX;
	while (current)
	{
		if (current->num < min)
		{
			min = current->num;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}
