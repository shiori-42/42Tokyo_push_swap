/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:43:05 by syonekur          #+#    #+#             */
/*   Updated: 2024/06/28 22:31:30 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(char *op)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a = (t_stack){NULL};
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	load_stack(&a, argv);
	if (!is_sorted(&a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
		free_stacks(&a);
		return (0);
	}
}
