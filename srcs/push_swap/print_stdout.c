/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stdout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:47:57 by shiori            #+#    #+#             */
/*   Updated: 2024/08/02 21:40:40 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(char *op)
{
	if (!op)
		return ;
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}
