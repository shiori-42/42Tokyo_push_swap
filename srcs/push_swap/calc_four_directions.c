/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_four_directions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:25:18 by shiori            #+#    #+#             */
/*   Updated: 2024/07/30 14:25:22 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_cost_up_up(t_node *a)
{
    return ft_max(a->index, a->target_node->index);
}

int calc_cost_down_down(t_node *a, int len_a, int len_b)
{
    return ft_max(len_a - a->index, len_b - a->target_node->index);
}

int calc_cost_up_down(t_node *a, int len_b)
{
    return a->index + (len_b - a->target_node->index);
}

int calc_cost_down_up(t_node *a, int len_a)
{
    return (len_a - a->index) + a->target_node->index;
}