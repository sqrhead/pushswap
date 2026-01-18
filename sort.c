/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:23 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/18 17:40:35 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(long *tab, int len)
{
	int		i;
	int		j;
	int		swapped;
	long	tmp;

	i = 0;
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
			j++;
		}
		i++;
		if (swapped == 1)
			break ;
	}
}

void	sort_three(t_stack **stack)
{
	int	n1;
	int	n2;
	int	n3;

	if (stack_get_len(*stack) == 2
		&& (*stack)->node->index > (*stack)->node->next->index)
		return (swap_a(*stack));
	if (stack_get_len(*stack) != 3)
		return ;
	n1 = (*stack)->node->index;
	n2 = (*stack)->node->next->index;
	n3 = (*stack)->node->next->next->index;
	if (n1 > n2 && n1 > n3)
		rotate_a(*stack);
	else if (n2 > n1 && n2 > n3)
		reverse_rotate_a(*stack);
	n1 = (*stack)->node->index;
	n2 = (*stack)->node->next->index;
	if (n1 > n2)
		swap_a(*stack);
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
	tmp = get_node(*stacka, (size_t)pos);
	len = stack_get_len(*stacka);
	rottotarget(stacka, tmp, pos, len);
	push_b(*stacka, *stackb);
	pos = get_smallest(*stacka);
	tmp = get_node(*stacka, (size_t)pos);
	len = stack_get_len(*stacka);
	rottotarget(stacka, tmp, pos, len);
	push_b(*stacka, *stackb);
	sort_three(stacka);
	push_a(*stacka, *stackb);
	push_a(*stacka, *stackb);
	if ((*stacka)->node->value > (*stacka)->node->next->value)
		swap_a(*stacka);
}

void	mega_sort(t_stack *sa, t_stack *sb, long *ts, int nele)
{
	int		chunk_size;

	bubble_sort(ts, nele);
	generate_chunks(ts, &sa);
	chunk_size = chunk_get_size(nele);
	if (chunk_size == 0)
		sort_low(sa, sb, nele);
	else
		sort_high(sa, sb, chunk_size);
}
