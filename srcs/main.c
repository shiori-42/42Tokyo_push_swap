/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:58:36 by shiori            #+#    #+#             */
/*   Updated: 2024/07/03 21:15:52 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**splited_argv;
	int		i;

	a = &((t_stack){NULL});
	b = &((t_stack){NULL});
	splited_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		splited_argv = ft_split(argv[1], ' ');
	if (argc == 2)
		load_stack(a, splited_argv);
	else
		load_stack(a, argv + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a->top) == 2)
			swap(&(a->top), "sa");
		else if (stack_len(a->top) == 3)
			sort_three(&(a->top));
		else
			sort_stacks(a, b);
		free_stacks(a);
		free_stacks(b);
		if (splited_argv)
		{
			i = 0;
			while (splited_argv[i])
			{
				free(splited_argv[i]);
				i++;
			}
			free(splited_argv);
		}
		return (0);
	}
}


void	init_nodes_a(t_node *a_top, t_node *b_top)
{
	set_index(a_top);
	set_index(b_top);
	set_target_a(a_top, b_top);
	cost_analysis_a(a_top, b_top);
	set_cheapst(a_top);
}

void	init_nodes_b(t_node *a_top, t_node *b_top)
{
	set_index(a_top);
	set_index(b_top);
	set_target_b(a_top, b_top);
}
