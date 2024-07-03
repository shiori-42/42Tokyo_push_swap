/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:58:33 by syonekur          #+#    #+#             */
/*   Updated: 2024/07/02 15:21:51 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr( char *s, int c)
{
	while (*s)
	{
		if (*s == ( char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	char test[20] = "abcdefghijgk";
// 	char *p, *q;

// 	p = ft_strchr(test, 'g');
// 	q = ft_strchr(test, 0);
// 	printf("test;g:%s\n", p);
// 	printf("test0:%s\n", q);
// 	return (0);
// }