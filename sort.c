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

void	sort_three(t_stack **stack)
{
	int	n1;
	int	n2;
	int	n3;
	// if too long pass it outside
	if ((*stack) && (*stack)->node && stack_get_len(*stack) < 3)
	{
		if ((*stack)->node->next &&
				(*stack)->node->value > (*stack)->node->next->value)
			swap_a((*stack));
		return;
	}
	if (!(*stack) || !(*stack)->node || stack_get_len(*stack) != 3)
		return;
	n1 = (int)(*stack)->node->value;
	n2 = (int)(*stack)->node->next->value;
	n3 = (int)(*stack)->node->next->next->value;

	if (n1 < n2 && n1 > n2 && n2 > n3)
		reverse_rotate_a(*stack);
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		rotate_a(*stack);
		swap_a(*stack);
	}
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		reverse_rotate_a(*stack);
		swap_a(*stack);
	}
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		rotate_a(*stack);
	else if (n1 > n2 && n1 < n3 && n2 < n3)
		swap_a(*stack);
	else
		return;
}

int	get_smallest(t_stack *stack)
{
	t_stack_node	*node;
	int				index;
	int				retindex;
	int				min;

	if (!stack || !stack->node)
		return (-1);
	index = 0;
	retindex = 0;
	node = stack->node;
	min = node->value;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			retindex = index;
		}
		index ++;
		node = node->next;
	}
	return (retindex);
}

void	sort_five(t_stack **stacka, t_stack **stackb)
{
	int				len;
	int				pos;
	t_stack_node	*tmp;

	pos = get_smallest(*stacka);
	tmp = get_node(*stacka, (size_t)get_smallest(*stacka));
	len = stack_get_len(*stacka);
	while ((*stacka)->node != tmp)
	{
		if (pos <= len / 2)
			rotate_a(*stacka);
		else
			reverse_rotate_a(*stacka);
	}
	push_b(*stacka, *stackb);
	tmp = get_node(*stacka, (size_t)get_smallest(*stacka));
	while ((*stacka)->node != tmp)
	{
		if (pos <= len / 2)
			rotate_a(*stacka);
		else
			reverse_rotate_a(*stacka);
	}
	push_b(*stacka, *stackb);
	sort_three(stacka);
	push_a(*stacka, *stackb);
	push_a(*stacka, *stackb);
	if ((*stacka)->node->value > (*stacka)->node->next->value)
		swap_a(*stacka);
}

void	mega_sort(t_stack *stacka, t_stack *stackb, long *temp_stack, int n_elements)
{
	int		chunk_size;

	bubble_sort(temp_stack, n_elements);
	generate_chunks(temp_stack, &stacka);
	chunk_size = chunk_get_size(n_elements);
	if (chunk_size == 0)
		sort_low(stacka, stackb, n_elements);
	else
		sort_high(stacka, stackb, chunk_size, 0);
}