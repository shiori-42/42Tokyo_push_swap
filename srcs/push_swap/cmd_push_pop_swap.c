/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push_pop_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:43:07 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/14 15:51:52 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **to, t_node **from, char *op)
{
	int		nbr;
	t_node	*new_node;

	if (*from)
	{
		nbr = pop(from);
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->nbr = nbr;
		new_node->next = *to;
		*to = new_node;
		print_operation(op);
	}
}

int	pop(t_node **top)
{
	int		nbr;
	t_node	*tmp;

	if (*top == NULL)
		return (-1);
	nbr = (*top)->nbr;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
	return (nbr);
}

void	swap(t_node **top, char *op)
{
	t_node	*second;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	second = (*top)->next;
	(*top)->next = second->next;
	second->next = *top;
	*top = second;
	print_operation(op);
}
