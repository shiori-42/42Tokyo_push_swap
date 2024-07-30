/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:03:33 by shiori            #+#    #+#             */
/*   Updated: 2024/07/30 14:45:31 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_node **top, int n)
{
	t_node	*new_node;
	t_node	*current;

	if (!top)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = n;
	if ((*top) == NULL)
		*top = new_node;
	else
	{
		current = *top;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

void	load_stack(t_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_comandline_args(argv[i]))
			free_errors(a);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (is_duplicate((*a), n))
			free_errors(a);
		append_node(a, n);
		i++;
	}
}
