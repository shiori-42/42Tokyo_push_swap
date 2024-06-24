#include "push_swap.h"

void free_stack(t_stack *stack) {
    while (stack->top) {
        pop(&stack->top);
    }
}

void free_erros(t_stack *stack) {
    while (stack->top) {
        pop(&stack->top);
    }
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_node *find_min(t_stack *stack){
    long min;
    t_node *current;
    t_node *min_node;

    current=stack->top;

    if(!current){
        return (NULL);
    }
    min=LONG_MAX;
    while(current){
        if(current->num<min)
        {
            min=current->num;
            min_node=current;
        }
        current=current->next;
    }
    return (min_node);
}
