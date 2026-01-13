/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:20 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/13 13:47:20 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void reverse_rotate(t_stack *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;
	t_stack_node	*tmp3;
	if (!stack || !stack->node)
		return;

	tmp = stack->node;
	tmp2 = stack->node;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp3 = tmp2->next;
	tmp2->next = NULL;
	stack->node = tmp3;
	stack->node->next = tmp;
}

void	reverse_rotate_a(t_stack *stacka)
{
	reverse_rotate(stacka);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stackb)
{
	reverse_rotate(stackb);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack *stacka, t_stack *stackb)
{
	reverse_rotate(stacka);
	reverse_rotate(stackb);
	write(1, "rrr\n", 4);
}