/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:17 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/13 13:46:46 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;
	if (!stack || !stack->node)
		return;

	tmp = stack->node;
	stack->node = stack->node->next;
	tmp2 = stack->node;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	tmp2->next->next = NULL;
}
void	rotate_a(t_stack *stacka)
{
	rotate(stacka);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stackb)
{
	rotate(stackb);
	write(1,"rb\n", 3);
}

void	rotate_both(t_stack *stacka, t_stack *stackb)
{
	rotate(stacka);
	rotate(stackb);
	write(1, "rr\n", 3);
}