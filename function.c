#include "push_swap.h"

void	push(t_node **top, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = value;
	new_node->next = *top;
	top = new_mode;
}

void	swap(t_node **top)
{
	t_node	*second;

	if (*top = NULL || (*top)->next == NULL)
		return ;
	second = (*top)->next;
	(*top)->next = second_next;
	second_next->top;
	*top = second;
}

void	rotate(t_node **top)
{
	t_node	*first;
	t_node	*current;

	it(*top == NULL || (*top)->next == NULL) return ;
	first = *top;
	current = *top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	*top = first->next;
	current->next = first;
	first->next = NULL;
}

voide	reverserotate(t_node **top)
{
	t_node	*current;
	t_node	*prev;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	current = *top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *top;
	*top = current;
}
