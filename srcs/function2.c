/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:41:26 by shiori            #+#    #+#             */
/*   Updated: 2024/07/03 20:05:29 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **top,char* op)
{
	t_node	*first;
	t_node	*current;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	first = *top;
	current = *top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	*top = first->next;
	current->next = first;
	first->next = NULL;
	print_operation(op);

}

void	rev_rotate(t_node **top,char* op)
{
	t_node	*current;
	t_node	*prev;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	current = *top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *top;
	*top = current;
	print_operation(op);

}
void rotate_both(t_node **a_top,t_node **b_top)
{
    rotate(a_top,"rr");
    rotate(b_top,NULL); 
}

void rev_rotate_both(t_node **a_top,t_node **b_top)
{
    rev_rotate(a_top,"rrr");
    rev_rotate(b_top,NULL); 
}

// void prep_for_push(t_node **stack_top,t_node *node,char stack_name)
// {
//     while(*stack_top!=node)
//         if(node->above_median){
//             if(stack_name=='a')
//                 rotate(stack_top,"ra");
//              else
//                 rotate(stack_top,"rb");
//             } else{
//                 if(stack_name=='a')
//                     rev_rotate(stack_top,"rra");
//                 else
//                     rev_rotate(stack_top,"rrb");
//             }
// }


void prep_for_push(t_node **stack_top, t_node *node, char stack_name) {
    if (!stack_top) {
        return;
    }
    if (!(*stack_top)) {
        return;
    }
    if (!node) {
        return;
    }

    while (*stack_top != node) {
        if (node->above_median) {
            if (stack_name == 'a') {
                rotate(stack_top, "ra");
            } else {
                rotate(stack_top, "rb");
            }
        } else {
            if (stack_name == 'a') {
                rev_rotate(stack_top, "rra");
            } else {
                rev_rotate(stack_top, "rrb");
            }
        }
    }
}

