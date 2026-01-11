#include "push_swap.h"

void sort_three(t_stack *stack)
{
	if (!stack || !stack->node)
		return;
	if (stack->node->value > stack->node->next->value)
		swap_a(stack);
	if (stack->node->value > stack->node->next->next->value)
		reverse_rotate_a(stack);
	if (stack->node->value > stack->node->next->value)
		swap_a(stack);
}
// 2 0 1