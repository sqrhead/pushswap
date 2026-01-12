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

t_stack_node	*get_node(t_stack *stack, size_t index)
{
	size_t				i;
	t_stack_node	*tmp;

	if (!stack || !stack->node)
		return (NULL);
	i = 0;
	tmp = stack->node;
	while (tmp)
	{
		if (i == index)
		{
			return (tmp);
		}
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}

size_t	get_index(t_stack *stack, int value)
{
	size_t			index;
	t_stack_node	*node;

	if (!stack || !stack->node)
		return (-1);
	index = 0;
	node = stack->node;
	while (node)
	{
		if (node->index == value)
			return (index);
		node = node->next;
		index ++;
	}
	return (-1);
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack_node *node;

	if (!stack || !stack->node)
		return (-1);
	node = stack->node;
	while (node)
	{
		if (node->next && node->value > node->next->value)
			return (1);
		node = node->next;
	}
	return (0);
}

