#include "push_swap.h"


/*
*/
void generate_chunks(long *tab, t_stack **stack)
{
	int				i;
	int				len;
	t_stack_node	*tmp;

	if (!*stack || !(*stack)->node)
		return;
	i = 0;
	len = stack_get_len(*stack);
	tmp = (*stack)->node;
	while (i < len - 1)
	{
		while (tmp->value != (int)tab[i])
		{
			tmp = tmp->next;
		}
		tmp->chunk_n = i;
		tmp = (*stack)->node;
		i ++;
	}
}