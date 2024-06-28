# include "push_swap.h"

void sort_three(t_node *top) {
    t_node *biggest_node;
    t_node *current;

    biggest_node = find_max(top);
    current = top; 
    if (biggest_node == current)
        ra(top);
    else if (current->next == biggest_node)
        rra(top);
    if (current->num > current->next->num)
        sa(top);
}

t_node *find_max(t_node *top) {
    t_node *current;
    t_node *max_node;

    current = top;
    max_node = current;
    while (current != NULL) {
        if (current->num > max_node->num) {
            max_node = current;
        }
        current = current->next;
    }

    return max_node;
}




