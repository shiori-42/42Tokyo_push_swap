/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:32:08 by shiori            #+#    #+#             */
/*   Updated: 2024/07/03 21:03:30 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **top)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!top || !(*top) || !(*top)->next || !(*top)->next->next)
	{
		return ;
	}
	first = *top;
	second = first->next;
	third = second->next;
	if (first->num > second->num && first->num > third->num)
	{
		rotate(top, "ra");
	}
	if (second->num < first->num && second->num < third->num)
	{
		rev_rotate(top, "rra");
	}
	if (first->num > second->num)
	{
		swap(top, "sa");
	}
}
