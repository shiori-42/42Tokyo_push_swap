/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:46 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/05 20:45:04 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *top)
{
	int		len;
	t_node	*current;

	if(!top)
		return(0);
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
		return (NULL);
	max_node = top;
	current = top->next;
	while (current)
	{
		if (current->nbr > max_node->nbr)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node	*find_min(t_node *top)
{
	t_node	*current;
	t_node	*min_node;

	if (!top)
		return (NULL);
	min_node = top;
	current = top->next;
	while (current)
	{
		if (current->nbr < min_node->nbr)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	set_index(t_node *top)
{
	int		i;
	int		median;
	t_node	*current;

	if (!top)
		return ;
	i = 0;
	current = top;
	median = stack_len(top) / 2;
	while (current)
	{
		current->index = i;
		if (i <= median)
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
		i++;
	}
}
void	find_cheapest(t_node *top)
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

