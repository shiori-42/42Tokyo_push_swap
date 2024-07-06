#ifndef CHECKER_H
#define CHECKER_H

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "get_next_line.h"

int run_push_swap(t_node **a, t_node **b, int argc, char **argv);
void print_stack(t_node *top);  // 追加

#endif
