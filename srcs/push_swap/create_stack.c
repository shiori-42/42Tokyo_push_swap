/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:35:33 by syonekur          #+#    #+#             */
/*   Updated: 2024/08/02 21:39:32 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_node **top, int n)
{
	t_node	*new_node;

	if (!top)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->nbr = n;
	new_node->is_cheapest = 0;
	new_node->next = *top;
	*top = new_node;
}

void	load_stack(t_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (check_comandline_args(argv[i]))
			free_errors(a);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (is_duplicate((*a), n))
			free_errors(a);
		append_node(a, n);
		i--;
	}
}

int	call_load_stack(t_node **a, int argc, char **argv)
{
	char	**splited_argv;
	int		i;

	splited_argv = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
	{
		splited_argv = ft_split(argv[1], ' ');
		load_stack(a, splited_argv);
		i = 0;
		while (splited_argv[i])
			free(splited_argv[i++]);
		free(splited_argv);
	}
	else
		load_stack(a, argv + 1);
	return (0);
}

int	is_sorted(t_node *top)
{
	t_node	*current;

	if (!top)
		return (1);
	current = top;
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}
