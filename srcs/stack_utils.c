/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:46 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/03 20:33:41 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *stack)
{
	t_node *current;
	t_node *next;

	if (!stack)
        return;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
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
	t_node	*current;
	t_node	*max_node;

	if (!top)
		return NULL;
	max_node = top;
	current = top;
	while (current)
	{
		if (current->num > max_node->num)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node *find_min(t_node *top) {
    t_node *min_node = top;
    t_node *current = top;

    if (!top) {
        return NULL;
    }

    while (current) {
        if (current->num < min_node->num)
            min_node = current;
        current = current->next;
    }

    return min_node;
}


void print_operation(char *op)
{
	if(!op)
		return;
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}