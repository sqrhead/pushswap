#include "push_swap.h"

int	check_duplicate(long *tab, int size)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (index < size)
	{
		j = 0;
		while (j < size)
		{
			if (index != j && tab[index] == tab[j])
				return (1);
			j ++;
		}
		index ++;
	}
	return (0);
}

t_stack *stack_clone(t_stack *stack)
{
	t_stack			*stackc;
	t_stack_node	*tmp;

	if (!stack || !stack->node)
		return (NULL);
	stackc = (t_stack *)malloc(sizeof(t_stack));
	if (!stackc)
		return (NULL);
	tmp = stack->node;
	while (tmp)
	{
		stack_new_node(&stack, node_new(tmp->value, tmp->chunk_n));
		tmp = tmp->next;
	}
	return (stackc);
}