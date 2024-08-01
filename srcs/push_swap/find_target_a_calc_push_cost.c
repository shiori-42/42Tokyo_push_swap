/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_a_calc_push_cost.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:26 by syonekur          #+#    #+#             */
/*   Updated: 2024/08/01 23:02:33 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	closest_smaller_value;

	while (a)
	{
		closest_smaller_value = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > closest_smaller_value)
			{
				closest_smaller_value = current_b->nbr;
				target_node = current_b;
			
			current_b = current_b->next;
		}
		if (closest_smaller_value == LONG_MIN)
			a->target_node = find_max_node(b);
		else
			a->target_node = target_node;
		}	
		calc_push_cost(a,b);	
		a = a->next;
	}
}
