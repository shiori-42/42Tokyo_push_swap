/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:32:08 by shiori            #+#    #+#             */
/*   Updated: 2024/07/05 15:17:46 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*max_node;

	max_node = find_max(*a);
	if (max_node == *a)
		rotate(a,"ra");
	else if ((*a)->next == max_node)
		rev_rotate(a,"rra");
	if ((*a)->nbr > (*a)->next->nbr)
		swap(a,"sa");
}
