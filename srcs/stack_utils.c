/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:46 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/05 15:17:53 by shiori           ###   ########.fr       */
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
		current = current->next;
		len++;
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
	current = top;
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
	current = top;
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

	i = 0;
	if (!top)
		return ;
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

void	calc_cost_for_push_a(t_node *a, t_node *b)
{
	int		len_a;
	int		len_b;
	t_node	*current_a;

	len_a = stack_len(a);
	len_b = stack_len(b);
	current_a = a;
	while (current_a)
	{
		current_a->push_cost = current_a->index;
		if (!(current_a->above_median))
			current_a->push_cost = len_a - (current_a->index);
		if (current_a->target_node->above_median)
			current_a->push_cost += current_a->target_node->index;
		else
			current_a->push_cost += len_b - (current_a->target_node->index);
		current_a = current_a->next;
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


void	print_operation(char *op)
{
	if (!op)
		return ;
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}
void	free_stack(t_node **top)
{
	t_node	*tmp;
	t_node	*current;

	if (!top)
		return ;
	current = *top;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*top= NULL;
}
int	is_duplicate(t_node *top, int nbr)
{
	t_node	*current;

	current = top;
	while (current)
	{
		if (current->nbr == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}