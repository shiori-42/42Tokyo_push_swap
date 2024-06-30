/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:41 by syonekur          #+#    #+#             */
/*   Updated: 2024/06/30 13:57:11 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node *top)
{
	t_node	*biggest_node;
	t_node	*current;

	biggest_node = find_max(top);
	current = top;
	if (biggest_node == current)
		ra(top);
	else if (current->next == biggest_node)
		rra(top);
	if (current->num > current->next->num)
		sa(top);
}

