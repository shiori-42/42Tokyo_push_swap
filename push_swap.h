/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:12:40 by syonekur          #+#    #+#             */
/*   Updated: 2024/02/07 23:14:07 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

void				exit_with_error(void);
void				load_stack(t_stack *stack, int argc, char **argv);
void				push(t_node **top, int value);
int					pop(t_node **top);
void				rotate(t_node **top);
void				reverserotate(t_node **top);
int					ft_atoi_int(char *str);
size_t				ft_strlen(char *str);
void				print_operation(char *op);

#endif
