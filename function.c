/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:43:07 by syonekur          #+#    #+#             */
/*   Updated: 2024/06/28 22:30:57 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **top, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->num = num;
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
	print_operation("sa");
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
	print_operation("ra");
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
	print_operation("rra");
}

int	pop(t_node **top)
{
	int		num;
	t_node	*tmp;

	if (*top == NULL)
		return (-1);
	num = (*top)->num;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
	return (num);
}
