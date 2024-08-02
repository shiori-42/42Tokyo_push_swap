/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:26:41 by shiori            #+#    #+#             */
/*   Updated: 2024/08/02 22:17:54 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_target(t_node **top, t_node *target_node, char stack_name)
{
	int	stack_size;
	int	target_index;

	target_index = target_node->index;
	stack_size = stack_len(*top);
	while (*top != target_node)
	{
		if (stack_name == 'a')
		{
			if (target_index <= (stack_size - 1) / 2)
				rotate(top, "ra");
			else
				rev_rotate(top, "rra");
		}
		else if (stack_name == 'b')
		{
			if (target_index <= (stack_size - 1) / 2)
				rotate(top, "rb");
			else
				rev_rotate(top, "rrb");
		}
	}
}
