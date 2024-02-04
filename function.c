/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:43:07 by syonekur          #+#    #+#             */
/*   Updated: 2024/02/04 14:50:54 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **top, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = value;
	new_node->next = *top;
	*top = new_node;
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

t_node	*pop(t_stack *stack)
{
	t_node	*top_node;

	if (stack->top == NULL)
		return (NULL);
	top_node = stack->top;
	stack->top = stack->top->next;
	return (top_node);
}
