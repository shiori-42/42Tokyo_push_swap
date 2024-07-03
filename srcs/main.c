/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:58:36 by shiori            #+#    #+#             */
/*   Updated: 2024/07/03 20:35:39 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
    char **splited_argv;

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
			swap(&(a->top),"sa");
		else if (stack_len(a->top) == 3)
			sort_three(&(a->top));
		else
			sort_stacks(a, b);
		free_stacks(a);
		free_stacks(b);    
        if (splited_argv)
        {
            int i = 0;
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
