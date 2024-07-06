/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:13:29 by shiori            #+#    #+#             */
/*   Updated: 2024/07/06 15:13:30 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int run_push_swap(t_node **a, t_node **b, int argc, char **argv) {
    if (call_load_stack(a, argc, argv))
        return 1;

    if (!is_sorted(*a)) {
        if (stack_len(*a) == 2)
            swap(a, "sa");
        else if (stack_len(*a) == 3)
            sort_three(a);
        else
            sort_stacks(a, b);
    }
    return 0;
}
