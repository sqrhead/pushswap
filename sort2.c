/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:25 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/16 12:08:39 by fshelna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_low(t_stack *stacka, t_stack *stackb, int n_elements)
{
	if (n_elements <= 3)
			sort_three(&stacka);
	else
			sort_five(&stacka, &stackb);
}

int	find_in_chunk_position(t_stack *stack, t_stack_node *node)
{
	t_stack_node	*tmp;
	int				index;

	if (!stack || !stack->node || !node)
		return (-1);
	tmp = stack->node;
	index = 0;
	while (tmp)
	{
		if (tmp == node)
			return (index);
		index ++;
		tmp = tmp->next;
	}
	return (-1);
}

t_stack_node	*find_node_by_nchunk(t_stack *stack, int chunk_index)
{
	t_stack_node *node;

	if (!stack || !stack->node)
		return (NULL);

	node = stack->node;
	while (node)
	{
		if (node->chunk_n == (size_t)chunk_index)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	sort_high(t_stack *stacka, t_stack *stackb, int chunk_size, int chunk_index)
{
	int	lenb;
	int pos;

	if (stack_is_sorted(stacka))
		return;
	while (chunk_index  < stack_get_len(stacka) / chunk_size)
	{
		while (chunk_contain(chunk_index, stacka) == 0)
		{
			while (stacka->node->chunk_n != (size_t)chunk_index)
			{
				pos = find_in_chunk_position(stacka,find_node_by_nchunk(stacka, chunk_index));
				if (pos < stack_get_len(stacka) / 2)
					rotate_a(stacka);
				else
					reverse_rotate_a(stacka);
			}
			push_b(stacka, stackb);
		}
		chunk_index ++;
	}
	lenb = stack_get_len(stackb);
	while (lenb > 0)
	{
		while (stackb->node->index != (size_t)(lenb - 1))
		{
			if (stackb->node->next && stackb->node->next->index == (size_t)(lenb - 1))
			{
				swap_b(stackb);
				continue ;
			}
			if (get_index(stackb, lenb -1) < (size_t)(lenb / 2))
				rotate_b(stackb);
			else
				reverse_rotate_b(stackb);
		}
		push_a(stacka, stackb);
		lenb = stack_get_len(stackb);
	}
}