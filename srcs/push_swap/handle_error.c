/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:57:36 by shiori            #+#    #+#             */
/*   Updated: 2024/07/14 15:48:57 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_comandline_args(char *argv)
{
	int	i;

	if (!(argv[0] == '+' || argv[0] == '-' || (argv[0] >= '0'
				&& argv[0] <= '9')))
		return (1);
	if ((argv[0] == '+' || argv[0] == '-') && !(argv[1] >= '0'
			&& argv[1] <= '9'))
		return (1);
	if (argv[0] == '+' || argv[0] == '-')
		i = 1;
	else
		i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(t_node *top, int nbr)
{
	t_node	*current;

	current = top;
	while (current)
	{
		if (current->nbr == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

void	free_stack(t_node **top)
{
	t_node	*tmp;
	t_node	*current;

	if (!top || !*top)
		return ;
	current = *top;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*top = NULL;
}

void	free_errors(t_node **a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(1);
}
