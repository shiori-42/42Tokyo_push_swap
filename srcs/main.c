/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:58:36 by shiori            #+#    #+#             */
/*   Updated: 2024/07/05 15:17:53 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**splited_argv;

	a =NULL;
	b =NULL;
	splited_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		splited_argv = ft_split(argv[1], ' ');
	if (argc == 2)
		load_stack(&(a), splited_argv);
	else
		load_stack(&(a), argv + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			swap(&(a), "sa");
		else if (stack_len(a) == 3)
			sort_three(&(a));
		else
			sort_stacks(&(a), &(b));
		free_stack(&(a));
		return (0);
	}
}

