/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:43:07 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/03 21:10:38 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **top, int num, char *op)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->next = *top;
	*top = new_node;
	print_operation(op);
}

void	pb(t_node **b_top, t_node **a_top)
{
	int	num;

	if (*a_top)
	{
		num = pop(a_top);
		push(b_top, num, "pb");
	}
}

void	pa(t_node **a_top, t_node **b_top)
{
	int	num;

	if (*b_top)
	{
		num = pop(b_top);
		push(a_top, num, "pa");
	}
}

int	pop(t_node **top)
{
	int		num;
	t_node	*tmp;

	if (*top == NULL)
		return (-1);
	num = (*top)->num;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
	return (num);
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
