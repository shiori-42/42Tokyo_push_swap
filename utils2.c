/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:20:41 by syonekur          #+#    #+#             */
/*   Updated: 2024/02/04 15:42:31 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h";

void	sort_three(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->top->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
	{
		swap(&a->top);
		print_operation("sa");
	}
	else if (top > middle && middle > bottom && top > bottom)
	{
		swap(&a->top);
		print_operation("sa");
		reverserotate(&a->top);
		print_operation("rra");
	}
	else if (top > middle && middle < bottom && top > bottom)
	{
		rotate(&a->top);
		print_operation("ra");
	}
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap(&a->top);
		print_operation("sa");
		rotate(&a->top);
		print_operation("ra");
	}
	else if (top < middle && middle > bottom && top > bottom)
	{
		reverserotate(&a->top);
		print_operation("rra");
	}
}
