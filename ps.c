/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:05:26 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/09 12:23:57 by fshelna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	swap_a(t_stack *stacka)
{
	t_stack_node *tmp;
	t_stack_node *tmp2;
	t_stack_node *tmp3;
	if (!stacka || stack_get_len(stacka) < 2)
		return;
	tmp = stacka->node;
	tmp2 = stacka->node->next;
	tmp3 = stacka->node->next->next;
	stacka->node = tmp2;
	stacka->node->next = tmp;
	stacka->node->next->next = tmp3;

	write(1,"sa\n",3);
}

void	swap_b(t_stack *stackb)
{
	t_stack_node *tmp;
	t_stack_node *tmp2;
	t_stack_node *tmp3;
	if (!stackb || stack_get_len(stackb) < 2)
		return;
	tmp = stackb->node;
	tmp2 = stackb->node->next;
	tmp3 = stackb->node->next->next;
	stackb->node = tmp2;
	stackb->node->next = tmp;
	stackb->node->next->next = tmp3;
	write(1,"sb\n",3);
}

void	swap_both(t_stack *stacka, t_stack *stackb)
{
	swap_a(stacka);
	swap_b(stackb);
	write(1,"ss\n", 3);
}

void	push_a(t_stack *stacka, t_stack *stackb)
{
	t_stack_node	*tmp;
	if (!stackb || !stacka)
		return;
	if (stack_get_len(stackb) < 1)
		return;
	tmp = stackb->node->next;
	stack_new_node(&stacka, stackb->node);
	stackb->node = tmp;
	write(1,"pb\n",3);
}

void	push_b(t_stack *stacka, t_stack *stackb)
{
	t_stack_node	*tmp;
	if (!stackb || !stacka)
		return;
	if (stack_get_len(stacka) < 1)
		return;
	tmp = stacka->node->next;
	stack_new_node(&stackb, stacka->node);
	stacka->node = tmp;
	write(1,"pb\n",3);
}