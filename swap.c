/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:05:26 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/13 13:45:35 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack *stack)
{
	t_stack_node *tmp;
	t_stack_node *tmp2;
	t_stack_node *tmp3;
	if (!stack || stack_get_len(stack) < 2)
		return;
	tmp = stack->node;
	tmp2 = stack->node->next;
	tmp3 = stack->node->next->next;
	stack->node = tmp2;
	stack->node->next = tmp;
	stack->node->next->next = tmp3;
}

void	swap_a(t_stack *stacka)
{
	swap(stacka);
	write(1,"sa\n",3);
}

void	swap_b(t_stack *stackb)
{
	swap(stackb);
	write(1,"sb\n",3);
}

void	swap_both(t_stack *stacka, t_stack *stackb)
{
	swap(stacka);
	swap(stackb);
	write(1,"ss\n", 3);
}