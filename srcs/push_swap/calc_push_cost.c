/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_push_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:21:57 by shiori            #+#    #+#             */
/*   Updated: 2024/08/01 23:13:10 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calc_push_cost(t_node *a, int len_a, int len_b)
{
    int cost_up_up;
    int cost_down_down;
    int cost_up_down;
    int cost_down_up;

    cost_up_up = calc_cost_up_up(a);
    cost_down_down = calc_cost_down_down(a, len_a, len_b);
    cost_up_down = calc_cost_up_down(a, len_b);
    cost_down_up = calc_cost_down_up(a, len_a);

    a->push_cost = ft_min(ft_min(cost_up_up, cost_down_down), ft_min(cost_up_down, cost_down_up));

    if (a->push_cost == cost_up_up) a->best_direction = UP_UP;
    else if (a->push_cost == cost_down_down) a->best_direction = DOWN_DOWN;
    else if (a->push_cost == cost_up_down) a->best_direction = UP_DOWN;
    else a->best_direction = DOWN_UP;
}

void calc_all_push_costs(t_node *a, t_node *b)
{
    t_node *current;
    int len_a;
    int len_b;

    current = a;
    len_a = stack_len(a);
    len_b = stack_len(b);
    while (current)
    {
        calc_push_cost(current, len_a, len_b);
        current = current->next;
    }
}