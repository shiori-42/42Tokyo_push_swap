/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:32:08 by shiori            #+#    #+#             */
/*   Updated: 2024/07/03 20:12:10 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **top) {
    if (!top || !(*top) || !(*top)->next || !(*top)->next->next) {
        return;
    }

    t_node *first = *top;
    t_node *second = first->next;
    t_node *third = second->next;

    if (first->num > second->num && first->num > third->num) {
        rotate(top,"ra");
    }
    if (second->num < first->num && second->num < third->num) {
        rev_rotate(top,"rra");
    }
    if (first->num > second->num) {
        swap(top,"sa"); 
    }
}
