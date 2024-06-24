# include "push_swap.h"

void sort_three(t_stack *stack){
    t_node *biggest_node;
    t_node *current;

    biggest_node=find_max(stack);
    current=stack->top; 
    if(biggest_node==current)
        ra(stack);// 最も大きいノードがトップにある場合、1つ上に回転
    else if(current->next==biggest_node)
        rra(stack);// 最も大きいノードが2番目にある場合、1つ下に回転
    if(current->num > current->next->num)
        sa(stack);// トップのノードが2番目のノードより大きい場合、トップ2つを交換
}


// スタックの中で最も大きいノードを探す関数の定義
t_node *find_max(t_stack *stack) {
    t_node *current = stack->top;
    t_node *max_node = current;

    while (current != NULL) {
        if (current->value > max_node->value) {
            max_node = current;
        }
        current = current->next;
    }

    return max_node;
}
