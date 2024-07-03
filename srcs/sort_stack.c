/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:39 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/03 20:41:01 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stacks(t_stack *a, t_stack *b)
{
    int len_a;

    len_a = stack_len(a->top);
    if (len_a == 4 && !is_sorted(a))
        pb(&(b->top), &(a->top));
    else if (len_a > 4 && !is_sorted(a))
    {
        pb(&(b->top), &(a->top));
        pb(&(b->top), &(a->top));
    }
    while (len_a-- > 2 && !is_sorted(a))
    {
        init_nodes_a(a->top, b->top);
        move_a_to_b(&(a->top), &(b->top));
    }
    sort_three(&(a->top));
    while (b->top)
    {
        move_b_to_a(&(a->top), &(b->top));
    }
    min_on_top(a);
}



void	move_a_to_b(t_node **a_top, t_node **b_top)
{
	t_node	*cheapst_node;

	cheapst_node = get_cheapst(*a_top);
	if (!cheapst_node || !cheapst_node->target_node)	
		return;
	if (cheapst_node->above_median && cheapst_node->target_node->above_median)
	{
		rotate_both(a_top, b_top);
	}
	else if (!cheapst_node->above_median
		&& !cheapst_node->target_node->above_median)
	{
		rev_rotate_both(a_top, b_top);
	}
	prep_for_push(a_top, cheapst_node, 'a');
	prep_for_push(b_top, cheapst_node->target_node, 'b');
	pb(b_top, a_top);
}

// void	move_b_to_a(t_node **a_top, t_node **b_top)
// {
// 	prep_for_push(a_top,(*b_top)->target_node, 'a');
// 	pa(a_top, b_top);
// }

void move_b_to_a(t_node **a_top, t_node **b_top) {
    t_node *min_node;

    min_node = find_min(*b_top);  // スタックBの中で最小のノードを見つける
    if (!min_node) {
        return;
    }

    if (!min_node->target_node) {
        return;
    }


    // スタックAとスタックBを適切な位置に回転させる
    prep_for_push(a_top, min_node->target_node, 'a');
    prep_for_push(b_top, min_node, 'b');
    pa(a_top, b_top);  // スタックBからスタックAにプッシュ
}



void min_on_top(t_stack *stack) {
    t_node *min_node;

    min_node = find_min(stack->top);
    set_index(stack->top);
    while ((stack->top) != min_node) {
        if (min_node->above_median)
            rotate(&(stack->top),"ra");
        else
            rev_rotate(&(stack->top),"rra");
    }
}

t_node *get_cheapst(t_node *top){
	t_node *current;
	
	current=top;
	while(current){
		if(current->cheapst==1){
			return (current);
		}
		current=current->next;
	}
	return NULL;
}