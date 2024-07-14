/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:47:18 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/14 20:24:08 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (call_load_stack(&(a), argc, argv))
		return (1);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			swap(&(a), "sa");
		else if (stack_len(a) == 3)
			sort_three(&(a));
		else
			sort_stacks(&(a), &(b));
	}
	free_stack(&(a));
	return (0);
}
