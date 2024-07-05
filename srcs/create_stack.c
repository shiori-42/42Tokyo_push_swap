/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:03:33 by shiori            #+#    #+#             */
/*   Updated: 2024/07/05 15:26:43 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_node **top, int n)
{
	t_node	*new_node;
	t_node	*current;

	if(!top)
		return;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->next=NULL;
	new_node->nbr=n;
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
void	move_to_target(t_node **top, t_node *node, char stack_name)
{
	while (*top != node)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				rotate(top, "ra");
			else
				rev_rotate(top, "rra");
		}
		else if (stack_name == 'b') 
		{
			if (node->above_median)
				rotate(top, "rb");
			else
				rev_rotate(top, "rrb");
		}
	}
}
void	load_stack(t_node **a, char **argv)
{
	long n;
    int	i;

	i = 0;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
        if (n > INT_MAX || n < INT_MIN) 
            free_stack(a);
		if (is_duplicate((*a), n))
            free_stack(a);
		append_node(a,n);
		i++;
	}
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
