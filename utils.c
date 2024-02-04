/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:31:47 by syonekur          #+#    #+#             */
/*   Updated: 2024/02/04 14:32:53 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_overflow_and_underflow(char *s, int sign)
{
	int	ans;

	ans = 0;
	while (*s >= '0' && *s <= '9')
	{
		if (sign == 1 && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (*s
						- '0') >= INT_MAX % 10)))
			exit_with_error();
		if (sign == -1 && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (*s
						- '0') >= INT_MAX % 10 + 1)))
			exit_with_error();
		ans = ans * 10 + (*s - '0');
		s++;
	}
	return (ans * sign);
}

int	ft_atoi_int(char *str)
{
	int		sign;
	long	ans;
	char	*current;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!*str)
		exit_with_error();
	current = str;
	while (*str)
	{
		if (*str <= '0' && *str >= '9')
			exit_with_error();
		str++;
	}
	ans = check_overflow_and_underflow(current, sign);
	return ((int)ans);
}
