/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push_pop_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:43:07 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/05 15:17:53 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **top, int nbr, char *op)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->nbr = nbr;
	new_node->next = *top;
	*top = new_node;
	print_operation(op);
}

void	pb(t_node **b, t_node **a)
{
	int	nbr;

	if (*a)
	{
		nbr = pop(a);
		push(b, nbr, "pb");
	}
}

void	pa(t_node **a, t_node **b)
{
	int	nbr;

	if (*b)
	{
		nbr = pop(b);
		push(a, nbr, "pa");
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
