/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:57:36 by shiori            #+#    #+#             */
/*   Updated: 2024/07/30 14:18:12 by shiori           ###   ########.fr       */
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


