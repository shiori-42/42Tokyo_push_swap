/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:00:05 by shiori            #+#    #+#             */
/*   Updated: 2024/07/30 21:01:32 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;

	current_a=a;
	long	best_match_index;

	best_match_index = LONG_MAX;
	while (current_a)
	{
		if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
		{
			best_match_index = current_a->nbr;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	if (best_match_index == LONG_MAX)
		b->target_node = find_min_node(a);
	else
		b->target_node = target_node;
}
