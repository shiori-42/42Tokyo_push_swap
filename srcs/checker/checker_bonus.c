/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:13:39 by shiori            #+#    #+#             */
/*   Updated: 2024/07/06 15:13:59 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void execute_cmd(t_node **a, t_node **b, char *cmd) {
    if (ft_strncmp(cmd, "sa", ft_strlen(cmd)) == 0)
        swap(a, "sa");
    else if (ft_strncmp(cmd, "pa", ft_strlen(cmd)) == 0)
        pa(b, a);
    else if (ft_strncmp(cmd, "pb", ft_strlen(cmd)) == 0)
        pb(a, b);
    else if (ft_strncmp(cmd, "ra", ft_strlen(cmd)) == 0)
        rotate(a, "ra");
    else if (ft_strncmp(cmd, "rb", ft_strlen(cmd)) == 0)
        rotate(b, "rb");
    else if (ft_strncmp(cmd, "rr", ft_strlen(cmd)) == 0) {
        rotate(a, "rr");
        rotate(b, NULL);
    } else if (ft_strncmp(cmd, "rra", ft_strlen(cmd)) == 0)
        rev_rotate(a, "rra");
    else if (ft_strncmp(cmd, "rrb", ft_strlen(cmd)) == 0)
        rev_rotate(b, "rrb");
    else if (ft_strncmp(cmd, "rrr", ft_strlen(cmd)) == 0) {
        rev_rotate(a, "rrr");
        rev_rotate(b, NULL);
    } else {
        write(2, "Error\n", 6);
        free(cmd);
        free_stack(a);
        free_stack(b);
        exit(1);
    }
}

int main(int argc, char **argv)
{
    t_node *a = NULL;
    t_node *b = NULL;
    char *cmd = NULL;

    if (run_push_swap(&a, &b, argc, argv)) {
        free_stack(&a);
        free_stack(&b);
        return 1;
    }

    while (1) {
        cmd = get_next_line(0);
        if (cmd == NULL) {
            break;
        }
        if (cmd[0] == '\n') {
            free(cmd);
            break;
        }
        execute_cmd(&a, &b, cmd);
        free(cmd);
    }

    if (is_sorted(a) && !b)
        printf("OK\n");
    else
        printf("KO\n");

    free_stack(&a);
    free_stack(&b);
    return 0;
}