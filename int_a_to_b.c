#include "push_swap.h"

set_index(t_node *top) {
    int i ;
    int median;
    t_node *current;

    i=0;
    current = top;
    if (!current)
        return;
    median = stack_len_from_top(top) / 2;
    while (current) {
        current->index = i;
        if (i <= median)
            current->above_median = 1;
        else
            current->above_median = 0;
        current = current->next;
        ++i;
    }
}

void set_target_a(t_node *a_top, t_node *b_top) {
    t_node *current_a;
    t_node *current_b;
    t_node *target_node;
    long best_match_index;

    current_a = a_top;
    while (current_a) {
        best_match_index = LONG_MIN;
        current_b = b_top;
        while (current_b) {
            if (current_b->num < current_a->num && current_b->num > best_match_index) {
                best_match_index = current_b->num;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match_index == LONG_MIN)
            current_a->target_node = find_max(b_top);
        else
            current_a->target_node = target_node;
        current_a = current_a->next;
    }
}

void cost_analysis_a(t_node *a_top, t_node *b_top) {
    int len_a;
    int len_b;
    t_node *current_a;


    len_a = stack_len_from_top(a_top);
    len_b = stack_len_from_top(b_top);
    current_a = a_top;
    while (current_a) {
        current_a->push_cost = current_a->index;
        if (!(current_a->above_median))
            current_a->push_cost = len_a - current_a->index;
        if (current_a->target_node->above_median)
            current_a->push_cost += current_a->target_node->index;
        else
            current_a->push_cost += len_b - current_a->target_node->index;
        current_a = current_a->next;
    }
}

void set_cheapest(t_node *top) {
    long cheapest_cost = LONG_MAX;
    t_node *cheapest_node = NULL;
    t_node *current = top;

    cheapest_cost = LONG_MAX;
    cheapest_node = NULL;
    current = top;
    if (!current)
        return;
    while (current) {
        if (current->push_cost < cheapest_cost) {
            cheapest_cost = current->push_cost;
            cheapest_node = current;
        }
        current = current->next;
    }
    if (cheapest_node)
        cheapest_node->cheapest = 1;
}

void init_nodes_a(t_node *a_top, t_node *b_top) {
    assign_index(a_top);
    assign_index(b_top);
    set_target_a(a_top, b_top);
    cost_analysis_a(a_top, b_top);
    set_cheapest(a_top);
}

int stack_len(t_node *top) {
    int len;
    t_node *current;

    len = 0;
    current= top;
    while (current) {
        len++;
        current = current->next;
    }
    return len;
}

t_node* find_max(t_node *top) {
    t_node *max_node;
    t_node *current;

    max_node=top;
    current=top->next;
    while (current) {
        if (current->num > max_node->num)
            max_node = current;
        current = current->next;
    }
    return max_node;
}
