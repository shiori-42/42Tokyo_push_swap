#include "push_swap.h"

int	stack_size(t_node *top)
{
	int	count;

	coutnt = 0;
	while (top)
	{
		coutnt++;
		top = top->next;
	}
	return (count);
}

int	choose_pivot(t_node *top, int size)
{
	int	i;
	int	middle;

	i = 0;
	middle = size / 2;
	while (i < middle)
	{
		top = top->next;
		i++;
	}
	return (top->next)
}

void	quicksort(t_stack *a, t_stack *b, int size)
{
	int	pivot;
	int	push_count;
	int	i;

	if (size <= 1)
		return ;
	pivot = choose_pivot(a->top, size);
	push_count = 0;
	i = 0;
	while (i<size)
    {
        if(a->topvalue<pivot)
        {
            push(&b->top,)
        }
    }
}
