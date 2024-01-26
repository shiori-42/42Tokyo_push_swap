/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:43:05 by syonekur          #+#    #+#             */
/*   Updated: 2024/01/26 23:32:58 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(char *op)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}

void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	is_duplicate(t_node *top, int num)
{
	t_node	*current;

	current = top;
	while (current != NULL)
	{
		if (current->value == num)
			exit_with_error();
		current = current->next;
	}
	return ;
}

void	load_stack(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi_int(argv[i]);
		is_duplicate(stack->top, num);
		push(&stack->top, num);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit_with_error();
	a = (t_stack){NULL};
	b = (t_stack){NULL};
	load_stack(&a, argc, argv);
	quick_sort(&a, &b, argc - 1);
	return (0);
}
