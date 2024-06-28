#include "push_swap.h"

void sort_stacks(t_stack *a, t_stack *b) {
    int len_a;

    len_a = stack_len(a);
    if (len_a-- > 3 && !is_sorted(a))
        pb(b, a);
    if (len_a-- > 3 && !is_sorted(a))
        pb(b, a);
    while (len_a-- > 3 && !is_sorted(a)) {
        init_nodes(a->top, b->top);
        move_a_to_b(a, b);
    }
    sort_three(a->top);
    while (b->top) {
        init_nodes(a->top, b->top);
        move_b_to_a(a, b);
    }
    assign_index(a->top);
    min_on_top(a);
}


void min_on_top(t_node *top) {
    int min_index;

    min_index = find_min_index(top);
    while (top->index != min_index) {
        if (top->index > min_index) {
            ra(top);
        } else {
            rra(top);
        }
    }
}

int find_min_index(t_node *top) {
    t_node *current;
    int min_index;

    current = top;
    min_index = current->index;
    while (current) {
        if (current->index < min_index) {
            min_index = current->index;
        }
        current = current->next;
    }
    return min_index;
}
