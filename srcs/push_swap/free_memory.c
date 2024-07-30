/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:18:18 by shiori            #+#    #+#             */
/*   Updated: 2024/07/30 14:18:28 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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