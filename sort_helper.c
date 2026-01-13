#include "push_swap.h"

void    rotate_to_target(t_stack **stack, t_stack_node *target, int pos, int len)
{
    while ((*stack)->node != target)
    {
        if (pos <= len / 2)
            rotate_a(*stack);
        else
            reverse_rotate_a(*stack);
    }
}