/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:24 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/03 21:13:41 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_duplicate(t_node *top, int num)
{
	t_node	*current;

	current = top;
	while (current)
	{
		if (current->num == num)
			return (1);
		current = current->next;
	}
	return (0);
}

t_node	*create_node(int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = n;
	new_node->next = NULL;
	return (new_node);
}

void	append_node(t_stack *stack, int n)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(n);
	if (!new_node)
	{
		free_stacks(stack);
		return ;
	}
	if (stack->top == NULL)
	{
		stack->top = new_node;
	}
	else
	{
		current = stack->top;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

void	load_stack(t_stack *stack, char **argv)
{
	int	i;
	int	num;

	i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (is_duplicate(stack->top, num))
		{
			free_stacks(stack);
			return ;
		}
		append_node(stack, num);
		i++;
	}
}
