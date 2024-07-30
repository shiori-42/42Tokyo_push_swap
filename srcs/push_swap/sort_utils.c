/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:46 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/30 15:27:16 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *top)
{
	int		len;
	t_node	*current;

	if (!top)
		return (0);
	len = 0;
	current = top;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void    set_index_stack(t_node *top)
{
    int     i;
    t_node  *current;

    if (!top)
        return ;
    current = top;
    i = 0;
    while (current)
    {
        current->index = i;
        current = current->next;
        i++;
    }
}

void    set_index_both_stack(t_node *a,t_node *b)
{
	set_index_stack(a);
	set_index_stack(b);
}

void	mark_cheapest_node(t_node *top)
{
	long	cheapest_cost;
	t_node	*cheapest_node;
	t_node	*current;

	if (!top)
		return ;
	current = top;
	cheapest_cost = LONG_MAX;
	while (current)
	{
		if (current->push_cost < cheapest_cost)
		{
			cheapest_cost = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = 1;
}
