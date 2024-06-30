/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:24 by syonekur          #+#    #+#             */
/*   Updated: 2024/06/30 13:57:33 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *top)
{
	t_node	*current;

	current = top;
	if (!current)
		return (1);
	while (current)
	{
		if (current->num > current->next->num)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_duplicate(t_node *top, int num)
{
	t_node	*current;

	current = top;
	while (current != NULL)
	{
		if (current->num == num)
			return (1);
		current = current->next;
	}
	return (0);
}

void	append_node(t_stack *stack, int n)
{
	t_node	*new_node;

	if (!stack->top)
		return ;
	new_node = ft_lstnew(n);
	if (!new_node)
	{
		free_stack(stack);
	}
	if (!stack->top)
		stack->top = new_node;
	else
		ft_lstadd_front(&stack->top, new_node);
}

void	load_stack(t_stack *stack, char **argv)
{
	int		i;
	int		num;
	t_node	*new_node;

	i = 0;
	while (argv[i])
	{
		if (!check_synrax(argv[i]))
			free_erros(stack);
		num = ft_atoi(argv[i]);
		if (is_duplicate(stack->top, num))
			free_errors(stack);
		append_node(stack->top, num);
		i++;
	}
}

// atoi再利用オーバーフローのエラーでEXITする
