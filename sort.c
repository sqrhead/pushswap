#include "push_swap.h"

void	bubble_sort(long *tab, int len)
{
	int 	i;
	int 	j;
    int	 	swapped;
	long	tmp;

	i = 0;
	j = 0;
	swapped = 0;
    while (i < len - 1)
	{
		j = 0;
		swapped = 1;
		while (j < len - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				swapped = 0;
			}
			j ++;
		}
		i ++;
		if (swapped == 1)
			break;
	}
}

void	sort_three(t_stack *stack)
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

void	sort_five(t_stack *stack)
{
	t_stack_node	*node;
	if (!stack || !stack->node)
		return;

	node = stack->node;
	while (stack_is_sorted(stack) == 1)
	{

	}
}