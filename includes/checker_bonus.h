/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:23:34 by syonekur          #+#    #+#             */
/*   Updated: 2024/08/02 21:34:54 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/get_next_line.h"
# include "push_swap.h"
# include <stdlib.h>
# include <unistd.h>

int		run_push_swap(t_node **a, t_node **b, int argc, char **argv);
void	execute_cmd_2(t_node **a, t_node **b, char *cmd);

#endif
