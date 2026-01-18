/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:25 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/18 19:56:44 by sqrhead          ###   ########.fr       */
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

void	push_to_b(t_stack *sa, t_stack *sb, int chunksize)
{
	int	i;

	i = 0;
	while (stack_get_len(sa) > 0)
	{
		if (sa->node->index <= (size_t)i)
		{
			push_b(sa, sb);
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
			rotate_a(sa);
	}
}

void	sort_high(t_stack *sa, t_stack *sb, int chunksize)
{
	int	target;
	int	pos;
	int	size;

	push_to_b(sa, sb, chunksize);
	while (stack_get_len(sb) > 0)
	{
		target = stack_get_len(sb) - 1;
		pos = get_index(sb, target);
		size = stack_get_len(sb);
		if (pos <= size / 2)
			while ((int)sb->node->index != target)
				rotate_b(sb);
		else
			while ((int)sb->node->index != target)
				reverse_rotate_b(sb);
		push_a(sa, sb);
	}
}
