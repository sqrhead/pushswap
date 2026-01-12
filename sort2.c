#include "push_swap.h"


void	sort_low(t_stack *stacka, t_stack *stackb, int n_elements)
{
	if (n_elements <= 3)
			sort_three(&stacka);
	else
			sort_five(&stacka, &stackb);
}
void	sort_high(t_stack *stacka, t_stack *stackb, int chunk_size, int chunk_index)
{
	int	lenb;

	while (chunk_index  < chunk_size)
	{
		while (chunk_contain(chunk_index, stacka) == 0)
		{
			while (stacka->node->chunk_n != chunk_index)
				rotate_a(stacka);
			push_b(stacka, stackb);
		}
		chunk_index ++;
	}
	lenb = stack_get_len(stackb);
	while (lenb > 0)
	{
		while (stackb->node->index != lenb - 1)
		{
			if (get_index(stackb, lenb -1) < lenb / 2)
				rotate_b(stackb);
			else
				reverse_rotate_b(stackb);
		}
		push_a(stacka, stackb);
		lenb = stack_get_len(stackb);
	}
}