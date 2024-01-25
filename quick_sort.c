#include "push_swap.h"

int	stack_size(t_node *top)
{
	int	cnt;

	cnt = 0;
	while (top)
	{
		cnt++;
		top = top->next;
	}
	return (cnt);
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
	return (top);
}

void	quicksort(t_stack *a, t_stack *b, int size)
{
	int	pivot;
	int	push_cnt;
	int	i;

	if (size <= 1)
		return ;
	pivot = choose_pivot(a->top, size);
	push_cnt = 0;
	i = 0;
	while (i < size)
	{
		if (a->top->value < pivot)
		{
			push(&b->top, pop(&a->top));
			push_cnt++;
		}
		else
		{
			rotate(&a->top);
		}
		i++;
	}
	quicksort(b, a, push_cnt);
	quicksort(a, b, size - push_cnt);
	while (push_cnt--)
	{
		push(&a->top, pop(&b->top));
	}
}
