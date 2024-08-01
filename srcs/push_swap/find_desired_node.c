/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_desired_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:01:46 by shiori            #+#    #+#             */
/*   Updated: 2024/08/01 22:39:21 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node(t_node *top)
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

t_node	*find_min_node(t_node *top)
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

t_node	*find_cheapest_node(t_node *top)
{
	t_node	*current;

	if (!top)
		return (NULL);
	current = top;
	while (current)
	{
		if (current->is_cheapest == 1)
			return (current);
		current = current->next;
	}
	return (NULL);
}