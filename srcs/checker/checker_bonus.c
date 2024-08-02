/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:53:49 by shiori            #+#    #+#             */
/*   Updated: 2024/08/02 22:53:37 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	execute_cmd(t_node **a, t_node **b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", ft_strlen(cmd)) == 0)
		swap(a, NULL);
	else if (ft_strncmp(cmd, "sb\n", ft_strlen(cmd)) == 0)
		swap(b, NULL);
	else if (ft_strncmp(cmd, "ss\n", ft_strlen(cmd)) == 0)
	{
		swap(a, NULL);
		swap(b, NULL);
	}
	else if (ft_strncmp(cmd, "pa\n", ft_strlen(cmd)) == 0)
		push(a, b, NULL);
	else if (ft_strncmp(cmd, "pb\n", ft_strlen(cmd)) == 0)
		push(b, a, NULL);
	else if (ft_strncmp(cmd, "ra\n", ft_strlen(cmd)) == 0)
		rotate(a, NULL);
	else if (ft_strncmp(cmd, "rb\n", ft_strlen(cmd)) == 0)
		rotate(b, NULL);
	else
		execute_cmd_2(a, b, cmd);
}

void	execute_cmd_2(t_node **a, t_node **b, char *cmd)
{
	if (ft_strncmp(cmd, "rr\n", ft_strlen(cmd)) == 0)
	{
		rotate(a, NULL);
		rotate(b, NULL);
	}
	else if (ft_strncmp(cmd, "rra\n", ft_strlen(cmd)) == 0)
		rev_rotate(a, NULL);
	else if (ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)) == 0)
		rev_rotate(b, NULL);
	else if (ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)) == 0)
	{
		rev_rotate(a, NULL);
		rev_rotate(b, NULL);
	}
	else
	{
		write(2, "Error\n", 6);
		free(cmd);
		free_stack(a);
		free_stack(b);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*cmd;

	a = NULL;
	b = NULL;
	if (call_load_stack(&a, argc, argv))
		return (1);
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
		{
			break ;
		}
		execute_cmd(&a, &b, cmd);
		free(cmd);
	}
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
