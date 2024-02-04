/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:43:07 by syonekur          #+#    #+#             */
/*   Updated: 2024/02/04 15:45:51 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	int		value;
	t_node	*new_node;

	if (from->top == NULL)
		return ;
	value = pop(from);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = value;
	new_node->next = to->top;
	to->top = new_node;
}

void	swap(t_node **top)
{
	t_node	*second;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	second = (*top)->next;
	(*top)->next = second->next;
	second->next = *top;
	*top = second;
}

void	rotate(t_node **top)
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
}

void	reverserotate(t_node **top)
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
}

int	pop(t_stack *stack)
{
	t_node	*top_node;
	int		value;

	if (stack->top == NULL)
		return (INT_MIN);
	top_node = stack->top;
	value = top_node->value;
	stack->top = top_node->next;
	free(top_node);
	return (value);
}
