/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:42:30 by shiori            #+#    #+#             */
/*   Updated: 2024/07/05 20:58:53 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	print_operation(char *op)
{
	if (!op)
		return ;
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}
