#ifndef PUSH_SWAP.H
#define   PUSH_SWAP.H

#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
    t_node *top;
}s_stack;



#endif

