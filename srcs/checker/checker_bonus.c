/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:13:39 by shiori            #+#    #+#             */
/*   Updated: 2024/07/06 18:40:11 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char **argv)
{
    t_node *a = NULL;
    t_node *b = NULL;

    if (run_push_swap(&a, &b, argc, argv)) {
        free_stack(&a);
        free_stack(&b);
        return 1;
    }
    if (is_sorted(a) && !b)
        printf("OK\n");
    else
        printf("KO\n");

    free_stack(&a);
    free_stack(&b);
    return 0;
}