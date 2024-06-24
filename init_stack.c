# include "push_swap.h" 

int is_sorted(t_stack *stack){

    t_node *current;
    
    current=stack->top;
    if(!current)
        return(1);
    while(current)
    {
        if(current->num >cuurent->next->num)
            return(1);
        current=cuurent->next;
    }
    return (0);
    
}

int	is_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		if (current->num == num)
			return(1);
		current = current->next;
	}
	return(0);
}

void append_node(t_stack *stack,int n){
    t_node *new_node;
    if(!stack)
        return;
    		new_node = ft_lstnew(n);
		if (!new_node)
		{
			exit_with_error();
		}
		if (!stack->top)
			stack->top = new_node;
		else
			ft_lstadd_front(&stack->top, new_node);

}

void	load_stack(t_stack *stack,  char **argv)
{
	int		i;
	int		num;
	t_node	*new_node;

	i = 0;
	while (argv[i])
	{
        if(!check_synrax(argv[i]))
           free_erros(stack);
		num = ft_atoi(argv[i]);
        if(is_duplicate(stack,num))
            free_errors(stack);
        append_node(stack,num);
        i++;
	}


}

//atoi再利用オーバーフローのエラーでEXITする
