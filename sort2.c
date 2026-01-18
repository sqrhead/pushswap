/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:25 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/18 17:41:55 by sqrhead          ###   ########.fr       */
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

t_stack_node	*node_get_closest(t_stack *stack, size_t index)
{
	t_stack_node	*node;
	t_stack_node	*lnode;
	int counter;

	counter = 0;
	if (!stack || !stack->node)
		return (NULL);
	node = stack->node;
	lnode = get_node(stack, stack_get_len(stack) - counter  - 1);
	while (lnode != node || node || lnode)
	{
		if (node->index == index)
			return (node);
		if (lnode->index == index)
			return (lnode);
		node = node->next;
		counter ++;
		lnode = get_node(stack, stack_get_len(stack) - counter - 1);
	}
	return (NULL);
}


void sort_high(t_stack *sa, t_stack *sb, int chunksize)
{
    int	i = 0;

    while (stack_get_len(sa) > 0)
    {
        if (sa->node->index <= (size_t)i)
        {
            push_b(sa, sb);
            // Optimization: If it's in the lower half of the range,
            // rotate it to the bottom of B to keep B somewhat sorted.
			if (stack_get_len(sb) > 1)
            	rotate_b(sb);
            i++;
        }
        else if (sa->node->index <= (size_t)(i + chunksize))
        {
            push_b(sa, sb);
            i++;
        }
        else
        {
            // Find the most efficient way to get a number from the range to the top
            // Usually, a simple rotation works here, but a "find_closest" logic
            // is even better for the move count.
            rotate_a(sa);
        }
    }

    // Phase 2: Push from B back to A
    // We always look for the largest remaining number to keep A sorted.
    while (stack_get_len(sb) > 0)
    {
        int target = stack_get_len(sb) - 1;
        int pos = get_index(sb, target);
        int size = stack_get_len(sb);

        // Bring the target (max) to the top of B
        if (pos <= size / 2)
        {
            while ((int)sb->node->index != target)
                rotate_b(sb);
        }
        else
        {
            while ((int)sb->node->index != target)
                reverse_rotate_b(sb);
        }
        push_a(sa, sb);
    }
}