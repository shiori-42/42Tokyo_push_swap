/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiori <shiori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:58:36 by shiori            #+#    #+#             */
/*   Updated: 2024/07/05 21:29:31 by shiori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a =NULL;
	b =NULL;
	
	if(call_load_stack(&(a),argc,argv))
		return(1);
	if (!is_sorted(a))
	{
		
		if (stack_len(a) == 2)
			swap(&(a), "sa");
		else if (stack_len(a) == 3)
			sort_three(&(a));
		else
			sort_stacks(&(a), &(b));
		free_stack(&(a));
		return (0);
	}
}
